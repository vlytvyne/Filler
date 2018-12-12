/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <vlytvyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:06:02 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/12/12 17:06:04 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_coor	get_board_size(char **line)
{
	t_coor	size;
	int		padding;
	int		num;

	padding = 1;
	size.y = ft_atoi(*line + 8);
	num = size.y;
	while (num /= 10)
		padding++;
	size.x = ft_atoi(*line + 8 + padding);
	ft_strdel(line);
	return (size);
}

static char		get_my_char(void)
{
	char	*line;
	int		player_index;

	get_next_line(0, &line);
	player_index = ft_atoi(line + 10);
	ft_strdel(&line);
	return (player_index == 1 ? 'o' : 'x');
}

static void		fire(char my_char, t_coor board_size)
{
	t_coor	padding;
	t_piece	board;
	t_piece	block;
	t_piece	map;
	t_piece shape;

	board = get_board(board_size);
	map = get_map(board, my_char);
	free_piece(board);
	block = get_block();
	padding = get_padding(block);
	shape = crop_block(block, padding);
	free_piece(block);
	send_answer(run_algorithm(map, shape), padding);
	free_piece(shape);
	free_piece(map);
}

int				main(void)
{
	char	my_char;
	char	*line;
	t_coor	board_size;
	int		first_time;

	first_time = 1;
	my_char = get_my_char();
	while (get_next_line(0, &line) > 0)
	{
		if (first_time)
		{
			first_time = 0;
			board_size = get_board_size(&line);
		}
		else
			free(line);
		fire(my_char, board_size);
	}
}
