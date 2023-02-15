/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:39:52 by wocheon           #+#    #+#             */
/*   Updated: 2023/02/14 17:04:03 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	move_down(t_map *map, t_player *player)
{
	int	x;
	int	y;

	(void)map;
	x = (int)(player->pos_x - player->dir_x * 0.11);
	y = (int)(player->pos_y - player->dir_y * 0.11);
	if (map->map[(int)(player->pos_y)][x] != 1)
		player->pos_x -= player->dir_x * 0.1;
	if (map->map[y][(int)(player->pos_x)] != 1)
		player->pos_y -= player->dir_y * 0.1;
}

void	move_up(t_map *map, t_player *player)
{
	int	x;
	int	y;

	(void)map;
	x = (int)(player->pos_x + player->dir_x * 0.11);
	y = (int)(player->pos_y + player->dir_y * 0.11);
	if (map->map[(int)(player->pos_y)][x] != 1)
		player->pos_x += player->dir_x * 0.1;
	if (map->map[y][(int)(player->pos_x)] != 1)
		player->pos_y += player->dir_y * 0.1;
}

void	move_left(t_map *map, t_player *player)
{
	int		x;
	int		y;
	double	dir_x;
	double	dir_y;

	dir_x = player->dir_x * cos(M_PI / 2) - player->dir_y * sin(M_PI / 2);
	dir_y = player->dir_x * sin(M_PI / 2) + player->dir_y * cos(M_PI / 2);
	x = (int)(player->pos_x - dir_x * 0.11);
	y = (int)(player->pos_y - dir_y * 0.11);
	if (map->map[(int)(player->pos_y)][x] != 1)
		player->pos_x -= dir_x * 0.1;
	if (map->map[y][(int)(player->pos_x)] != 1)
		player->pos_y -= dir_y * 0.1;
}

void	move_right(t_map *map, t_player *player)
{
	int		x;
	int		y;
	double	dir_x;
	double	dir_y;

	dir_x = player->dir_x * cos(M_PI / 2) - player->dir_y * sin(M_PI / 2);
	dir_y = player->dir_x * sin(M_PI / 2) + player->dir_y * cos(M_PI / 2);
	x = (int)(player->pos_x + dir_x * 0.11);
	y = (int)(player->pos_y + dir_y * 0.11);
	if (map->map[(int)(player->pos_y)][x] != 1)
		player->pos_x += dir_x * 0.1;
	if (map->map[y][(int)(player->pos_x)] != 1)
		player->pos_y += dir_y * 0.1;
}

void	move_hook(t_map *map, t_player *player, int keycode)
{
	if (keycode == KEY_A)
		move_left(map, player);
	else if (keycode == KEY_D)
		move_right(map, player);
	if (keycode == KEY_S)
		move_down(map, player);
	else if (keycode == KEY_W)
		move_up(map, player);
}
