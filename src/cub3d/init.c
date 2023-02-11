/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:48:22 by wocheon           #+#    #+#             */
/*   Updated: 2023/02/11 16:03:00 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, \
		WIN_WIDTH, WIN_HEIGHT, "BUS");
	mlx->image = malloc(sizeof(t_image));
	if (!mlx->image)
		exit(1);
	mlx->image->img = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx->image->addr = mlx_get_data_addr(mlx->image->img, \
		&mlx->image->bpp, &mlx->image->size_line, &mlx->image->endian);
}

void	init_data(t_game *game, t_mlx *mlx)
{

	game->player = init_player(game->map);
	game->mlx = mlx;
}
