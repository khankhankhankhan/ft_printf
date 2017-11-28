/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 20:00:40 by hkang             #+#    #+#             */
/*   Updated: 2017/10/12 20:10:02 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *res;

	res = (t_list*)malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	if (!content)
	{
		res->content = NULL;
		res->content_size = 0;
		res->next = NULL;
		return (res);
	}
	res->content = ft_memalloc(content_size);
	if (!res->content)
		return (NULL);
	ft_memcpy(res->content, content, content_size);
	res->content_size = content_size;
	res->next = NULL;
	return (res);
}
