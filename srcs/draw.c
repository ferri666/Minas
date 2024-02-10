/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 13:02:04 by ffons-ti          #+#    #+#             */
/*   Updated: 2024/02/08 12:00:29 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minas.h"
#include "libft.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_a_square(t_data *img, int x, int y, int stat)
{
	int	i;
	int	j;

	i = 0;
	while (i < 40)
	{
		j = 0;
		while (j < 40)
		{
			if (stat == 0)
				my_mlx_pixel_put(img, x + i, y + j, 0xfcd380);
			if (stat == 1)
				my_mlx_pixel_put(img, x + i, y + j, 0xFF441C);
			if (stat == 2)
				my_mlx_pixel_put(img, x + i, y + j, 0x53FF1C);
			if (stat == 3)
				my_mlx_pixel_put(img, x + i, y + j, 0xAFFAFF);
			j++;
		}
		i++;
	}
}

void	draw_something(t_game *g)
{
	t_data	img;
	int		i;
	int		j;

	j = 0;
	img.img = mlx_new_image(g->mlx, g->width, g->height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	while (j < g->map->max_y)
	{
		i = 0;
		while (i < g->map->max_x)
		{
			draw_a_square(&img, 41 * i + 25, 41 * j + 15, g->stat[j][i]);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(g->mlx, g->win, img.img, 0, 0);
}

void	draw_numbers(t_game *g)
{
	int		i;
	int		j;
	int		num;

	j = 0;
	while (j < g->map->max_y)
	{
		i = 0;
		while (i < g->map->max_x)
		{
			num = g->map->num[j][i];
			mlx_put_image_to_window((*g).mlx, (*g).win, (*g).num[num],
				41 * i + 30, 41 * j + 15);
			i++;
		}
		j++;
	}
}
