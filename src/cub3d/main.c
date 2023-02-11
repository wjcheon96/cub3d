/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:23:33 by wocheon           #+#    #+#             */
/*   Updated: 2023/02/11 19:53:08 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int argc, char **argv)
{
	t_game	game;
	t_mlx	mlx;

	if (argc != 2 || !filename_valid(argv[1]))
		return (0);
	parse_data(&game, argv[1]);
	init_mlx(&mlx);
	init_data(&game, &mlx);
	start_game(&game, &mlx);
	return (0);
}
