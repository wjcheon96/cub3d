/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:15:24 by eunrlee           #+#    #+#             */
/*   Updated: 2023/02/13 15:49:14 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	parse_line(t_game *game, char *line, int type)
{
	if (type >= 0 && type <= 3)
	{
		if (game->text[type].path)
			print_error("path error");
		game->text[type].path = ft_mystrdup(line + 2);
	}
	else if (type == 4)
		game->bgcolor->floor = type_color(line + 1);
	else if (type == 5)
		game->bgcolor->ceiling = type_color(line + 1);
	else
		game->map->map_temp = ft_strjoin(game->map->map_temp, line);
}

void	trans_map(t_game *game, char **temp)
{
	int	x;
	int	y;

	y = 0;
	while (temp[y])
	{
		game->map->map[y] = (int *)malloc(sizeof(int) * game->map->width);
		if (!game->map->map[y])
			print_error("allocated error");
		ft_memset(game->map->map[y], -1, sizeof(int) * game->map->width);
		x = -1;
		while (temp[y][++x])
		{
			if (temp[y][x] == '0')
				game->map->map[y][x] = 0;
			else if (temp[y][x] == '1')
				game->map->map[y][x] = 1;
			else if (temp[y][x] == 'N' || temp[y][x] == 'W' || \
				temp[y][x] == 'S' || temp[y][x] == 'E')
				game->map->map[y][x] = temp[y][x];
		}
		y++;
	}
}

void	parse_map(t_game *game)
{
	char	**temp;

	temp = ft_split(game->map->map_temp, '\n');
	if (!temp)
		print_error("allocated error");
	game->map->height = get_size(temp);
	game->map->width = get_maxlen(temp);
	game->map->map = (int **)malloc(sizeof(int *) * game->map->height);
	if (!game->map->map)
		print_error("allocated error");
	trans_map(game, temp);
	free_str(temp);
}

void	check_map(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] != -1 && map->map[y][x] != 1)
			{
				if (y == map->height || x == map->width || x == 0 || y == 0)
					print_error("map error");
				if (map->map[y - 1][x] == -1 || map->map[y + 1][x] == -1 || \
						map->map[y][x - 1] == -1 || map->map[y][x + 1] == -1)
					print_error("map error");
			}
			x++;
		}
		y++;
	}
}
