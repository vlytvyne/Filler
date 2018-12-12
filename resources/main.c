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

t_coor  get_board_size(char **line)
{
    t_coor	size;
    int		padding;
    int		num;

	padding = 1;
	size.y = ft_atoi(*line + 8);
	num = size.y;
    while (num /= 10)
		padding++;
	size.x = ft_atoi(*line + 8 + padding);
    ft_strdel(line);
    return (size);
}

t_piece	get_board(t_coor size)
{
    char		*line;
    char		**table;
    int			i;
	static int	fisrt_call = 1;
	t_piece		p_table;

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
	block = (char**)malloc(sizeof(char*) * p_block.size.y);
	while (i < p_block.size.y)
	{
		GNL(block[i] = ft_strdup(line);)
		i++;
	}
	p_block.form.cm = block;
	return (p_block);
}

//totaly more than 25 lines

void	init_map(int **map, t_piece t, char my_char)
{
	int		x;
	int		y;

	y = 0;
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
}

void	set_left_values(int **map, int x, int y)
{
	while (x > 0)
	{
		map[y][x - 1] = map[y][x] + 1;
		x--;
	}
}

void	set_right_values(int **map, int x, int y, int size_x)
{
	while (x < size_x - 1)
	{
		if (map[y][x + 1] != EN_CHAR)
			map[y][x + 1] = map[y][x] + 1;
		x++;
	}
}

void	map_draw_horizontal(int **map, t_piece t)
{
	int y;
	int x;

	y = 0;
	while (y < t.size.y)
	{
		x = 0;
		while (x < t.size.x)
		{
			if (map[y][x] == EN_CHAR)
			{
				set_left_values(map, x, y);
				set_right_values(map, x, y, t.size.x);
				break ;
			}
			x++;
		}
		y++;
	}
}

void	set_under_values(int **map, int x, int y)
{
	while (y > 0)
	{
		map[y - 1][x] = map[y][x] + 1;
		y--;
	}
}

void	set_beneath_values(int **map, int x, int y, int size_y)
{
	while (y < size_y - 1)
	{
		if (map[y + 1][x] == EMPTY)
			map[y + 1][x] = map[y][x] + 1;
		y++;
	}
}

void	map_draw_vertical(int **map, t_piece t)
{
	int y;
	int x;

	x = 0;
	while (x < t.size.x)
	{
		y = 0;
		while (y < t.size.y)
		{
			if (map[y][x] != EMPTY)
			{
				set_under_values(map, x, y);
				set_beneath_values(map, x, y, t.size.y);
				break ;
			}
			y++;
		}
		x++;
	}
}

void	map_mark_my_char(int **map, t_piece t, char my_char)
{
	int x;
	int y;

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
}

