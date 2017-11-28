/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:35:31 by hkang             #+#    #+#             */
/*   Updated: 2017/09/18 15:47:33 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t len)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = dest;
	s = src;
	i = 0;
	while (i < len)
	{
		i++;
		*d++ = *s++;
		if (*(s - 1) == c)
			return (dest + i);
	}
	return (0);
}
