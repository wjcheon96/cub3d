/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:23:58 by wocheon           #+#    #+#             */
/*   Updated: 2023/02/13 20:23:20 by eunrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# include "libft.h"
# include "mlx.h"
# include "structure.h"
# include "parse.h"

# define TITLE "bus"
# define WIN_HEIGHT 900
# define WIN_WIDTH 1600
# define TEX_WIDTH 64
# define TEX_HEIGHT 64

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13

# define KEY_ESC 53

# define KEY_LEFT 123
# define KEY_RIGHT 124

// init_player.c
int			find_dir(char c);
void		init_player_pos(t_player *player, t_map *map);
void		init_player_dir(t_player *player);
void		init_player_plane(t_player *player);
t_player	*init_player(t_map *map);

// init.c
void		init_mlx(t_mlx *mlx);
void		init_data(t_game *game, t_mlx *mlx);

// validity_check.c
int			filename_valid(char *filename);

// parce.c
void		parse_data(t_game *game, char *file);

// put_background.c
void		put_background(t_game *game);
void		bg_pixel_put(t_image image, int x, int y, int color);

// game.c
void		start_game(t_game *game, t_mlx *mlx);
void		render(t_game *game);
void		draw_image(t_game *game, int x, t_ray *ray);
void		hit_wall(t_game *game, t_ray *ray);
void		set_texture(t_ray *ray);

// render_dda.c
void		init_ray(t_game *game, t_ray *ray, int x);
void		calculate_ray(t_game *game, t_ray *ray);
void		dda(t_game *game, t_ray *ray);
void		calculate_distance(t_game *game, t_ray *ray);

// put_texture.c
void		set_texture(t_ray *ray);
void		hit_wall(t_game *game, t_ray *ray);
int			wall_pixel_put(t_image image, int x, int y);
void		texture_pixel_put(t_image image, int x, int y, int color);
void		texture_to_image(t_game *game, int x, t_ray *ray);

// hook.c
int			exit_hook(t_game *game);
void		close_image(t_mlx *mlx);
int			key_hook(int keycode, t_game *game);
void		reset_image(t_mlx *mlx);
void		rotate_hook(t_player *player, int keycode);

void		move_hook(t_map *map, t_player *player, int keycode);

#endif
