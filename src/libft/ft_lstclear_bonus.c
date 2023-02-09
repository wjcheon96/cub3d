/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:33:20 by wocheon           #+#    #+#             */
/*   Updated: 2022/11/09 15:35:04 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*next;

	if (lst)
	{
		curr = *lst;
		while (curr)
		{
			next = curr -> next;
			ft_lstdelone(curr, del);
			curr = next;
		}
		*lst = NULL;
	}
}
