/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:48:22 by wocheon           #+#    #+#             */
/*   Updated: 2023/02/13 15:48:17 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, \
		WIN_WIDTH, WIN_HEIGHT, "BUS");
	mlx->image.img = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx->image.addr = mlx_get_data_addr(mlx->image.img, \
		&mlx->image.bpp, &mlx->image.size_line, &mlx->image.endian);
}

void	init_data(t_game *game, t_mlx *mlx)
{
	game->mlx = mlx;
	game->player = init_player(game->map);
	parse_text(game);
}

void	init_game(t_game *game)
{
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		print_perror("allocated error");
	game->bgcolor = malloc(sizeof(t_bgcolor));
	if (!game->bgcolor)
		print_perror("allocated error");
	game->text = malloc(sizeof(t_text) * 4);
	if (!game->text)
		print_perror("allocated error");
	ft_memset(game->map, 0, sizeof(t_map));
	ft_memset(game->bgcolor, 0, sizeof(t_bgcolor));
	ft_memset(game->text, 0, sizeof(t_text) * 4);
	game->bgcolor->ceiling = -1;
	game->bgcolor->floor = -1;
}
