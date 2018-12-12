/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <vlytvyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:30:51 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/12/12 17:30:52 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	init_map(int **map, t_piece t, char my_char)
{
	int		x;
	int		y;

	y = 0;
	while (y < t.size.y)
	{
		x = 0;
		map[y] = (int*)malloc(sizeof(int) * t.size.x);
		while (x < t.size.x)
		{
			if (t.form.cm[y][x] == my_char || t.form.cm[y][x] == my_char - 32)
				map[y][x] = EMPTY;
			else if (t.form.cm[y][x] != '.')
				map[y][x] = EN_CHAR;
			else
				map[y][x] = EMPTY;
			x++;
		}
		y++;
	}
}

static void	map_mark_my_char(int **map, t_piece t, char my_char)
{
	int x;
	int y;

	y = 0;
	while (y < t.size.y)
	{
		x = 0;
		while (x < t.size.x)
		{
			if (t.form.cm[y][x] == my_char || t.form.cm[y][x] == my_char - 32)
				map[y][x] = MY_CHAR;
			x++;
		}
		y++;
	}
}

t_piece		get_map(t_piece t, char my_char)
{
	int		**map;
	t_piece	p_map;

	map = (int**)malloc(sizeof(int*) * t.size.y);
	init_map(map, t, my_char);
	map_draw_horizontal(map, t);
	map_draw_vertical(map, t);
	map_mark_my_char(map, t, my_char);
	p_map.form.im = map;
	p_map.size = t.size;
	return (p_map);
}
