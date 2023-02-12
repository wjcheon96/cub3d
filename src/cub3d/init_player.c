/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:47:02 by wocheon           #+#    #+#             */
/*   Updated: 2023/02/12 17:42:45 by eunrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	find_dir(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	else
		return (0);
}

void	init_player_pos(t_player *player, t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			if (find_dir(map->map[j][i]))
			{
				player->init_state = map->map[j][i];
				player->pos_x = (double)i;
				player->pos_y = (double)j;
			}
			i++;
		}
		j++;
	}
}

void	init_player_dir(t_player *player)
{
	if (player->init_state == 'N')
	{
		player->dir_x = 0.0;
		player->dir_y = -1.0;
	}
	else if (player->init_state == 'S')
	{
		player->dir_x = 0.0;
		player->dir_y = 1.0;
	}
	else if (player->init_state == 'E')
	{
		player->dir_x = 1.0;
		player->dir_y = 0.0;
	}
	else if (player->init_state == 'W')
	{
		player->dir_x = -1.0;
		player->dir_y = 0.0;
	}
}

void	init_player_plane(t_player *player)
{
	if (player->init_state == 'N')
	{
		player->plane_x = 0.66;
		player->plane_y = 0.0;
	}
	else if (player->init_state == 'S')
	{
		player->plane_x = -0.66;
		player->plane_y = 0.0;
	}
	else if (player->init_state == 'E')
	{
		player->plane_x = 0.0;
		player->plane_y = 0.66;
	}
	else if (player->init_state == 'W')
	{
		player->plane_x = 0.0;
		player->plane_y = -0.66;
	}
}

t_player	*init_player(t_map *map)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	player->dx = 0;
	player->dy = 0;
	init_player_pos(player, map);
	init_player_dir(player);
	init_player_plane(player);
	return (player);
}
