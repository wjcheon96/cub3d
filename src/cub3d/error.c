/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunrlee <eunrlee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:30:59 by eunrlee           #+#    #+#             */
/*   Updated: 2023/02/13 19:31:00 by eunrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	print_perror(char *str)
{
	perror(str);
	exit(1);
}

void	print_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(1);
}
