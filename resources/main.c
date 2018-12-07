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

t_coor  get_board_size()
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

t_piece	get_board(t_coor size)
{
    char		*line;
    char		**table;
    int			i;
	static int	fisrt_call = 1;
	t_piece		p_table;

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
	p_table.form.cm = table;
	p_table.size = size;
    return (p_table);
}

t_coor	get_block_size()
{
	char	*line;
    t_coor	size;
    int		padding;
    int		num;

	padding = 1;
	GNL(
	size.y = ft_atoi(line + 6);
	num = size.y;
    while (num /= 10)
		padding++;
	size.x = ft_atoi(line + 6 + padding);)
    return (size);
}

t_piece	get_block()
{
	char	*line;
	char	**block;
	int		i;
	t_piece	p_block;

	i = 0;
	p_block.size = get_block_size();
	block = (char**)malloc(sizeof(char*) * (p_block.size.y + 1));
	while (i < p_block.size.y)
	{
		GNL(block[i] = ft_strdup(line);)
		i++;
	}
	block[i] = NULL;
	p_block.form.cm = block;
	return (p_block);
}

t_piece	get_map(t_piece t, char my_char)
{
    int		**map;
	int		x;
	int		y;
	t_piece	p_map;

	y = 0;
	map = (int**)malloc(sizeof(int*) * t.size.y);
	while (y < t.size.y)
	{
		x = 0;
		map[y] = (int*)malloc(sizeof(int) * t.size.x);
		while (x < t.size.x)
		{
			if (t.form.cm[y][x] == my_char || t.form.cm[y][x] == my_char - 32)
				map[y][x] = EMPTY;
			else if (t.form.cm[y][x] != '.')
				map[y][x] = EN_CHAR;
			else
				map[y][x] = EMPTY;
			x++;
		}
		y++;
	}

	int change = 0;
	y = 0;
	while (y < t.size.y)
	{
		x = 0;
		while (x < t.size.x)
		{
			if (map[y][x] != EMPTY)
			{
				if (x + 1 < t.size.x && map[y][x + 1] == EMPTY)
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
	while (x < t.size.x)
	{
		y = 0;
		while (y < t.size.y)
		{
			if (map[y][x] != EMPTY)
			{
				if (y + 1 < t.size.y && map[y + 1][x] == EMPTY)
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
	while (y < t.size.y)
	{
		x = 0;
		while (x < t.size.x)
		{
			if (t.form.cm[y][x] == my_char || t.form.cm[y][x] == my_char - 32)
				map[y][x] = MY_CHAR;
			x++;
		}
		y++;
	}

	p_map.form.im = map;
	p_map.size = t.size;
	return (p_map);
}

void	print_form(t_piece piece, int is_char)
{
	int y = 0;
	int x;

	while (y < piece.size.y)
	{
		x = 0;
		while (x < piece.size.x)
		{
			if (is_char)
				ft_putchar_fd(piece.form.cm[y][x], 2);
			else
				ft_putnbr_fd(piece.form.im[y][x], 2);
			x++;
		}
		ft_putchar_fd('\n', 2);
		y++;
	}
}

int		get_y_padd(t_piece block)
{
	int		y;
	int		x;

	y = 0;
	while (y < block.size.y)
	{
		x = 0;
		while (x < block.size.x)
		{
			if (block.form.cm[y][x] == '*')
				return (y);
			x++;
		}
		y++;
	}
	return (y);
}

int		get_x_padd(t_piece block)
{
	int		y;
	int		x;

	x = 0;
	while (x < block.size.x)
	{
		y = 0;
		while (y < block.size.y)
		{
			if (block.form.cm[y][x] == '*')
				return (x);
			y++;
		}
		x++;
	}
	return (x);
}

t_coor	get_padding(t_piece block)
{
	t_coor	padding;

	padding.y = get_y_padd(block);
	padding.x = get_x_padd(block);
	return (padding);
}

int     main(void)
{
    char    my_char;
	t_coor	size;
	t_coor	padding;
    t_piece	table;
    t_piece	block;
	t_piece	map;

    my_char = get_my_char();
	size = get_board_size();
    table = get_board(size);
	map = get_map(table, my_char);
	block = get_block();
	print_form(map, 0);
	print_form(block, 1);
	padding = get_padding(block);
	ft_putnbr_fd(padding.x, 2);
	ft_putnbr_fd(padding.y, 2);
    // ft_putstr("12 14\n");
}