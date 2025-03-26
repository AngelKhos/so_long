/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:59:16 by authomas          #+#    #+#             */
/*   Updated: 2025/03/26 20:56:16 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void data_init(t_data *data)
{
	ft_memset(data, 0, sizeof(t_data));
}

void game(t_data *data)
{
	void *img;
	int img_width;
	int img_height;
	
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 32, 32, "UwU");
	get_img(data);
	img = mlx_xpm_file_to_image(data->mlx, "assets/floor.xpm",&img_width, &img_height);
	mlx_put_image_to_window(data->mlx, data->mlx_win, img, 0, 0);
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