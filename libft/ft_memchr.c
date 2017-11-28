/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 16:49:17 by hkang             #+#    #+#             */
/*   Updated: 2017/09/28 14:09:06 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char	*t;
	size_t			i;

	if (n == 0)
		return (0);
	t = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		if (*t++ == (unsigned char)c)
			return ((void*)(src + i));
		i++;
	}
	return (0);
}
