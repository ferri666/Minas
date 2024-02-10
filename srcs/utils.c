/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:26:56 by ffons-ti          #+#    #+#             */
/*   Updated: 2024/02/04 12:36:07 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minas.h"
#include "libft.h"

void	display_map(char **map, int n_lines)
{
	int	i;

	i = 0;
	while (i < n_lines)
	{
		ft_putendl_fd(map[i], 1);
		i++;
	}
}

void	display_num_map(short int **map, int n_lines, int max_x)
{
	int	i;
	int	j;

	i = 0;
	while (i < n_lines)
	{
		j = 0;
		while (j < max_x)
			ft_putnbr_fd(map[i][j++], 1);
		ft_putendl_fd("", 1);
		i++;
	}
}
