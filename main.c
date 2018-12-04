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



int     main(int argc, char **argv)
{
    char *buff;

    int fd = open("result", O_WRONLY);
    for (int i = 0; i < 21; i++)
    {
        get_next_line(0, &buff);
        ft_putstr_fd(buff, fd);
        ft_putchar_fd('\n', fd);
    }
    ft_putstr("12 14\n");
    for (int i = 0; i < 20; i++)
    {
        ft_putnbr_fd(get_next_line(0, &buff), fd);
        ft_putstr_fd(buff, fd);
        ft_putchar_fd('\n', fd);
    }
    ft_putstr("12 14\n");
    close(fd);
}