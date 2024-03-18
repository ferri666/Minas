/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:48:45 by ffons-ti          #+#    #+#             */
/*   Updated: 2024/03/12 17:44:43 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minas.h"
#include "libft.h"

static int	key_quit(int keycode, t_game *game)
{
	if (keycode == 53 || keycode == 12)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit_game(game);
	}
	if (keycode == 49)
	{
		reset_stat(game);
		mlx_clear_window(game->mlx, game->win);
		draw_something(game);
		draw_numbers(game);
	}
	return (1);
}

static void	init_game(t_game *g, t_map *map)
{
	(*g).mlx = mlx_init();
	(*g).stat = init_stat(map);
	(*g).width = map->max_x * 42 + 40;
	(*g).height = map->max_y * 42 + 40;
	load_images(g);
	(*g).win = mlx_new_window((*g).mlx, (*g).width, (*g).height, "MINAS");
}

static int	mouse_hk(int button, int x, int y, t_game *g)
{
	if ((button == 1 || button == 2) && y > 10)
		change_stat(g, (x - 25) / 40, (y - 15) / 40, button);
	mlx_clear_window((*g).mlx, (*g).win);
	draw_something(g);
	draw_numbers(g);
	if (is_it_solved(g))
	{
		mlx_string_put((*g).mlx, (*g).win, g->width / 2 - 50,
			g->height - 25, 0x53FF1C, "YOU WIN!!!!");
		ft_printf("YOU WIN!!!!\n");
	}
	return (1);
}

static int	render(t_game *g)
{
	int	count;

	if (is_it_solved(g))
	{
		count = 1424242424;
		while (count)
			count--;
		mlx_destroy_window(g->mlx, g->win);
		exit_game(g);
	}
	return (1);
}

void	start_game(t_map *map)
{
	t_game	game;

	game.map = map;
	init_game(&game, game.map);
	draw_something(&game);
	draw_numbers(&game);
	mlx_hook(game.win, 17, 0, mlx_quit, &game);
	mlx_mouse_hook(game.win, mouse_hk, &game);
	mlx_key_hook(game.win, key_quit, &game);
	mlx_loop_hook(game.mlx, render, &game);
	mlx_loop(game.mlx);
}
