/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_padd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <vlytvyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:16:54 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/12/12 17:16:55 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	get_y_padd(t_piece block)
{
	int		y;
	int		x;

	y = 0;
	while (y < block.size.y)
	{
		x = 0;
		while (x < block.size.x)
		{
			if (block.form.cm[y][x] == '*')
				return (y);
			x++;
		}
		y++;
	}
	return (y);
}

static int	get_x_padd(t_piece block)
{
	int		y;
	int		x;

	x = 0;
	while (x < block.size.x)
	{
		y = 0;
		while (y < block.size.y)
		{
			if (block.form.cm[y][x] == '*')
				return (x);
			y++;
		}
		x++;
	}
	return (x);
}

t_coor		get_padding(t_piece block)
{
	t_coor	padding;

	padding.y = get_y_padd(block);
	padding.x = get_x_padd(block);
	return (padding);
}
