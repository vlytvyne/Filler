/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <vlytvyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:16:06 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/12/13 16:16:07 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizual.h"

void		skip_line(void)
{
	char *line;

	get_next_line(0, &line);
	ft_strdel(&line);
}

void		print_board(t_piece board)
{
	int x;
	int y;

	y = 0;
	while (y < board.size.y)
	{
		x = 0;
		while (x < board.size.x)
		{
			if (board.form.cm[y][x] == 'O')
				ft_printf("%t", B_BLUE);
			else if (board.form.cm[y][x] == 'X')
				ft_printf("%t", B_YELLOW);
			else if (board.form.cm[y][x] == 'o')
				ft_printf("%t", BLUE);
			else if (board.form.cm[y][x] == 'x')
				ft_printf("%t", YELLOW);
			ft_printf("%c", board.form.cm[y][x]);
			ft_printf("%t", EOC);
			x++;
		}
		ft_printf("\n");
		y++;
	}
	ft_printf("%t", EOC);
}

void		free_piece(t_piece piece)
{
	int y;

	y = 0;
	while (y < piece.size.y)
	{
		free(piece.form.cm[y]);
		y++;
	}
	free(piece.form.cm);
}

int			block_lines(char **line)
{
	int		y;

	y = ft_atoi(*line + 6);
	ft_strdel(line);
	return (y);
}

void		skip_block(int num_lines)
{
	char	*line;
	int		i;

	i = 0;
	while (i < num_lines)
	{
		get_next_line(0, &line);
		ft_strdel(&line);
		i++;
	}
}
