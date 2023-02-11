/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:23:33 by wocheon           #+#    #+#             */
/*   Updated: 2023/02/11 14:09:50 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	start_game(t_game *game)
{
	
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_mlx	mlx;

	if (argc != 2 || !filename_valid(argv[1]))
		return (0);
	parse_data(argv[1]);
	init_mlx(&mlx);
	init_data(&game, &mlx);
	start_game(&game);
	return (0);
}
