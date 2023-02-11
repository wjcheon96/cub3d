/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_dda.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:13:26 by wocheon           #+#    #+#             */
/*   Updated: 2023/02/11 22:18:43 by wocheon          ###   ########.fr       */
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