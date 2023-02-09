/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 23:43:38 by wocheon           #+#    #+#             */
/*   Updated: 2022/11/09 12:55:32 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	temp;
	char		str[10];
	int			i;

	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	else if (n < 0)
	{
		temp = -(long long)n;
		write(fd, "-", 1);
	}
	else
		temp = (long long)n;
	i = 0;
	while (temp)
	{
		str[i++] = (temp % 10) + '0';
		temp /= 10;
	}
	while (--i >= 0)
		write(fd, &str[i], 1);
}
