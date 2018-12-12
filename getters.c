/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <vlytvyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:21:15 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/12/12 17:21:16 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_piece			get_board(t_coor size)
{
	char		*line;
	char		**table;
	int			i;
	t_piece		p_table;

	i = 0;
	get_next_line(0, &line);
	ft_strdel(&line);
	table = (char**)malloc(sizeof(char*) * size.y);
	while (i < size.y)
	{
		get_next_line(0, &line);
		table[i] = ft_strdup(line + 4);
		ft_strdel(&line);
		i++;
	}
	p_table.form.cm = table;
	p_table.size = size;
	return (p_table);
}

static t_coor	get_block_size(void)
{
	char	*line;
	t_coor	size;
	int		padding;
	int		num;

	padding = 1;
	get_next_line(0, &line);
	size.y = ft_atoi(line + 6);
	num = size.y;
	while (num /= 10)
		padding++;
	size.x = ft_atoi(line + 6 + padding);
	ft_strdel(&line);
	return (size);
}

t_piece			get_block(void)
{
	char	*line;
	char	**block;
	int		i;
	t_piece	p_block;

	i = 0;
	p_block.size = get_block_size();
	block = (char**)malloc(sizeof(char*) * p_block.size.y);
	while (i < p_block.size.y)
	{
		get_next_line(0, &line);
		block[i] = ft_strdup(line);
		ft_strdel(&line);
		i++;
	}
	p_block.form.cm = block;
	return (p_block);
}

t_piece			crop_block(t_piece block, t_coor padding)
{
	char	**shape;
	t_piece	p_shape;
	t_coor	end_coor;
	int		y;
	int		x;

	end_coor = get_end_coor(block);
	p_shape.size.y = end_coor.y - padding.y + 1;
	p_shape.size.x = end_coor.x - padding.x + 1;
	shape = (char**)malloc(sizeof(char*) * p_shape.size.y);
	y = 0;
	while ((y + padding.y) <= end_coor.y)
	{
		x = 0;
		shape[y] = (char*)malloc(sizeof(char) * p_shape.size.x);
		while ((x + padding.x) <= end_coor.x)
		{
			shape[y][x] = block.form.cm[y + padding.y][x + padding.x];
			x++;
		}
		y++;
	}
	p_shape.form.cm = shape;
	return (p_shape);
}
