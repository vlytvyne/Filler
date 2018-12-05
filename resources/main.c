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
    if (ft_atoi(line) == 1)
        return ('x');
    else
        return ('o');
}

char    **get_table()
{
    char    *line;
    char    **table;
    int     lines_amount;
    int     i;

    i = 0;
    if (get_next_line(0, &line) <= 0)
        return (NULL);
    lines_amount = ft_atoi(line);
    ft_strdel(&line);
    get_next_line(0, &line);
    ft_strdel(&line);
    table = (char**)malloc(sizeof(char*) * lines_amount);
    while (i < lines_amount)
    {
        get_next_line(0, &line);
        table[i] = ft_strdup(line + 4);
        ft_strdel(&line);
        i++;
    }
    return (table);
}

int     main(void)
{
    char    my_char;
    char    **table;

    int fd = open("result", O_WRONLY);
    my_char = get_my_char();
    if ((table = get_table()) == NULL)
        exit(0);
    for (int i = 0; i < 15; i++)
    {
        ft_putstr_fd(table[i], fd);
        ft_putchar_fd('\n', fd);
    }
    ft_putstr("12 14\n");
    close(fd);


}