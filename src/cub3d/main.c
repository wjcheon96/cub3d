/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:23:33 by wocheon           #+#    #+#             */
/*   Updated: 2023/02/10 15:43:15 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	parse_data(char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	//exception error
	line = get_next_line(fd);
	
}

void	close_image(t_mlx *ptr)
{
	mlx_destroy_window(ptr->mlx_ptr, ptr->win_ptr);
	// free_map(ptr->image.map, ptr->image.map_row);
	exit(0);
}

int	exit_hook(t_mlx *ptr)
{
	close_image(ptr);
	return (0);
}

int	key_hook(t_mlx *ptr);

int	main(int argc, char **argv)
{
	t_mlx	ptr;

	if (argc != 2 || !filename_valid(argv[1]))
		return (0);
	parse_data(argv[1]);
	ptr.mlx_ptr = mlx_init();
	ptr.win_ptr = mlx_new_window(ptr.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, TITLE);
	ptr.img_ptr = mlx_new_image(ptr.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	// start game
	mlx_hook(ptr.win_ptr, 2, 0, key_hook, &ptr);
	mlx_hook(ptr.win_ptr, 17, 0, exit_hook, &ptr);
	mlx_loop(ptr.mlx_ptr);
}