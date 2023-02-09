/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 23:31:13 by wocheon           #+#    #+#             */
/*   Updated: 2022/11/09 22:29:25 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_count(long long num)
{
	int	len;

	len = 0;
	if (num <= 0)
	{
		len++;
		num *= -1;
	}
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long long	num;
	int			len;
	char		*str;

	num = (long long)n;
	len = ft_len_count(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	if (num == 0)
		str[0] = '0';
	else if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	while (num)
	{
		str[len--] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
