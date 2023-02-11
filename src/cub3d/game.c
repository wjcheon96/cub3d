/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:44:10 by wocheon           #+#    #+#             */
/*   Updated: 2023/02/11 20:35:24 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_ray(t_game *game, t_ray *ray, int x)
{
	t_player	*player;

	player = game->player;
	ray->camera = 2 * x / (double)WIN_WIDTH - 1;
	ray->raydir_x = player->dir_x + player->dx + player->plane_x * ray->camera;
	ray->raydir_y = player->dir_y + player->dy + player->plane_y * ray->camera;
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
	if (ray->raydir_x == 0)
		ray->deltadist_x = 1e30;
	else
		ray->deltadist_x = fabs(1 / ray->raydir_x);
	if (ray->raydir_y == 0)
		ray->deltadist_y = 1e30;
	else
		ray->deltadist_y = fabs(1 / ray->raydir_y);
	ray->hit = 0;
}

// dx, dy key press
void	calculate_ray(t_game *game, t_ray *ray)
{
	t_player	*player;

	player = game->player;
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (player->pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - player->pos_x) * ray->deltadist_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (player->pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - player->pos_y) * ray->deltadist_y;
	}
}

void	dda(t_game *game, t_ray *ray)
{
	t_map	*map;

	map = game->map;
	while (ray->hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 0;
		}
		if (map->map[ray->map_x][ray->map_y] > 0)
			ray->hit = 1;
	}
}

void	calculate_distance(t_game *game, t_ray *ray)
{
	t_player	*player;

	player = game->player;
	if (ray->side == 0)
		ray->walldist = (ray->map_x - player->pos_x + (1 - ray->step_x) / 2) \
		/ ray->raydir_x;
	else
		ray->walldist = (ray->map_y - player->pos_y + (1 - ray->step_y) / 2) \
		/ ray->raydir_y;
	ray->line_height = (int)(WIN_HEIGHT / ray->walldist);
	ray->draw_start = WIN_HEIGHT / 2 - ray->line_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
}

void	set_texture(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->raydir_y < 0)
			ray->texture_num = 0;
		else
			ray->texture_num = 1;
	}
	else
	{
		if (ray->raydir_x < 0)
			ray->texture_num = 2;
		else
			ray->texture_num = 3;
	}
}

void	hit_wall(t_game *game, t_ray *ray)
{
	t_player	*player;

	player = game->player;
	if (ray->side == 0)
		ray->wall_x = player->pos_y + ray->walldist * ray->raydir_y;
	else
		ray->wall_x = player->pos_x + ray->walldist * ray->raydir_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->texure_x = (int)(ray->wall_x * (double)TEX_WIDTH);
	if (ray->side == 0 && ray->raydir_x > 0)
		ray->texure_x = TEX_HEIGHT - ray->texure_x -1;
	if (ray->side == 1 && ray->raydir_y < 0)
		ray->texure_x = TEX_HEIGHT - ray->texure_x - 1;
}

char	*wall_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->size_line + x * (image->bpp / 8));
	*(unsigned int *)dst = color;
	return ((char *)dst);
}

void	texture_to_image(t_ray *ray)
{
	double	step;
	double	tex_pos;
	int		y;
	int		tex_y;

	step = 1.0 * TEX_HEIGHT / ray->line_height;
	tex_pos = (ray->draw_start - WIN_HEIGHT / 2 + WIN_HEIGHT / 2) * step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex_y = (int)tex_pos & (TEX_HEIGHT - 1);
		tex_pos += step;
		y++;
	}
}

void	draw_image(t_game *game, t_ray *ray)
{
	set_texture(ray);
	hit_wall(game, ray);
	texture_to_image(ray);
}

void	render(t_game *game)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		init_ray(game, &ray, x);
		calculate_ray(game, &ray);
		dda(game, &ray);
		calculate_distance(game, &ray);
		draw_image(game, &ray);
		x++;
	}
}

void	start_game(t_game *game, t_mlx *mlx)
{
	put_background(game);
	render(game);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->image->img, 0, 0);
	mlx_loop(game->mlx->mlx_ptr);
}