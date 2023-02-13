/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:39:43 by wocheon           #+#    #+#             */
/*   Updated: 2023/02/13 16:32:14 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	close_image(t_mlx *mlx)
{
	(void)mlx;
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	exit(0);
}

void	move_hook(t_player *player, int keycode)
{
	if (keycode == KEY_A)
		player->dx -= 0.1;
	else if (keycode == KEY_S)
		player->dy += 0.1;
	else if (keycode == KEY_D)
		player->dx += 0.1;
	else if (keycode == KEY_W)
		player->dy -= 0.1;
}

void	reset_image(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->image.img);
	mlx->image.img = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx->image.addr = mlx_get_data_addr(mlx->image.img, &mlx->image.bpp, \
		&mlx->image.size_line, &mlx->image.endian);
}

void	rotate_hook(t_player *player, int axis)
{
	double	old_dir_x;
	double	old_dir_y;
	double	old_plane_x;
	double	old_plane_y;

	old_dir_x = player->dir_x;
	old_dir_y = player->dir_y;
	old_plane_x = player->plane_x;
	old_plane_y = player->plane_y;
	player->dir_x = old_dir_x * cos(axis * 0.01) - old_dir_y * sin(axis * 0.01);
	player->dir_y = old_dir_x * sin(axis * 0.01) + old_dir_y * cos(axis * 0.01);
	player->plane_x = old_plane_x * cos(axis * 0.01) - \
	old_plane_y * sin(axis * 0.01);
	player->plane_y = old_plane_x * sin(axis * 0.01) + \
	old_plane_y * cos(axis * 0.01);
}

int	key_hook(int keycode, t_game *game)
{
	if ((keycode >= KEY_A && keycode <= KEY_D) || keycode == KEY_W)
		move_hook(game->player, keycode);
	if (keycode == KEY_ESC)
		close_image(game->mlx);
	if (keycode == KEY_LEFT)
		rotate_hook(game->player, -1);
	if (keycode == KEY_RIGHT)
		rotate_hook(game->player, 1);
	reset_image(game->mlx);
	start_game(game, game->mlx);
	return (0);
}

int	exit_hook(t_game *game)
{
	close_image(game->mlx);
	return (0);
}
