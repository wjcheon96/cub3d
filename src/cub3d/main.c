/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:23:33 by wocheon           #+#    #+#             */
/*   Updated: 2023/02/11 16:03:12 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void			my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->size_line + x * (image->bpp / 8));
	*(unsigned int*)dst = color;
}

void	put_background(t_game *game)
{
	int color;

	for (int i = 0 ; i < WIN_HEIGHT - 1 ; ++i)
	{
		for (int j = 0 ; j < WIN_WIDTH - 1; ++j)
		{
			color = ((220) << 16) + ((100) << 8) + ((256 * 0));
			my_mlx_pixel_put(game->mlx->image, j, i, color);
		}	
	}
}

void	start_game(t_game *game, t_mlx *mlx)
{
	put_background(game);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->image->img, 0, 0);
	mlx_loop(game->mlx->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_mlx	mlx;

	(void)argc;
	(void)argv;
	if (argc != 2 || !filename_valid(argv[1]))
		return (0);
	parse_data(argv[1]);
	init_mlx(&mlx);
	init_data(&game, &mlx);
	start_game(&game, &mlx);
	return (0);
}
