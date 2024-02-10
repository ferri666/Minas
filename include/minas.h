/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minas.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:40:17 by ffons-ti          #+#    #+#             */
/*   Updated: 2024/02/08 11:58:01 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINAS_H
# define MINAS_H
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <time.h>

typedef struct s_map
{
	short int	**num;
	char		**map;
	int			max_x;
	int			max_y;
}				t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*num[10];
	short int	**stat;
	int			width;
	int			height;
	t_map		*map;
}			t_game;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

/* validate.c */
void		check_arg(int ac, char **av);
int			val_char(t_map t_map);
char		**dunk(char *str, int n_lines);
int			validate(t_map t_map);

/* error.c*/
void		dmap_error(char	**map, char *str);

/* minas.c */
short int	**map_num(t_map map_t);
short int	*mall(int max);

/* utils.c */
void		display_map(char **map, int n_lines);
void		display_num_map(short int **map, int n_lines, int max_x);

/* game.c */
void		start_game(t_map *map);

/* game_utils.c*/

void		exit_game(t_game *g);
int			mlx_quit(t_game *game);

/* load.c */
void		load_images(t_game *g);

/* draw.c */
void		draw_something(t_game *game);
void		draw_numbers(t_game *g);

/* stat.c*/
short	int	**init_stat(t_map *map);
void		change_stat(t_game *g, int x, int y, int button);
int			is_it_solved(t_game *g);
void		reset_stat(t_game *g);

/* map.c */
char		**generate_map(void);
#endif