/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:37:01 by wocheon           #+#    #+#             */
/*   Updated: 2022/12/30 16:06:15 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_elem
{
	struct s_elem	*next;
	struct s_elem	*prev;
	char			*data;
	int				fd;
}	t_elem;

typedef struct s_node
{
	t_elem	*head;
	t_elem	*tail;
}	t_node;

char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strjoin(char *s1, char *s2, ssize_t read_byte);
void	delete_node(t_node *list, t_elem *backup);
t_elem	*push_back(t_node *list, int fd);
t_elem	*find_node(t_node *list, int fd);
char	*get_next_line(int fd);

#endif
