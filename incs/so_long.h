/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:21:16 by authomas          #+#    #+#             */
/*   Updated: 2025/03/26 20:54:44 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <math.h>

typedef struct s_data
{
    int ppos_x;
    int ppos_y;
    int coin_count;
    char **map;
    void *mlx;
    void *mlx_win;
    t_img *img;
} t_data;

typedef struct s_img
{
    void *wall;
    void *floor;
    void *item;
    void *player_img;
    void *exit;
    int img_height;
    int img_width;
} t_img;

int file_checking(char *file_name);
int check_lines(char *new_line, size_t len_line);
char *get_map(int fd);
int map_checking(char *av, t_data *data);
int check_map_elem(char *map, t_data *data);
void	free_tab(char **tab);
int is_map_closed(char *map);
int get_player_pos_y(char **map);
int get_player_pos_x(char **map);
int valid_ff(char *map, t_data *data);
void flood_fill(char **map, int x, int y);


#endif