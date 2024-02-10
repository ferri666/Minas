/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minas.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:42:52 by ffons-ti          #+#    #+#             */
/*   Updated: 2024/02/07 14:04:56 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minas.h"
#include "libft.h"

int	is_this_a_bomb(char c)
{
	if (c == 'M')
		return (1);
	return (0);
}

short int	*mall(int max)
{
	short int	*ret;

	ret = ft_calloc (sizeof(short int), (max + 1));
	if (!ret)
		return (NULL);
	else
		return (ret);
}

short int	count_mines(t_map map, int x, int y)
{
	short int	total;

	total = 0;
	total += is_this_a_bomb(map.map[y][x]);
	if (x != 0)
	{
		total += is_this_a_bomb(map.map[y][x - 1]);
		if (y != 0)
			total += is_this_a_bomb(map.map[y - 1][x - 1]);
		if (y != map.max_y - 1)
			total += is_this_a_bomb(map.map[y + 1][x - 1]);
	}
	if (x != map.max_x - 1)
	{
		total += is_this_a_bomb(map.map[y][x + 1]);
		if (y != 0)
			total += is_this_a_bomb(map.map[y - 1][x + 1]);
		if (y != map.max_y - 1)
			total += is_this_a_bomb(map.map[y + 1][x + 1]);
	}
	if (y != 0)
		total += is_this_a_bomb(map.map[y - 1][x]);
	if (y != map.max_y - 1)
		total += is_this_a_bomb(map.map[y + 1][x]);
	return (total);
}

short int	**map_num(t_map map_t)
{
	char		**map;
	short int	**ret;
	int			i;
	int			j;

	j = 0;
	map = map_t.map;
	ret = ft_calloc(sizeof(short int *), (map_t.max_y + 1));
	if (!ret)
		return (NULL);
	while (j < map_t.max_y)
	{
		ret[j] = mall(map_t.max_x);
		if (!ret[j])
			return (NULL);
		i = 0;
		while (i < map_t.max_x)
		{
			ret[j][i] = count_mines(map_t, i, j);
			i++;
		}
		j++;
	}
	return (ret);
}
