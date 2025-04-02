/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 20:17:42 by authomas          #+#    #+#             */
/*   Updated: 2025/04/02 17:54:26 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	get_img(t_data *data)
{
	int	img_width;
	int	img_height;

	data->img.exit = mlx_xpm_file_to_image(data->mlx,
			"assets/exit.xpm", &img_width, &img_height);
	data->img.floor = mlx_xpm_file_to_image(data->mlx,
			"assets/floor.xpm", &img_width, &img_height);
	data->img.wall = mlx_xpm_file_to_image(data->mlx,
			"assets/wall.xpm", &img_width, &img_height);
	data->img.item = mlx_xpm_file_to_image(data->mlx,
			"assets/frog.xpm", &img_width, &img_height);
	data->img.teto_img = mlx_xpm_file_to_image(data->mlx,
			"assets/teto.xpm", &img_width, &img_height);
	data->img.img_width = img_width;
	data->img.img_height = img_height;
}

void	update_teto(t_data *data, int x, int y)
{
	static int	move = 1;

	ft_printf("%d steps made :D\n", move++);
	if (data->map.map[y][x] == 'C')
		data->coins++;
	data->map.map[data->teto.pos_y][data->teto.pos_x] = '0';
	data->map.map[data->map.exit_pos_y][data->map.exit_pos_x] = 'E';
	data->teto.pos_x = x;
	data->teto.pos_y = y;
	data->map.map[data->teto.pos_y][data->teto.pos_x] = 'P';
	if (data->coins == data->coin_count
		&& (data->teto.pos_y == data->map.exit_pos_y)
		&& (data->teto.pos_x == data->map.exit_pos_x))
		end_the_game(data, move);
}

void	print_map_loop(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			print_map(data, x, y);
			x++;
		}
		y++;
	}
}

void	print_map(t_data *data, int x, int y)
{
	if (data->map.map[y][x] == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img.wall, x * 32, y * 32);
	else if (data->map.map[y][x] == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img.floor, x * 32, y * 32);
	else if (data->map.map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img.item, x * 32, y * 32);
	else if (data->map.map[y][x] == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img.floor, x * 32, y * 32);
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img.teto_img, x * 32, y * 32);
	}
	else if (data->map.map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img.exit, x * 32, y * 32);
}
