/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:20:13 by authomas          #+#    #+#             */
/*   Updated: 2025/03/24 23:57:54 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int file_checking(char *file_name)
{
	int size;

	size = ft_strlen(file_name);
	if (size <= 4)
		return (1);
	if(ft_strncmp(&file_name[size - 4], ".ber", size) == 0)
		return (0);
	return (1);
}
int check_lines(char *new_line, size_t len_line)
{
	int i;

	i = 0;
	if (ft_strlen(new_line) != len_line)
		return (0);
	while (new_line[i])
	{
		if (!ft_strchr("01PCE\n", new_line[i]))
			return (0);
		i++;
	}
	return (1);
}

char *get_map(int fd)
{
	char *new_line;
	char *map;
	size_t len_line;
	
	new_line = get_next_line(fd);
	map = NULL;
	len_line = ft_strlen(new_line);
	while (new_line)
	{
		if (check_lines(new_line, len_line))
			map = ft_join(map, new_line);
		else
		{
			ft_printf("Error\nSo_long: the map is not ok");
			free(map);
			return (NULL);
		}
		new_line = get_next_line(fd);
	}
	return (map);
}

int is_map_closed(char *map)
{
	char **big_map;
	int i;
	int line_count;

	i = 0;
	line_count = 0;
	big_map = ft_split(map, '\n');
	while (big_map[line_count])
		line_count++;
	while (big_map[0][i])
	{
		if (big_map[0][i] != '1'  || big_map[line_count - 1][i] != '1')
			return (free_tab(big_map), 0);
		i++;
	}
	i = 0;
	while (big_map[i])
	{
		if (big_map[i][0] != '1' || big_map[i][ft_strlen(big_map[i]) - 1] != '1')
			return (free_tab(big_map), 0);
		i++;
	}
	free_tab(big_map);
	return (1);
}

int map_checking(char *av, t_data *data)
{
	int fd;
	char *map;
	fd = -1;
	
	if (file_checking(av) == 0)
		fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nso_long");
		return (0);
	}
	map = get_map(fd);
	if (!map)
		return (0);
	data->map = ft_split(map, '\n');
	if (!check_map_elem(map, data) || !is_map_closed(map) || !valid_ff(map, data))
	{
		ft_printf("Error\nSo_long: the map is not ok");
		free(map);
		return (0);
	}
	free(map);
	return (1);
}
