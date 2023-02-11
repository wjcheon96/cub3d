/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:44:10 by wocheon           #+#    #+#             */
/*   Updated: 2023/02/11 22:55:25 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_image(t_game *game, t_ray *ray)
{
	set_texture(ray);
	hit_wall(game, ray);
	texture_to_image(game, ray);
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
