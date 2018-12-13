/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <vlytvyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:12:57 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/12/13 16:12:59 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "vizual.h"

static void		skip_top_comment(void)
{
	int		i;

	i = 0;
	while (i < 9)
	{
		skip_line();
		i++;
	}
}

static int		final(char **line)
{
	int		o_score;
	int		x_score;

	o_score = ft_atoi(*line + 10);
	ft_strdel(line);
	get_next_line(0, line);
	x_score = ft_atoi(*line + 10);
	ft_strdel(line);
	ft_printf("%t", B_MAGENTA);
	if (x_score == o_score)
		ft_printf("It's a draw game! ");
	else if (x_score < o_score)
		ft_printf("Player 1 (O) win! ");
	else if (x_score > o_score)
		ft_printf("Player 2 (X) win! ");
	ft_printf("Score: %tO = %d %tX = %d\n", B_BLUE, o_score, B_YELLOW, x_score);
	return (0);
}

static t_coor	first_read(int *first_time, char *line)
{
	t_coor	board_size;

	board_size.x = 0;
	board_size.y = 0;
	if (*first_time)
	{
		*first_time = 0;
		board_size = get_board_size(line);
	}
	return (board_size);
}

static void		check_opp_stop(char **line)
{
	if (*(*(line) + 1) == 'i')
	{
		skip_block(block_lines(line));
		skip_line();
		get_next_line(0, line);
	}
}

int				main(void)
{
	char	*line;
	t_coor	board_size;
	t_piece	board;
	int		first_time;

	first_time = 1;
	system("clear");
	skip_top_comment();
	while (get_next_line(0, &line) > 0)
	{
		if (*line == '=')
			return (final(&line));
		else
			system("clear");
		board_size = first_time ? first_read(&first_time, line) : board_size;
		check_opp_stop(&line);
		free(line);
		board = get_board(board_size);
		print_board(board);
		free_piece(board);
		get_next_line(0, &line);
		skip_block(block_lines(&line));
		skip_line();
		usleep(200000);
	}
}
