/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 17:49:14 by hkang             #+#    #+#             */
/*   Updated: 2017/09/19 19:17:51 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*copy;

	len = ft_strlen(src) + 1;
	if (!(copy = (char*)malloc(len)))
		return (0);
	copy = (char*)ft_memcpy(copy, src, len);
	return (copy);
}
