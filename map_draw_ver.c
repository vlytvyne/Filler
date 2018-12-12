/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw_ver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <vlytvyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:32:49 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/12/12 17:32:50 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	set_under_values(int **map, int x, int y)
{
	while (y > 0)
	{
		map[y - 1][x] = map[y][x] + 1;
		y--;
	}
}

static void	set_beneath_values(int **map, int x, int y, int size_y)
{
	while (y < size_y - 1)
	{
		if (map[y + 1][x] == EMPTY)
			map[y + 1][x] = map[y][x] + 1;
		y++;
	}
}

void		map_draw_vertical(int **map, t_piece t)
{
	int y;
	int x;

	x = 0;
	while (x < t.size.x)
	{
		y = 0;
		while (y < t.size.y)
		{
			if (map[y][x] != EMPTY)
			{
				set_under_values(map, x, y);
				set_beneath_values(map, x, y, t.size.y);
				break ;
			}
			y++;
		}
		x++;
	}
}
