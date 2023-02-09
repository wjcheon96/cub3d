/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:37:14 by wocheon           #+#    #+#             */
/*   Updated: 2022/11/25 15:09:25 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*new;

	res = NULL;
	while (lst)
	{
		new = (t_list *)malloc(sizeof(t_list));
		if (!new)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		new->content = f(lst->content);
		new->next = 0;
		ft_lstadd_back(&res, new);
		lst = lst -> next;
	}
	return (res);
}
