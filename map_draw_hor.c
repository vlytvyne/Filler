/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw_hor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <vlytvyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:32:44 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/12/12 17:32:45 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	set_left_values(int **map, int x, int y)
{
	while (x > 0)
	{
		map[y][x - 1] = map[y][x] + 1;
		x--;
	}
}

static void	set_right_values(int **map, int x, int y, int size_x)
{
	while (x < size_x - 1)
	{
		if (map[y][x + 1] != EN_CHAR)
			map[y][x + 1] = map[y][x] + 1;
		x++;
	}
}

void		map_draw_horizontal(int **map, t_piece t)
{
	int y;
	int x;

	y = 0;
	while (y < t.size.y)
	{
		x = 0;
		while (x < t.size.x)
		{
			if (map[y][x] == EN_CHAR)
			{
				set_left_values(map, x, y);
				set_right_values(map, x, y, t.size.x);
				break ;
			}
			x++;
		}
		y++;
	}
}
