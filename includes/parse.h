/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:45:50 by wocheon           #+#    #+#             */
/*   Updated: 2023/02/11 22:40:25 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "structure.h"

// parse.c
void	parse_data(t_game *game, char *file);
void	read_file(t_game *game, char *file, int fd);
void	parse_text(t_game *game);
// size.c
int		get_sizec(char	*str, int c);
int		get_size(char	**str);
int		get_maxlen(char **str);

// type.c
int		valid_line(char *line);
int		type_color(char *line);
int		get_type(char *line);

// str.c
void	free_str(char **str);
char	*ft_mystrdup(char *line);
long	ft_myatoi(const char *str);
// map.c
void	check_map(t_map *map);
void	parse_map(t_game *game);
int		trans_map(t_game *game, char **temp, int cnt);
void	parse_line(t_game *game, char *line, int type);
// init.c
void	init_game(t_game *game);
// error.c
void	print_perror(char *str);
void	print_error(char *str);
#endif