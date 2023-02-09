/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:37:32 by wocheon           #+#    #+#             */
/*   Updated: 2022/12/30 16:11:17 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (dest);
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin_readbyte(char *s1, char *s2, ssize_t read_byte)
{
	ssize_t	s1_len;
	char	*str;

	s1_len = 0;
	while (s1 && s1[s1_len])
		s1_len++;
	str = malloc(sizeof(char) * s1_len + read_byte + 1);
	if (!str)
	{
		free(s2);
		return (0);
	}
	ft_strncpy(str, s1, s1_len);
	ft_strncpy(str + s1_len, s2, read_byte);
	return (str);
}

t_elem	*push_back(t_node *list, int fd)
{
	t_elem	*new;

	new = malloc(sizeof(t_elem));
	if (new == NULL)
		return (NULL);
	new -> prev = NULL;
	new -> next = NULL;
	new -> fd = fd;
	new -> data = NULL;
	if (list-> head == NULL)
	{
		list -> head = new;
		list -> tail = new;
	}
	else
	{
		list -> tail -> next = new;
		new -> prev = list -> tail;
		list -> tail = new;
	}
	return (new);
}

t_elem	*find_node(t_node *list, int fd)
{
	t_elem	*node;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	node = list -> head;
	while (node != 0)
	{
		if (node -> fd == fd)
			return (node);
		node = node -> next;
	}
	node = push_back(list, fd);
	if (node == NULL)
		return (NULL);
	return (node);
}

void	delete_node(t_node *list, t_elem *backup)
{
	if (backup == NULL)
		return ;
	if (backup -> prev != NULL)
		backup -> prev -> next = backup -> next;
	else
		list -> head = backup -> next;
	if (backup -> next != NULL)
		backup -> next -> prev = backup -> prev;
	else
		list -> tail = backup -> prev;
	free(backup -> data);
	free(backup);
}
