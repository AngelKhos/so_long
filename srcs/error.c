/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:17:07 by authomas          #+#    #+#             */
/*   Updated: 2025/04/07 14:10:53 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab && tab[i])
	{
		if (tab[i])
		{
			free(tab[i++]);
			tab[i - 1] = NULL;
		}
	}
	if (tab)
		free(tab);
}

void	end_the_game(t_data *data, int move)
{
	ft_printf("You win!!!!\nYour final move count : %d\n", move);
	ft_laundry(data);
}

static void	img_destroy(t_data *data)
{
	if (data->mlx)
	{
		if (data->img.exit)
			mlx_destroy_image(data->mlx, data->img.exit);
		if (data->img.teto_img)
			mlx_destroy_image(data->mlx, data->img.teto_img);
		if (data->img.wall)
			mlx_destroy_image(data->mlx, data->img.wall);
		if (data->img.floor)
			mlx_destroy_image(data->mlx, data->img.floor);
		if (data->img.item)
			mlx_destroy_image(data->mlx, data->img.item);
	}
}

int	ft_laundry(t_data *data)
{
	free_tab(data->map.map);
	img_destroy(data);
	if (data->mlx)
	{
		if (data->mlx_win)
			mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(0);
	return (0);
}
