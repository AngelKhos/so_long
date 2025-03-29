/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:59:16 by authomas          #+#    #+#             */
/*   Updated: 2025/03/29 16:56:18 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void data_init(t_data *data)
{
	ft_memset(data, 0, sizeof(t_data));
}

void game(t_data *data)
{	
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 800, 600, "UwU");
	get_img(data);
	print_map(data);
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