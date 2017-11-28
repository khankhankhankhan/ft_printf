/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 16:07:27 by hkang             #+#    #+#             */
/*   Updated: 2017/09/18 16:24:33 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	size_t		i;

	if (dest == src || len == 0)
		return (dest);
	i = 0;
	d = dest;
	s = src;
	while (i < len && d < s)
	{
		*(d + i) = *(s + i);
		i++;
	}
	while (len > 0 && d > s)
	{
		*(d + len - 1) = *(s + len - 1);
		len--;
	}
	return (dest);
}
