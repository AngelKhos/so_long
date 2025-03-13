/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:20:13 by authomas          #+#    #+#             */
/*   Updated: 2025/03/13 18:02:46 by authomas         ###   ########lyon.fr   */
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
int check_lines(char *map_line, size_t len_line)
{
	int i;

	i = 0;
	if (ft_strlen(map_line) != len_line)
		return (0);
	while (map_line[i])
	{
		if (!ft_strchr("01PCE\n", map_line[i]))
			return (0);
		i++;
	}
	return (1);
}

void get_map(int fd)
{
	//char** map_line; on voit ca apres, deja j'essye d'afficher ma map sur le term
	char *map_line;
	size_t len_line;
	
	map_line = get_next_line(fd);
	len_line = ft_strlen(map_line);
	while (map_line)
	{
		if (check_lines(map_line, len_line))
		{
			ft_printf("%s\n", map_line);
			free(map_line);
		}
		map_line = get_next_line(fd);
		if (map_line[ft_strlen(map_line) - 1] != '\n')
		map_line[ft_strlen(map_line)] = '\n';
	}
}

int	main(int ac, char **av)
{
	int fd;

	fd = -1;
	if (ac != 2)
		return (1);
	if (file_checking(av[1]) == 0)
		fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nso_long");
		return (1);
	}
	get_map(fd);
	return (0);
}
