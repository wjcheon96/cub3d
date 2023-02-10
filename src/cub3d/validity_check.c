/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:26:54 by wocheon           #+#    #+#             */
/*   Updated: 2023/02/10 15:27:35 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	filename_valid(char *filename)
{
	char	**split_filename;
	int		divided_length;
	int		validity;

	validity = 0;
	divided_length = 0;
	split_filename = ft_split(filename, '.');
	if (!split_filename)
		ft_error("split error");
	while (split_filename[divided_length] != 0)
		divided_length++;
	if (!ft_strncmp(split_filename[divided_length - 1], "cub", 4))
		validity = 1;
	free_split(split_filename);
	return (validity);
}