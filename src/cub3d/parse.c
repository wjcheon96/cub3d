/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:00:30 by wocheon           #+#    #+#             */
/*   Updated: 2023/02/11 16:08:59 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	print_error(char *str)
{
	perror(str);
	exit(1);
}

int	get_sizec(char	*str, int c)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == c)
			i++;
		str++;
	}
	return (i);
}

int	get_size(char	**str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	get_maxlen(char **str)
{
	int	i;
	int	ret;
	int	len;

	i = 0;
	ret = 0;
	while (str[i])
	{
		len = ft_strlen(str[i]);
		if (len > ret)
			ret = len;
		i++;
	}
	return (ret);
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	is_space(int c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int	valid_line(char *line)
{
	int	i;

	i = 0;
	if (line[0] == '\n')
		return (0);
	while (line[i])
	{
		if (line[i] == '\n')
			break ;
		if (line[i] != '0' && line[i] != '1' && line[i] != 'W' \
			&& line[i] != 'N' && line[i] != 'E' && line[i] != 'S'
			&& !is_space(line[i]))
			return (0);
		i++;
	}
	return (1);
}

char	*ft_mystrdup(char *line)
{
	int		len;
	char	*ret;
	int		i;
	int		nl;

	nl = 0;
	if (ft_strchr(line, '\n'))
		nl = 1;
	i = 0;
	while (line[i] && is_space(line[i]))
		i++;
	len = 0;
	while (line[i + len])
		len++;
	ret = (char *)malloc(sizeof(char) * (len - nl + 1));
	if (!ret)
		print_error("allocated error");
	ft_strlcpy(ret, line + i, len);
	return (ret);
}

int	type_color(char *line)
{
	int		i;
	int		num;
	int		ret;
	char	**tmp;

	if (get_sizec(line, ',') != 2)
		print_error("color error");
	while (is_space(*line))
		line++;
	tmp = ft_split(line, ',');
	if (!tmp)
		print_error("allocated error");
	i = -1;
	ret = 0;
	while (++i < 3)
	{
		ret = ret << 8;
		num = ft_atoi(tmp[i]);
		if (num < 0 || num > 256)
			print_error("");
		ret += num;
	}
	free_str(tmp);
	return (ret);
}

void	parse_line(t_game *game, char *line, int type)
{
	if (type >= 0 && type <= 3)
	{
		if (game->text[type].path)
			print_error("");
		game->text[type].path = ft_mystrdup(line + 2);
	}
	else if (type == 4)
		game->bgcolor->floor = type_color(line + 1);
	else if (type == 5)
		game->bgcolor->ceiling = type_color(line + 1);
	else
		game->map->map_temp = ft_strjoin(game->map->map_temp, line);
}

int	get_type(char *line)
{

	if (*line == 'N' && *(line + 1) == 'O')
		return (0);
	else if (*line == 'W' && *(line + 1) == 'E')
		return (1);
	else if (*line == 'S' && *(line + 1) == 'O')
		return (2);
	else if (*line == 'E' && *(line + 1) == 'A')
		return (3);
	else if (*line == 'F' && *(line + 1) == ' ')
		return (4);
	else if (*line == 'C' && *(line + 1) == ' ')
		return (5);
	else if (valid_line(line))
		return (6);
	return (-1);
}

void	parse_map(t_game *game)
{
	char	**temp;
	int	x;
	int	y;

	temp = ft_split(game->map->map_temp, '\n');
	if (!temp)
		print_error("akffhr");
	game->map->hei = get_size(temp);
	game->map->wid = get_maxlen(temp);
	game->map->map = (int **)malloc(sizeof(int *) * game->map->hei);
	if (!game->map->map)
		print_error("akffhr");
	y = 0;
	while (temp[y])
	{
		game->map->map[y] = (int *)malloc(sizeof(int) * game->map->wid);
		if (!game->map->map[y])
			print_error("akffhr");
		ft_memset(game->map->map[y], -1, sizeof(int) * game->map->wid);
		x = -1;
		while (temp[y][++x])
		{
			if (temp[y][x] == ' ')
				continue ;
			if (temp[y][x] == '0')
				game->map->map[y][x] = 0;
			else if (temp[y][x] == '1')
				game->map->map[y][x] = 1;
			else
				game->map->map[y][x] = temp[y][x];
		}
		y++;
	}
}

void	init_game(t_game *game)
{
	game->map = malloc(sizeof(t_map));
	game->bgcolor = malloc(sizeof(t_bgcolor));
	game->text = malloc(sizeof(t_text) * 4);
	ft_memset(game->map, 0, sizeof(t_map));
	ft_memset(game->bgcolor, 0, sizeof(t_bgcolor));
	ft_memset(game->text, 0, sizeof(t_text));
}

void	parse_data(t_game *game, char *file)
{
	int		fd;
	char	*line;
	int		type;

	init_game(game);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_error(file);
	line = 0;
	while (1)
	{
		if (line)
			free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] == '\n' && game->map->map_temp)
			print_error("map error");
		if (line[0] == '\n')
			continue ;
		type = get_type(line);
		if (type == -1)
			print_error("type error");
		parse_line(game, line, type);
	}
	close(fd);
	parse_map(game);
}
