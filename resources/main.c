/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:53:29 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/29 16:53:31 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

char    get_my_char()
{
    char    *line;

    get_next_line(0, &line);
    if (ft_atoi(line + 10) == 1)
        return ('x');
    else
        return ('o');
}

t_coor  get_size()
{
    char	*line;
    t_coor	size;
    int		padding;
    int		num;

	padding = 1;
	if (get_next_line(0, &line) <= 0)
		return (size);
	size.y = ft_atoi(line + 8);
	num = size.y;
    while (num /= 10)
		padding++;
	size.x = ft_atoi(line + 8 + padding);
    ft_strdel(&line);
    return (size);
}

char    **get_table(t_coor size)
{
    char    *line;
    char    **table;
    int     i;
	static int	fisrt_call = 1;

	if (fisrt_call)
		fisrt_call = 0;
	else
	{
		GNL()
	}
    i = 0;
	GNL();
    table = (char**)malloc(sizeof(char*) * size.y);
    while (i < size.y)
    {
        GNL(table[i] = ft_strdup(line + 4);)
        i++;
    }
    return (table);
}

int     **get_map(char **table)
{

}

int     main(void)
{
    char    my_char;
	t_coor	size;
    char    **table;

    my_char = get_my_char();
	size = get_size();
    table = get_table(size);
    int i = 0;
    while (i < size.y)
    {
        ft_putstr_fd(table[i], 2);
        ft_putchar_fd('\n', 2);
        i++;
    }
    ft_putstr("12 14\n");
}