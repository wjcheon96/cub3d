/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 05:42:31 by wocheon           #+#    #+#             */
/*   Updated: 2023/01/10 12:45:56 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_size(unsigned long long n, int base_len)
{
	int	size;

	size = 0;
	if (n == 0)
		size++;
	while (n)
	{
		n /= base_len;
		size++;
	}
	return (size);
}

char	*ft_itoa_base(unsigned long long n, char *base)
{
	int			base_len;
	int			size;
	char		*ret;

	base_len = ft_strlen(base);
	size = ft_itoa_size(n, base_len);
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	ret[size] = '\0';
	size--;
	if (n == 0)
		ret[0] = '0';
	while (n)
	{
		ret[size--] = base[n % base_len];
		n /= base_len;
	}
	return (ret);
}
