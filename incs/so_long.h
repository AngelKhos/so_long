/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:21:16 by authomas          #+#    #+#             */
/*   Updated: 2025/03/20 18:50:49 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <math.h>

int file_checking(char *file_name);
int check_lines(char *new_line, size_t len_line);
char *get_map(int fd);
char *map_checking(char *av);
int check_map_elem(char *map);
void	free_tab(char **tab);
int is_map_closed(char *map);
int get_player_pos_y(char **map);
int get_player_pos_x(char **map);
int valid_ff(char *map);
void flood_fill(char **map, int x, int y);

typedef struct s_data
{
    int player;
	int coins;
	int entrance;
	int exit;
	int wall;
	int o;
	int i;
}   t_data;

#endif