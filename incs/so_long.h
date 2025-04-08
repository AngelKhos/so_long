/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:21:16 by authomas          #+#    #+#             */
/*   Updated: 2025/04/07 14:10:21 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>

# ifndef KEY_W
#  define KEY_W 119
# endif

# ifndef KEY_A
#  define KEY_A 97
# endif

# ifndef KEY_S
#  define KEY_S 115
# endif

# ifndef KEY_D
#  define KEY_D 100
# endif

typedef struct s_img
{
	void	*wall;
	void	*floor;
	void	*item;
	void	*teto_img;
	void	*exit;
	int		img_height;
	int		img_width;
}	t_img;

typedef struct s_player
{
	int	pos_x;
	int	pos_y;
}	t_player;

typedef struct s_map
{
	char	**map;
	int		x_max;
	int		y_max;
	int		exit_pos_x;
	int		exit_pos_y;
}	t_map;

typedef struct s_data
{
	t_player	teto;
	int			coins;
	int			coin_count;
	t_map		map;
	void		*mlx;
	void		*mlx_win;
	t_img		img;
}	t_data;

int		file_checking(char *file_name);
int		check_lines(char *new_line, size_t len_line);
char	*get_map(int fd);
int		map_checking(char *av, t_data *data);
int		check_map_elem(char *map, t_data *data);
void	free_tab(char **tab);
int		is_map_closed(char *map);
void	get_teto_pos(char **map, t_data *data);
int		valid_ff(char *map, t_data *data);
void	flood_fill(char **map, int x, int y);
void	print_map_loop(t_data *data);
void	print_map(t_data *data, int x, int y);
void	get_img(t_data *data);
void	update_teto(t_data *data, int x, int y);
void	end_the_game(t_data *data, int move);
int		ft_laundry(t_data *data);

#endif