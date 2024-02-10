/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 13:52:47 by ffons-ti          #+#    #+#             */
/*   Updated: 2024/02/04 15:45:10 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minas.h"
#include "libft.h"

void	exit_game(t_game *g)
{
	ft_free_matrix((void **)(*g).map->map);
	ft_free_matrix((void **)(*g).map->num);
	ft_free_matrix((void **)(*g).stat);
	ft_printf("BYE-BYE!\n");
	exit (0);
}

int	mlx_quit(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit_game(game);
	return (0);
}
