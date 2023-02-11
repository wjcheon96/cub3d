/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunrlee <eunrlee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:15:24 by eunrlee           #+#    #+#             */
/*   Updated: 2023/02/11 21:15:25 by eunrlee          ###   ########.fr       */
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

	x = 0;
	while (temp[x])
	{
		game->map->map[x] = (int *)malloc(sizeof(int) * game->map->height);
		if (!game->map->map[x])
			print_error("allocated error");
		ft_memset(game->map->map[x], -1, sizeof(int) * game->map->height);
		y = -1;
		while (temp[x][++y])
		{
			if (temp[x][y] == '0')
				game->map->map[x][y] = 0;
			else if (temp[x][y] == '1')
				game->map->map[x][y] = 1;
			else if (temp[x][y] == 'N' || temp[x][y] == 'W' || \
				temp[x][y] == 'S' || temp[x][y] == 'E')
				game->map->map[x][y] = temp[x][y];
		}
		x++;
	}
}

void	parse_map(t_game *game)
{
	char	**temp;

	temp = ft_split(game->map->map_temp, '\n');
	if (!temp)
		print_error("allocated error");
	game->map->height = get_maxlen(temp);
	game->map->width = get_size(temp);
	game->map->map = (int **)malloc(sizeof(int *) * game->map->width);
	if (!game->map->map)
		print_error("allocated error");
	trans_map(game, temp);
	free_str(temp);
}

void	check_map(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->width)
	{
		y = 0;
		while (y < map->height)
		{
			if (map->map[x][y] != -1 && map->map[x][y] != 1)
			{
				if (y == map->height || x == map->width || x == 0 || y == 0)
					print_error("map error");
				if (map->map[x - 1][y] == -1 || map->map[x + 1][y] == -1 || \
						map->map[x][y - 1] == -1 || map->map[x][y + 1] == -1)
					print_error("map error");
			}
			y++;
		}
		x++;
	}
}
