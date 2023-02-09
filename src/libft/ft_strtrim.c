/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 23:15:39 by wocheon           #+#    #+#             */
/*   Updated: 2022/11/09 12:59:33 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *s2)
{
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	if (!s2)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(s2, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (end && ft_strchr(s2, s1[end]))
		end--;
	return (ft_substr(s1, start, end - start + 1));
}
