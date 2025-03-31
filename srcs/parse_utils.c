/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:38:46 by authomas          #+#    #+#             */
/*   Updated: 2025/03/30 17:56:34 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void get_teto_pos(char **map, t_data *data)
{
	int x;
	int y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while(map[y][x])
		{
			if (map[y][x] == 'P')
			{
				data->teto.pos_x = x;
				data->teto.pos_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
	return ;
}

int check_map_elem(char *map, t_data *data)
{
	int i;
	int p;
	int e;
	
	p = 0;
	e = 0;
	i = 0;
	while (map[i])
	{
		if (map[i] == 'P')
			p++;
		if (map[i] == 'E')
			e++;
		if (map[i] == 'C')
			data->coin_count++;
		i++;
	}
	if (p != 1 || data->coin_count < 1 || e != 1 )
		return (0);
	return (1);
}

void flood_fill(char **map, int x, int y)
{
	map[y][x] = 'V';
	
	if (map[y][x + 1] != 'V' && map[y][x + 1] != '1')
		flood_fill(map, x + 1, y);
	if (map[y][x - 1] != 'V' && map[y][x - 1] != '1')
		flood_fill(map, x - 1, y);
	if (map[y + 1][x] != 'V' && map[y + 1][x] != '1')
		flood_fill(map, x, y + 1);
	if (map[y - 1][x] != 'V' && map[y - 1][x] != '1')
		flood_fill(map, x, y - 1);
}

int valid_ff(char *map, t_data *data)
{
	char **map_check;
	int x;
	int y;
	
	map_check = ft_split(ft_strdup(map), '\n');
	get_teto_pos(map_check, data);
	flood_fill(map_check, data->teto.pos_x, data->teto.pos_y);
	y = 0;
	while (map_check[y])
	{
		x = 0;
		while (map_check[y][x])
		{
			if (map_check[y][x] == 'C' || map_check[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	data->map.x_max = x;
	data->map.y_max = y;
	return (1);
}
