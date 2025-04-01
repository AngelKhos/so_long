/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 18:37:14 by authomas          #+#    #+#             */
/*   Updated: 2025/04/01 22:21:06 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void update_teto(t_data *data, int x, int y)
{
    static int move = 1;
    
    ft_printf("Oh! I can go there! %d\n", move++);
    if (data->map.map[y][x] == 'C')
        data->coins++;
    data->map.map[data->teto.pos_y][data->teto.pos_x] = '0';
    data->map.map[data->map.exit_pos_y][data->map.exit_pos_x] = 'E';
    data->teto.pos_x = x;
    data->teto.pos_y = y;
    data->map.map[data->teto.pos_y][data->teto.pos_x] = 'P';
}