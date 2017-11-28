/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 21:32:03 by hkang             #+#    #+#             */
/*   Updated: 2017/09/27 22:26:32 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *res;
	t_list *first;
	t_list *temp;

	if (!lst)
		return (0);
	temp = lst->next;
	lst = f(lst);
	first = ft_lstnew(lst->content, lst->content_size);
	if (!first)
		return (0);
	res = first;
	lst = temp;
	while (lst)
	{
		temp = res;
		res = ft_lstnew(f(lst)->content, f(lst)->content_size);
		if (!res)
			return (0);
		temp->next = res;
		temp = lst->next;
		lst = f(lst);
		lst = temp;
	}
	return (first);
}
