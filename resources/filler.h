/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:18:46 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/29 17:18:48 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "libft.h"
#include "printf.h"
#include "get_next_line.h"

# define GNL(x) get_next_line(0, &line); x ft_strdel(&line);
# define MY_CHAR -3
# define EN_CHAR 0
# define EMPTY -1

typedef	union	u_map
{
	int			**im;
	char		**cm;
}				t_map;

typedef struct  s_coor
{
    int         x;
    int         y;
}               t_coor;

typedef struct	s_piece
{
	t_coor		size;
	t_map		form;
}				t_piece;


#endif
