/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunrlee <eunrlee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:14:45 by eunrlee           #+#    #+#             */
/*   Updated: 2023/02/11 21:15:00 by eunrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
	while (line[i] && line[i] == ' ')
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
