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
    int     player_index;

    GNL(player_index = ft_atoi(line + 10);)
    return (player_index == 1 ? 'o' : 'x');
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

char    **get_board(t_coor size)
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

int     **get_map(char **table, t_coor size, char my_char)
{
    int		**map;
	int		x;
	int		y;

	y = 0;
	map = (int**)malloc(sizeof(int*) * size.y);
	while (y < size.y)
	{
		x = 0;
		map[y] = (int*)malloc(sizeof(int) * size.x);
		while (x < size.x)
		{
			if (table[y][x] == my_char || table[y][x] == my_char - 32)
				map[y][x] = EMPTY;
			else if (table[y][x] != '.')
				map[y][x] = EN_CHAR;
			else
				map[y][x] = EMPTY;
			x++;
		}
		y++;
	}

	int change = 0;
	y = 0;
	while (y < size.y)
	{
		x = 0;
		while (x < size.x)
		{
			if (map[y][x] != EMPTY)
			{
				if (x + 1 < size.x && map[y][x + 1] == EMPTY)
				{
					map[y][x + 1] = map[y][x] + 1;
					change = 1;
				}
				if (x - 1 >= 0 && map[y][x - 1] == EMPTY)
				{
					map[y][x - 1] = map[y][x] + 1;
					change = 1;
				}
				if (change)
				{
					x = -1;
					change = 0;
				}
			}
			x++;
		}
		y++;
	}

	x = 0;
	while (x < size.x)
	{
		y = 0;
		while (y < size.y)
		{
			if (map[y][x] != EMPTY)
			{
				if (y + 1 < size.y && map[y + 1][x] == EMPTY)
				{
					map[y + 1][x] = map[y][x] + 1;
					change = 1;
				}
				if (y - 1 >= 0 && map[y - 1][x] == EMPTY)
				{
					map[y - 1][x] = map[y][x] + 1;
					change = 1;
				}
				if (change)
				{
					y = -1;
					change = 0;
				}
			}
			y++;
		}
		x++;
	}

	y = 0;
	while (y < size.y)
	{
		x = 0;
		while (x < size.x)
		{
			if (table[y][x] == my_char || table[y][x] == my_char - 32)
				map[y][x] = MY_CHAR;
			x++;
		}
		y++;
	}
	return (map);
}

void	print_map(int **map, t_coor size)
{
	int y = 0;
	int x;
	while (y < size.y)
	{
		x = 0;
		while (x < size.x)
		{
			ft_putnbr_fd(map[y][x], 2);
			x++;
		}
		ft_putchar_fd('\n', 2);
		y++;
	}
}

int     main(void)
{
    char    my_char;
	t_coor	size;
    char    **table;
    int		**map;

    my_char = get_my_char();
	size = get_size();
    table = get_board(size);
	map = get_map(table, size, my_char);
	print_map(map, size);
    ft_putstr("12 14\n");
}