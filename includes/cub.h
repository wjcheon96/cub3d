/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:23:58 by wocheon           #+#    #+#             */
/*   Updated: 2023/02/11 14:18:22 by wocheon          ###   ########.fr       */
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

# define TITLE "bus"
# define WIN_MAGNI 100
# define WIN_HEIGHT (WIN_MAGNI * 9)
# define WIN_WIDTH (WIN_MAGNI * 16)

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13

# define KEY_ESC 53

# define KEY_LEFT 123
# define KEY_RIGHT 124

typedef struct s_map
{
	int		**map;
	int		height;
	int		width;
}	t_map;

typedef struct s_image
{
	void	*img;
	void	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_image;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_image	*image;
}	t_mlx;

typedef struct s_player
{
	int		init_state;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	raydir_x;
	double	raydir_y;
}	t_player;

typedef struct s_ray
{
	double	theta;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	walldist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		texture_num;
	double	wall_x;
	int		texure_x;
}	t_ray;

typedef struct s_game
{
	t_map		*map;
	t_player	*player;
	t_mlx		*mlx;
}	t_game;

// init_player.c
int			find_dir(char c);
void		init_player_pos(t_player *player, t_map *map);
void		init_player_dir(t_player *player);
void		init_player_plane(t_player *player);
t_player	*init_player(t_map *map);

// init.c
void		init_mlx(t_mlx *mlx);
void		init_data(t_game *game, t_mlx *mlx);

#endif