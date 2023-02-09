/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 23:19:33 by wocheon           #+#    #+#             */
/*   Updated: 2022/11/09 13:39:14 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_error(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (NULL);
}

static char	**ft_putword(char const *s, char c, char **str, size_t cnt)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < cnt)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			j = 0;
			while (s[j] && s[j] != c)
				j++;
			str[i] = ft_substr(s, 0, j);
			if (!str[i])
				return (ft_error(str));
			s += j;
		}
		i++;
	}
	str[i] = NULL;
	return (str);
}

static size_t	ft_word_count(char const *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			cnt++;
		while (*s && *s != c)
			s++;
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	cnt;

	if (!s)
		return (NULL);
	cnt = ft_word_count(s, c);
	str = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!str)
		return (NULL);
	return (ft_putword(s, c, str, cnt));
}
