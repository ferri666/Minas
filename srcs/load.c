/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:17:01 by ffons-ti          #+#    #+#             */
/*   Updated: 2024/02/04 15:14:08 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minas.h"
#include "libft.h"

void	load_images(t_game *g)
{
	int		tilex;
	int		tiley;

	tilex = 30;
	tiley = 40;
	(*g).num[0] = mlx_xpm_file_to_image((*g).mlx, "img/0.xpm", &tilex, &tiley);
	(*g).num[1] = mlx_xpm_file_to_image((*g).mlx, "img/1.xpm", &tilex, &tiley);
	(*g).num[2] = mlx_xpm_file_to_image((*g).mlx, "img/2.xpm", &tilex, &tiley);
	(*g).num[3] = mlx_xpm_file_to_image((*g).mlx, "img/3.xpm", &tilex, &tiley);
	(*g).num[4] = mlx_xpm_file_to_image((*g).mlx, "img/4.xpm", &tilex, &tiley);
	(*g).num[5] = mlx_xpm_file_to_image((*g).mlx, "img/5.xpm", &tilex, &tiley);
	(*g).num[6] = mlx_xpm_file_to_image((*g).mlx, "img/6.xpm", &tilex, &tiley);
	(*g).num[7] = mlx_xpm_file_to_image((*g).mlx, "img/7.xpm", &tilex, &tiley);
	(*g).num[8] = mlx_xpm_file_to_image((*g).mlx, "img/8.xpm", &tilex, &tiley);
	(*g).num[9] = mlx_xpm_file_to_image((*g).mlx, "img/9.xpm", &tilex, &tiley);
}
