/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 20:17:42 by authomas          #+#    #+#             */
/*   Updated: 2025/03/26 21:01:57 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void get_img(t_data *data)
{
	data->img->exit = mlx_xpm_file_to_image(data->mlx, "assets/exit.xpm",data->img->img_width, data->img->img_height);
	data->img->floor = mlx_xpm_file_to_image(data->mlx, "assets/floor.xpm",data->img->img_width, data->img->img_height);
	data->img->wall = mlx_xpm_file_to_image(data->mlx, "assets/wall.xpm",data->img->img_width, data->img->img_height);
	data->img->item = mlx_xpm_file_to_image(data->mlx, "assets/frog.xpm",data->img->img_width, data->img->img_height);
	data->img->player_img = mlx_xpm_file_to_image(data->mlx, "assets/player.xpm",data->img->img_width, data->img->img_height);
}

// void print_map(t_data *data)
// {
	
// }
