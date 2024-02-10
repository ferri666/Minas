/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:42:49 by ffons-ti          #+#    #+#             */
/*   Updated: 2024/02/07 14:10:12 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minas.h"
#include "libft.h"

char	**dunk(char *str, int n_lines)
{
	char	**map;
	char	*line;
	int		i;
	int		fd;

	fd = open (str, O_RDONLY);
	map = ft_calloc(n_lines + 1, sizeof(char *));
	if (!map)
		return (NULL);
	i = 0;
	while (i < n_lines)
	{
		line = get_next_line(fd);
		if (!line)
			dmap_error(map, "Error\nEmpty line or Memory problem\n");
		if (i == n_lines - 1)
			map[i] = ft_substr(line, 0, ft_strlen(line));
		else
			map[i] = ft_substr(line, 0, ft_strlen(line) - 1);
		i++;
		free(line);
	}
	close (fd);
	return (map);
}

int	validate(t_map t_map)
{
	char	**map;
	char	*line;
	int		n_lines;
	size_t	len;
	int		i;

	i = 0;
	map = t_map.map;
	n_lines = t_map.max_y;
	while (i < n_lines)
	{
		line = map[i];
		if (i == 0)
			len = ft_strlen(line);
		if (len != ft_strlen(line))
			return (0);
		i++;
	}
	return (1);
}

int	val_char(t_map t_map)
{
	int		i;
	size_t	j;
	size_t	len;
	char	**map;
	int		n_lines;

	map = t_map.map;
	n_lines = t_map.max_y;
	i = 0;
	len = ft_strlen(map[0]);
	while (i < n_lines)
	{
		j = 0;
		while (j < len)
		{
			if (map[i][j] != 'M' && map[i][j] != '0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	check_arg(int ac, char **av)
{
	int	fd;

	if (ac > 2)
	{
		ft_putstr_fd("Error\nNúmero de Argumentos Inválido\n", 2);
		exit (-1);
	}
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
		{
			ft_putstr_fd("Error\nMapa no encontrado\n", 2);
			exit (-1);
		}
		close(fd);
	}
}
