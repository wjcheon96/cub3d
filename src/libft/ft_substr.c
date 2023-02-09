/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:07:50 by wocheon           #+#    #+#             */
/*   Updated: 2022/11/09 22:30:05 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	s_len;
	size_t	size;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if ((unsigned int)s_len <= start)
		return (ft_strdup(""));
	size = (unsigned int)s_len - start;
	if (size > len)
		size = len;
	str = (char *)malloc(sizeof(char) * size + 1);
	if (str == 0)
		return (NULL);
	i = 0;
	while (i < size)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
