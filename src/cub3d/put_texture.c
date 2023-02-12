/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:15:21 by wocheon           #+#    #+#             */
/*   Updated: 2023/02/12 18:55:12 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
	ray->texture_x = (int)(ray->wall_x * (double)TEX_WIDTH);
	if (ray->side == 0 && ray->raydir_x > 0)
		ray->texture_x = TEX_WIDTH - ray->texture_x - 1;
	if (ray->side == 1 && ray->raydir_y < 0)
		ray->texture_x = TEX_WIDTH - ray->texture_x - 1;
}

int	wall_pixel_put(t_image image, int x, int y)
{
	char	*dst;

	dst = image.addr + (y * image.size_line + x * (image.bpp / 8));
	return ((int)dst);
}

void	texture_pixel_put(t_image image, int x, int y, int color)
{
	char	*dst;

	dst = image.addr + (y * image.size_line + x * (image.bpp / 8));
	*(unsigned int *)dst = color;
}

void	texture_to_image(t_game *game, int x, t_ray *ray)
{
	int		y;
	int		tex_y;
	double		step;
	double		tex_pos;
	int		color;

	(void)game;
	step = 1.0 * TEX_HEIGHT / ray->line_height;
	tex_pos = (ray->draw_start - WIN_HEIGHT / 2 + ray->line_height / 2) * step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex_y = (int)tex_pos & (TEX_HEIGHT - 1);
		tex_pos += step;
		color = game->text[ray->texture_num].data[TEX_HEIGHT * tex_y + ray->texture_x];
		texture_pixel_put(game->mlx->image, x, y, color);
		y++;
	}
}
