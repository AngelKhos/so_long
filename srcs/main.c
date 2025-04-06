/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:59:16 by authomas          #+#    #+#             */
/*   Updated: 2025/04/06 14:55:11 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	data_init(t_data *data)
{
	ft_memset(data, 0, sizeof(t_data));
}

void	move_teto(int keycode, t_data *data)
{
	if (keycode == KEY_W
		&& data->map.map[data->teto.pos_y - 1][data->teto.pos_x] != '1')
	{
		update_teto(data, data->teto.pos_x, data->teto.pos_y - 1);
		print_map_loop(data);
	}
	else if (keycode == KEY_A
		&& data->map.map[data->teto.pos_y][data->teto.pos_x - 1] != '1')
	{
		update_teto(data, data->teto.pos_x - 1, data->teto.pos_y);
		print_map_loop(data);
	}
	else if (keycode == KEY_S
		&& data->map.map[data->teto.pos_y + 1][data->teto.pos_x] != '1')
	{
		update_teto(data, data->teto.pos_x, data->teto.pos_y + 1);
		print_map_loop(data);
	}
	else if (keycode == KEY_D
		&& data->map.map[data->teto.pos_y][data->teto.pos_x + 1] != '1')
	{
		update_teto(data, data->teto.pos_x + 1, data->teto.pos_y);
		print_map_loop(data);
	}
}

int	key_pressed(int keycode, t_data *data)
{
	if (keycode == 65307)
		ft_laundry(data);
	move_teto(keycode, data);
	return (0);
}

void	game(t_data *data)
{
	data->mlx = mlx_init();
	if (!(data->mlx))
	{
		printf("Error\nSo_long: mlx error\n");
		ft_laundry(data);
		return ;
	}
	data->mlx_win = mlx_new_window(data->mlx, data->map.x_max * 32,
			data->map.y_max * 32, "so_long");
	if (!data->mlx_win)
	{
		printf("Error\nSo_long: mlx error\n");
		ft_laundry(data);
		return ;
	}
	get_img(data);
	print_map_loop(data);
	mlx_key_hook(data->mlx_win, key_pressed, data);
	mlx_hook(data->mlx_win, 17, (1L << 0), ft_laundry, data);
	mlx_loop(data->mlx);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		ft_printf("Error\nSo_long: wrong number of arguments\n");
		return (1);
	}
	data_init(&data);
	if (!map_checking(av[1], &data))
		return (1);
	game(&data);
	return (0);
}
