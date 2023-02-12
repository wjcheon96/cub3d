/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:39:43 by wocheon           #+#    #+#             */
/*   Updated: 2023/02/12 14:47:30 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	close_image(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	exit(0);
}

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
		close_image(mlx);
	return (0);
}

int	exit_hook(t_mlx *mlx)
{
	close_image(mlx);
	return (0);
}
