/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_end_coor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <vlytvyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:18:36 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/12/12 17:18:37 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	get_end_x_coor(t_piece block)
{
	int		y;
	int		x;

	x = block.size.x - 1;
	while (x >= 0)
	{
		y = block.size.y - 1;
		while (y >= 0)
		{
			if (block.form.cm[y][x] == '*')
				return (x);
			y--;
		}
		x--;
	}
	return (x);
}

static int	get_end_y_coor(t_piece block)
{
	int		y;
	int		x;

	y = block.size.y - 1;
	while (y >= 0)
	{
		x = block.size.x - 1;
		while (x >= 0)
		{
			if (block.form.cm[y][x] == '*')
				return (y);
			x--;
		}
		y--;
	}
	return (y);
}

t_coor		get_end_coor(t_piece block)
{
	t_coor	end_coor;

	end_coor.y = get_end_y_coor(block);
	end_coor.x = get_end_x_coor(block);
	return (end_coor);
}
