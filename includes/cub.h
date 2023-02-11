/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:23:58 by wocheon           #+#    #+#             */
/*   Updated: 2023/02/11 16:02:22 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# include "libft.h"
# include "mlx.h"
# include "structure.h"

# define TITLE "bus"
# define WIN_MAGNI 100
# define WIN_HEIGHT (WIN_MAGNI * 9)
# define WIN_WIDTH (WIN_MAGNI * 16)

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13

# define KEY_ESC 53

# define KEY_LEFT 123
# define KEY_RIGHT 124

// init_player.c
int			find_dir(char c);
void		init_player_pos(t_player *player, t_map *map);
void		init_player_dir(t_player *player);
void		init_player_plane(t_player *player);
t_player	*init_player(t_map *map);

// init.c
void		init_mlx(t_mlx *mlx);
void		init_data(t_game *game, t_mlx *mlx);

// validity_check.c
int			filename_valid(char *filename);

// parce.c
void		parse_data(t_game *game, char *file);

#endif