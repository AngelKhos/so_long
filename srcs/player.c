/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:31:01 by authomas          #+#    #+#             */
/*   Updated: 2025/03/20 18:29:00 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int get_player_pos_x(char **map)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (map[x])
	{
		y = 0;
		while(map[x][y])
		{
			if (map[x][y] == 'P')
				return (x);
			y++;
		}
		x++;
	}
	return(0);
}

int get_player_pos_y(char **map)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (map[x])
	{
		y = 0;
		while(map[x][y])
		{
			if (map[x][y] == 'P')
				return (y);
			y++;
		}
		x++;
	}
	return(0);
}
