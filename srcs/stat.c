/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:35:36 by ffons-ti          #+#    #+#             */
/*   Updated: 2024/02/08 13:42:29 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minas.h"
#include "libft.h"

int	is_it_solved(t_game *g)
{
	int	i;
	int	j;

	j = 0;
	while (j < g->map->max_y)
	{
		i = 0;
		while (i < g->map->max_x)
		{
			if (g->map->map[j][i] == 'M' && g->stat[j][i] != 1)
				return (0);
			if (g->map->map[j][i] == '0' && g->stat[j][i] == 1)
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

void	reset_stat(t_game *g)
{
	int	i;
	int	j;

	j = 0;
	while (j < g->map->max_y)
	{
		i = 0;
		while (i < g->map->max_x)
		{
			g->stat[j][i] = 0;
			i++;
		}
		j++;
	}
}

void	change_stat(t_game *g, int x, int y, int button)
{
	if (x < 0 || x >= g->map->max_x)
		return ;
	if (y < 0 || y >= g->map->max_y)
		return ;
	if (button == 1)
	{
		if (g->stat[y][x] == 0)
			g->stat[y][x] = 1;
		else if (g->stat[y][x] == 1)
			g->stat[y][x] = 2;
		else if (g->stat[y][x] == 2)
			g->stat[y][x] = 0;
		else
			g->stat[y][x] = 1;
	}
	else
	{
		if (g->stat[y][x] == 0)
			g->stat[y][x] = 2;
		else if (g->stat[y][x] == 2)
			g->stat[y][x] = 3;
		else
			g->stat[y][x] = 0;
	}
	return ;
}

short	int	**init_stat(t_map *map)
{
	short int	**ret;
	int			i;
	int			j;

	j = 0;
	ret = ft_calloc(map->max_y + 1, sizeof(short int *));
	if (!ret)
		return (NULL);
	while (j < map->max_y)
	{
		ret[j] = mall(map->max_x);
		if (!ret[j])
		{
			ft_free_matrix((void **)ret);
			return (NULL);
		}
		i = 0;
		while (i < map->max_x)
		{
			ret[j][i] = 0;
			i++;
		}
		j++;
	}
	return (ret);
}
