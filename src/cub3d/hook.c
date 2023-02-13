/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:39:43 by wocheon           #+#    #+#             */
/*   Updated: 2023/02/13 16:19:05 by wocheon          ###   ########.fr       */
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

void	rotate_hook(t_player *player, int keycode)
{
	if (keycode == KEY_LEFT)
		player->theta -= 0.001;
	else if (keycode == KEY_RIGHT)
		player->theta += 0.001;
}

int	key_hook(int keycode, t_game *game)
{
	if ((keycode >= KEY_A && keycode <= KEY_D) || keycode == KEY_W)
		move_hook(game->player, keycode);
	if (keycode == KEY_ESC)
		close_image(game->mlx);
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		rotate_hook(game->player, keycode);
	reset_image(game->mlx);
	start_game(game, game->mlx);
	return (0);
}

int	exit_hook(t_game *game)
{
	close_image(game->mlx);
	return (0);
}
