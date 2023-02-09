/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 05:25:21 by wocheon           #+#    #+#             */
/*   Updated: 2022/12/30 15:30:54 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_arg(char format, va_list *ap)
{
	int		i;

	i = 0;
	if (format == 'c')
		return (ft_print_char(va_arg(*ap, int)));
	else if (format == 's')
		return (ft_print_str(va_arg(*ap, char *)));
	else if (format == 'p')
		return (ft_print_ptr(va_arg(*ap, uintptr_t)));
	else if (format == 'd' || format == 'i')
		return (ft_print_int(va_arg(*ap, int)));
	else if (format == 'u' || format == 'x' || format == 'X')
		return (ft_print_uint(va_arg(*ap, unsigned int), format));
	else if (format == '%')
		return (write(1, "%", 1));
	else
		return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;
	int		arg;

	ret = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			arg = ft_get_arg(*(++format), &ap);
			if (arg >= 0)
				ret += arg;
		}
		else
		{
			write(1, format, 1);
			ret++;
		}
		format++;
	}
	va_end(ap);
	return (ret);
}
