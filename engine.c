/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <vlytvyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:35:36 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/12/12 17:35:38 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_lc	*fit_shape(t_piece map, t_piece shape, int m_x, int m_y)
{
	int		x;
	int		y;
	int		sum;
	int		blocks_covered;

	zero_vars(3, &blocks_covered, &y, &sum);
	while (y < shape.size.y)
	{
		x = 0;
		while (x < shape.size.x)
		{
			if (shape.form.cm[y][x] == '*')
			{
				if (map.form.im[y + m_y][x + m_x] == EN_CHAR)
					return (NULL);
				else if (map.form.im[y + m_y][x + m_x] == MY_CHAR)
					blocks_covered++;
				else
					sum += map.form.im[y + m_y][x + m_x];
			}
			x++;
		}
		y++;
	}
	return (blocks_covered != 1 ? NULL : create_lc(m_x, m_y, sum));
}

t_lc		*run_algorithm(t_piece map, t_piece shape)
{
	int		x;
	int		y;
	int		till_x;
	int		till_y;
	t_lc	*head;

	y = 0;
	till_x = map.size.x - shape.size.x;
	till_y = map.size.y - shape.size.y;
	head = NULL;
	while (y <= till_y)
	{
		x = 0;
		while (x <= till_x)
		{
			if (head == NULL)
				head = fit_shape(map, shape, x, y);
			else
				tlc_add_end(head, fit_shape(map, shape, x, y));
			x++;
		}
		y++;
	}
	return (head);
}

void		send_answer(t_lc *list, t_coor padding)
{
	int		min_sum;
	t_coor	answer;
	t_lc	*to_free;

	min_sum = INT_MAX;
	while (list)
	{
		if (list->sum < min_sum)
		{
			min_sum = list->sum;
			answer = list->coor;
		}
		to_free = list;
		list = list->next;
		free(to_free);
	}
	answer.y -= padding.y;
	answer.x -= padding.x;
	ft_printf("%d %d\n", answer.y, answer.x);
}
