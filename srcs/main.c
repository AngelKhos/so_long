/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:59:16 by authomas          #+#    #+#             */
/*   Updated: 2025/03/30 19:18:44 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void data_init(t_data *data)
{
	ft_memset(data, 0, sizeof(t_data));
}
void move_teto(int keycode, t_data *data)
{
	if (keycode == 6 && data->map.map[data->teto.pos_y - 1][data->teto.pos_x] != '1')
		ft_printf("oh i can go there!");
	else if (keycode == 12 && data->map.map[data->teto.pos_y][data->teto.pos_x - 1] != '1')
		ft_printf("oh i can go there!");
	else if (keycode == 1 && data->map.map[data->teto.pos_y + 1][data->teto.pos_x] != '1')
		ft_printf("oh i can go there!");
	else if (keycode == 2 && data->map.map[data->teto.pos_y][data->teto.pos_x + 1] != '1')
		ft_printf("oh i can go there!");
	else
		ft_printf("nope");
}

int key_pressed(int keycode , t_data *data)
{
	static int move = 1;
	
	move_teto(keycode, data);
	ft_printf("UWU in terminal %d\n", move);
	move++;
	return (0);
}

void game(t_data *data)
{	
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, data->map.x_max * 32, data->map.y_max * 32, "UwU");
	get_img(data);
	print_map(data);
	mlx_key_hook(data->mlx_win, key_pressed, data);
	mlx_loop(data->mlx);
}

int	main(int ac, char **av)
{
	t_data data;
	
	if (ac != 2)
		return (1);
	data_init(&data);
	if (!map_checking(av[1], &data))
		return (1);
	game(&data);
	return (0);
}