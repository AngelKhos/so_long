/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:38:46 by authomas          #+#    #+#             */
/*   Updated: 2025/03/20 18:52:33 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int check_map_elem(char *map)
{
	int i;
	int p;
	int c;
	int e;
	
	p = 0;
	c = 0;
	e = 0;
	i = 0;
	while (map[i])
	{
		if (map[i] == 'P')
			p++;
		if (map[i] == 'E')
			e++;
		if (map[i] == 'C')
			c++;
		i++;
	}
	if (p != 1 || c < 1 || e != 1 )
		return (0);
	return (1);
}
void flood_fill(char **map, int x, int y)
{
	map[x][y] = 'V';
	
	if (map[x][y + 1] != 'V' && map[x][y + 1] != '1')
		flood_fill(map, x, y + 1);
	if (map[x][y - 1] != 'V' && map[x][y - 1] != '1')
		flood_fill(map, x, y - 1);
	if (map[x + 1][y] != 'V' && map[x + 1][y] != '1')
		flood_fill(map, x + 1, y);
	if (map[x - 1][y] != 'V' && map[x - 1][y] != '1')
		flood_fill(map, x - 1, y);
}

int valid_ff(char *map)
{
	char **map_check;
	int x;
	int y;

	map_check = ft_split(ft_strdup(map), '\n');
	x = get_player_pos_x(map_check);
	y = get_player_pos_y(map_check);
	flood_fill(map_check, x, y);
	x = 0;
	while (map_check[x])
	{
		y = 0;
		while (map_check[x][y])
		{
			if (map_check[x][y] == 'C' || map_check[x][y] == 'E')
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

