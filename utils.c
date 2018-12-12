/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <vlytvyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:13:46 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/12/12 17:13:47 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	tlc_add_end(t_lc *head, t_lc *new)
{
	if (head == NULL || new == NULL)
		return ;
	while (head->next)
		head = head->next;
	head->next = new;
}

t_lc	*create_lc(int x, int y, int sum)
{
	t_lc	*list;

	list = (t_lc*)malloc(sizeof(t_lc));
	list->next = NULL;
	list->coor.x = x;
	list->coor.y = y;
	list->sum = sum;
	return (list);
}

void	free_piece(t_piece piece)
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
