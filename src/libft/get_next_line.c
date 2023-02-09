/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:36:16 by wocheon           #+#    #+#             */
/*   Updated: 2022/12/30 16:07:34 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strchr_idx(char *s, char c)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i + 1);
		i++;
	}
	if (c == '\0')
		return (i + 1);
	return (0);
}

char	*get_newline(t_node *list, t_elem *backup, ssize_t read_byte)
{
	char	*result;
	ssize_t	data_len;

	data_len = 0;
	while (backup -> data && backup -> data[data_len])
		data_len++;
	if (read_byte < 0 || data_len == 0)
	{
		delete_node(list, backup);
		return (NULL);
	}
	result = malloc(sizeof(char) * (data_len + 1));
	if (result == NULL)
	{
		delete_node(list, backup);
		return (NULL);
	}
	ft_strncpy(result, backup -> data, data_len);
	delete_node(list, backup);
	return (result);
}

char	*get_result(t_node *list, t_elem *backup, size_t result_len,
	size_t data_len)
{
	char	*result;
	char	*temp;

	while (backup -> data && backup->data[data_len])
		data_len++;
	result = malloc(sizeof(char) * (result_len + 1));
	if (result == 0)
	{
		delete_node(list, backup);
		return (0);
	}
	ft_strncpy(result, backup -> data, result_len);
	temp = backup -> data;
	backup -> data = malloc(sizeof(char) * (data_len - result_len + 1));
	if (backup -> data == 0)
	{
		free (result);
		backup -> data = temp;
		delete_node(list, backup);
		return (0);
	}
	ft_strncpy(backup -> data, temp + result_len, data_len - result_len);
	free(temp);
	return (result);
}

ssize_t	read_buf(t_elem *backup, int fd)
{
	char	*buf;
	char	*temp;
	ssize_t	read_byte;

	buf = malloc(sizeof(char) * BUFFER_SIZE);
	if (buf == NULL)
		return (-1);
	while (1)
	{
		read_byte = read(fd, buf, BUFFER_SIZE);
		if (read_byte <= 0)
			break ;
		temp = backup -> data;
		backup -> data = ft_strjoin_readbyte(backup -> data, buf, read_byte);
		if (backup -> data == 0)
		{
			backup -> data = temp;
			return (-1);
		}
		free (temp);
		if (ft_strchr_idx(backup -> data, '\n') != 0)
			break ;
	}
	free(buf);
	return (read_byte);
}

char	*get_next_line(int fd)
{
	static t_node	list;
	t_elem			*backup;
	size_t			result_len;
	ssize_t			read_byte;

	if (BUFFER_SIZE <= 0)
		return (0);
	backup = find_node(&list, fd);
	if (!backup)
		return (NULL);
	while (1)
	{
		result_len = ft_strchr_idx(backup -> data, '\n');
		if (result_len > 0)
			return (get_result(&list, backup, result_len, 0));
		read_byte = read_buf(backup, fd);
		if (read_byte <= 0)
			return (get_newline(&list, backup, read_byte));
	}
}
