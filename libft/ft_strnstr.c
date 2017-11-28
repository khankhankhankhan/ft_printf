/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 11:38:39 by hkang             #+#    #+#             */
/*   Updated: 2017/09/25 13:28:21 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *dest, const char *src, size_t len)
{
	size_t l1;
	size_t l2;

	l2 = ft_strlen(src);
	if (!l2)
		return ((char*)dest);
	l1 = ft_strlen(dest);
	len = (len > l1) ? l1 : len;
	while (len >= l2)
	{
		if (!ft_memcmp(dest, src, l2))
			return ((char*)dest);
		dest++;
		len--;
	}
	return (0);
}
