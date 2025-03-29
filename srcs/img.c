/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 20:17:42 by authomas          #+#    #+#             */
/*   Updated: 2025/03/29 17:07:32 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void get_img(t_data *data)
{
	data->img.exit = mlx_xpm_file_to_image(data->mlx, "assets/exit.xpm",&data->img.img_width, &data->img.img_height);
	data->img.floor = mlx_xpm_file_to_image(data->mlx, "assets/floor.xpm",&data->img.img_width, &data->img.img_height);
	data->img.wall = mlx_xpm_file_to_image(data->mlx, "assets/wall.xpm",&data->img.img_width, &data->img.img_height);
	data->img.item = mlx_xpm_file_to_image(data->mlx, "assets/frog.xpm",&data->img.img_width, &data->img.img_height);
	data->img.teto_img = mlx_xpm_file_to_image(data->mlx, "assets/player.xpm",&data->img.img_width, &data->img.img_height);
}

void print_map(t_data *data)
{
	int x;
	int y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.wall, x * 16, y * 16);
			else if (data->map[y][x] == '0')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.floor, x * 16, y * 16);
			else if (data->map[y][x] == 'C')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.item, x * 16, y * 16);
			else if (data->map[y][x] == 'P')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.floor, x * 16, y * 16);
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.teto_img, x * 16, y * 16);
			}
			else if (data->map[y][x] == 'E')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.exit, x * 16, y * 16);
			x++;
		}
		y++;
	}
}
