/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:09:20 by ffons-ti          #+#    #+#             */
/*   Updated: 2024/02/07 14:15:40 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minas.h"
#include "libft.h"

void	leaks(void)
{
	system("leaks -q minas");
}

int	count_lines(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		i++;
	}
	return (i);
}

int	main(int ac, char **av)
{
	t_map	r_map;

	check_arg(ac, av);
	if (ac == 2)
	{
		r_map.max_y = ft_nlines(av[1]);
		r_map.map = dunk(av[1], r_map.max_y);
		if (!validate(r_map))
			dmap_error(r_map.map, "Error\nMapa no rectangular\n");
		if (!val_char(r_map))
			dmap_error(r_map.map, "Error\nMapa con Carácter Inválido\n");
		r_map.max_x = ft_strlen(r_map.map[0]);
		r_map.num = map_num(r_map);
	}
	else
	{
		r_map.map = generate_map();
		r_map.max_y = count_lines(r_map.map);
		r_map.max_x = ft_strlen(r_map.map[0]);
		r_map.num = map_num(r_map);
	}
	start_game(&r_map);
}