t_piece	get_map(t_piece t, char my_char)
{
    int		**map;
	int		x;
	int		y;
	t_piece	p_map;

	map = (int**)malloc(sizeof(int*) * t.size.y);
	init_map(map, t, my_char);
	map_draw_horizontal(map, t);
	map_draw_vertical(map, t);
	map_mark_my_char(map, t, my_char);

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
				fprintf(stderr, "%c",piece.form.cm[y][x]);
			else
				fprintf(stderr, "%-3i",piece.form.im[y][x]);
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

int		get_end_x_coor(t_piece block)
{
	int		y;
	int		x;

	x = block.size.x - 1;
	while (x >= 0)
	{
		y = block.size.y - 1;
		while (y >= 0)
		{
			if (block.form.cm[y][x] == '*')
				return (x);
			y--;
		}
		x--;
	}
	return (x);
}

int		get_end_y_coor(t_piece block)
{
	int		y;
	int		x;

	y = block.size.y - 1;
	while (y >= 0)
	{
		x = block.size.x - 1;
		while (x >= 0)
		{
			if (block.form.cm[y][x] == '*')
				return (y);
			x--;
		}
		y--;
	}
	return (y);
}

t_coor	get_end_coor(t_piece block)
{
	t_coor	end_coor;

	end_coor.y = get_end_y_coor(block);
	end_coor.x = get_end_x_coor(block);
	return (end_coor);
}

t_piece	crop_block(t_piece block, t_coor padding)
{
	char	**shape;
	t_piece	p_shape;
	t_coor	end_coor;
	int		y;
	int		x;

	end_coor = get_end_coor(block);
	p_shape.size.y = end_coor.y - padding.y + 1;
	p_shape.size.x = end_coor.x - padding.x + 1;
	shape = (char**)malloc(sizeof(char*) * p_shape.size.y);
	y = 0;
	while ((y + padding.y) <= end_coor.y)
	{
		x = 0;
		shape[y] = (char*)malloc(sizeof(char) * p_shape.size.x);
		while ((x + padding.x) <= end_coor.x)
		{
			shape[y][x] = block.form.cm[y + padding.y][x + padding.x];
			x++;
		}
		y++;
	}
	p_shape.form.cm = shape;
	return (p_shape);
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

t_lc	*fit_shape(t_piece map, t_piece shape, int m_x, int m_y)
{
	int		x;
	int		y;
	int		sum;
	int		blocks_covered;

	zero_vars(3, &blocks_covered, &y, &sum);
	while (y < shape.size.y)
	{
		x = 0;
		while (x < shape.size.x)
		{
			if (shape.form.cm[y][x] == '*')
			{
				if (map.form.im[y + m_y][x + m_x] == EN_CHAR)
					return (NULL);
				else if (map.form.im[y + m_y][x + m_x] == MY_CHAR)
					blocks_covered++;
				else
					sum += map.form.im[y + m_y][x + m_x];
			}
			x++;
		}
		y++;
	}
	return (blocks_covered != 1 ? NULL : create_lc(m_x, m_y, sum));
}

void	tlc_add_end(t_lc *head, t_lc *new)
{
	if (head == NULL || new == NULL)
		return ;
	while (head->next)
		head = head->next;
	head->next = new;
}

t_lc	*run_algorithm(t_piece map, t_piece shape)
{
	int		x;
	int		y;
	int		till_x;
	int		till_y;
	t_lc	*head;

	y = 0;
	till_x = map.size.x - shape.size.x;
	till_y = map.size.y - shape.size.y;
	head = NULL;
	while (y <= till_y)
	{
		x = 0;
		while (x <= till_x)
		{
			if (head == NULL)
				head = fit_shape(map, shape, x, y);
			else
				tlc_add_end(head, fit_shape(map, shape, x, y));
			x++;
		}
		y++;
	}
	return (head);
}

void	send_answer(t_lc *list, t_coor padding)
{
	int		min_sum;
	t_coor	answer;
	t_lc	*to_free;

	min_sum = INT_MAX;
	while (list)
	{
		if (list->sum < min_sum)
		{
			min_sum = list->sum;
			answer = list->coor;
		}
		to_free = list;
		list = list->next;
		free(to_free);
	}
	answer.y -= padding.y;
	answer.x -= padding.x;
	ft_printf("%d %d\n", answer.y, answer.x);
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

void	fire(char my_char, t_coor board_size)
{
	t_coor	padding;
    t_piece	board;
    t_piece	block;
	t_piece	map;
	t_piece shape;

	board = get_board(board_size);
	map = get_map(board, my_char);
	free_piece(board);
	block = get_block();
	padding = get_padding(block);
	shape = crop_block(block, padding);
	free_piece(block);
	send_answer(run_algorithm(map, shape), padding);
	free_piece(shape);
	free_piece(map);
}

int     main(void)
{
    char    my_char;
	char	*line;
	t_coor	board_size;
	int		first_time;

	first_time = 1;
    my_char = get_my_char();
	while (get_next_line(0, &line) > 0)
	{
		if (first_time)
		{
			first_time = 0;
			board_size = get_board_size(&line);
		}
		else
			free(line);
		fire(my_char, board_size);
	}
	system("leaks vlytvyne.filler > result");
}