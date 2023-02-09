/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_formats.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 05:53:03 by wocheon           #+#    #+#             */
/*   Updated: 2022/12/31 18:30:51 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_char(int ap)
{
	return (write(1, &ap, 1));
}

int	ft_print_str(char *ap)
{
	if (!ap)
		return (write(1, "(null)", 6));
	return (write(1, ap, ft_strlen(ap)));
}

int	ft_print_ptr(uintptr_t ap)
{
	char	*str;
	int		bytes;

	write(1, "0x", 2);
	str = ft_itoa_base(ap, "0123456789abcdef");
	if (!str)
		return (-1);
	bytes = ft_strlen(str);
	write(1, str, bytes);
	free(str);
	str = NULL;
	return (bytes + 2);
}

int	ft_print_int(long long ap)
{
	char	*str;
	int		bytes;

	if (ap < 0)
	{
		write(1, "-", 1);
		str = ft_itoa_base(-ap, "0123456789");
	}
	else
		str = ft_itoa_base(ap, "0123456789");
	if (!str)
		return (-1);
	bytes = ft_strlen(str);
	write(1, str, bytes);
	free(str);
	str = NULL;
	if (ap < 0)
		bytes++;
	return (bytes);
}

int	ft_print_uint(unsigned int ap, char type)
{
	char	*str;
	int		bytes;

	if (type == 'u')
		str = ft_itoa_base(ap, "0123456789");
	else if (type == 'x')
		str = ft_itoa_base(ap, "0123456789abcdef");
	else
		str = ft_itoa_base(ap, "0123456789ABCDEF");
	if (!str)
		return (-1);
	bytes = ft_strlen(str);
	write(1, str, bytes);
	free(str);
	str = NULL;
	return (bytes);
}
