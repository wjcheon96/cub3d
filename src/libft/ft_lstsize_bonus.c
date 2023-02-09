/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:04:36 by wocheon           #+#    #+#             */
/*   Updated: 2022/11/09 15:43:48 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		cnt;
	t_list	*temp;

	if (!lst)
		return (0);
	cnt = 0;
	temp = lst;
	while (temp -> next)
	{
		cnt++;
		temp = temp -> next;
	}
	if (temp -> next == NULL)
		cnt++;
	return (cnt);
}
