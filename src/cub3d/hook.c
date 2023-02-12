/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:39:43 by wocheon           #+#    #+#             */
/*   Updated: 2023/02/12 20:21:20 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	close_image(t_mlx *mlx)
{
	(void)mlx;
	//mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	exit(0);
}

void	move_hook(t_player *player, int keycode)
{
	if (keycode == KEY_A)
		player->dx -= 10;
	else if (keycode == KEY_S)
		player->dy -= 10;
	else if (keycode == KEY_D)
		player->dx += 10;
	else if (keycode == KEY_W)
		player->dy += 10;
}

void	reset_image(t_mlx *mlx)
{
	t_image	*img;

	mlx_destroy_image(mlx->mlx_ptr, mlx->image);
	mlx->image->img = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	img = mlx->image;
	img->addr = mlx_get_data_addr(mlx->image, &img->bpp, \
									&img->size_line, &img->endian);
}


int	key_hook(int keycode, t_game *game)
{
	if ((keycode >= KEY_A && keycode <= KEY_D) || keycode == KEY_W)
		move_hook(game->player, keycode);
	if (keycode == KEY_ESC)
		close_image(game->mlx);
	reset_image(game->mlx);
	start_game(game, game->mlx);
	return (0);
}

int	exit_hook(t_game *game)
{
	close_image(game->mlx);
	return (0);
}
