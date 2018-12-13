/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <vlytvyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:17:18 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/12/13 16:17:19 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizual.h"

t_coor	get_board_size(char *line)
{
	t_coor	size;
	int		padding;
	int		num;

	padding = 1;
	size.y = ft_atoi(line + 8);
	num = size.y;
	while (num /= 10)
		padding++;
	size.x = ft_atoi(line + 8 + padding);
	return (size);
}

t_piece	get_board(t_coor size)
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
