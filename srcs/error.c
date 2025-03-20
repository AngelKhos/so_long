/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:17:07 by authomas          #+#    #+#             */
/*   Updated: 2025/03/15 16:17:43 by authomas         ###   ########lyon.fr   */
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