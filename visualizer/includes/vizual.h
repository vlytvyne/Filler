/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vizual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <vlytvyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:17:54 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/12/13 16:17:56 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIZUAL_H
# define VIZUAL_H

# include "filler.h"

void		skip_line(void);
void		print_board(t_piece board);
void		free_piece(t_piece piece);
void		skip_block(int num_lines);
t_piece		get_board(t_coor size);
t_coor		get_board_size(char *line);
int			block_lines(char **line);

#endif
