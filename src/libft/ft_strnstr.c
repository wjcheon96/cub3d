/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:23:18 by wocheon           #+#    #+#             */
/*   Updated: 2022/11/09 22:29:35 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h_len;
	size_t	n_len;
	size_t	i;

	if (*needle == '\0')
		return ((char *)haystack);
	h_len = ft_strlen(haystack);
	n_len = ft_strlen(needle);
	if (h_len < n_len || len < n_len)
		return (0);
	if (h_len > len)
		i = len;
	else
		i = h_len;
	while (i-- >= n_len)
	{
		if (!ft_strncmp(haystack, needle, n_len))
			return ((char *)haystack);
		haystack++;
	}
	return (0);
}
