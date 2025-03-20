/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:59:16 by authomas          #+#    #+#             */
/*   Updated: 2025/03/15 16:21:11 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	main(int ac, char **av)
{
    char *map;
	
	if (ac != 2)
		return (1);
	map = map_checking(av[1]);
	ft_printf("%s\n", map);
	free(map);
	return (0);
}