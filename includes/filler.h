/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <vlytvyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:18:46 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/29 17:18:48 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include "printf.h"
# include "get_next_line.h"

# define MY_CHAR -3
# define EN_CHAR 0
# define EMPTY -1

typedef	union			u_map
{
	int					**im;
	char				**cm;
}						t_map;

typedef struct			s_coor
{
	int					x;
	int					y;
}						t_coor;

typedef struct			s_piece
{
	t_coor				size;
	t_map				form;
}						t_piece;

typedef struct			s_list_coor
{
	struct s_list_coor	*next;
	int					sum;
	t_coor				coor;
}						t_lc;

void					tlc_add_end(t_lc *head, t_lc *new);
t_lc					*create_lc(int x, int y, int sum);
void					free_piece(t_piece piece);
t_piece					get_board(t_coor size);
t_piece					get_block();
t_piece					crop_block(t_piece block, t_coor padding);
t_piece					get_map(t_piece t, char my_char);
void					map_draw_horizontal(int **map, t_piece t);
void					map_draw_vertical(int **map, t_piece t);
t_lc					*run_algorithm(t_piece map, t_piece shape);
void					send_answer(t_lc *list, t_coor padding);
t_coor					get_end_coor(t_piece block);
t_coor					get_padding(t_piece block);

#endif
