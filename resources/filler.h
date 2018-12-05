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

typedef struct  s_coor
{
    int         x;
    int         y;
}               t_coor;

#endif
