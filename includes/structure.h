/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:58:51 by wocheon           #+#    #+#             */
/*   Updated: 2023/02/11 16:05:24 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef struct s_map
{
	char	*map_temp;
	int		**map;
	int		hei;
	int		wid;
}	t_map;

typedef struct s_text
{
	char	*path;
	int		*texture;
	double	wid;
	double	hei;
}	t_text;

typedef struct s_image
{
	void	*img;
	void	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_image;

typedef struct s_bgcolor
{
	int	floor;
	int	ceiling;
}	t_bgcolor;

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
	t_text		*text;
	t_bgcolor	*bgcolor;
	t_map		*map;
	t_player	*player;
	t_mlx		*mlx;
}	t_game;


#endif