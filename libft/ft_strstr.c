/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 13:32:51 by hkang             #+#    #+#             */
/*   Updated: 2017/09/25 13:37:04 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *dest, const char *src)
{
	const char *d;
	const char *tempd;
	const char *temps;

	d = dest;
	if (*src == 0)
		return ((char*)d);
	while (*d)
	{
		tempd = d;
		temps = src;
		while (*temps == *tempd)
		{
			tempd++;
			temps++;
			if (*temps == '\0')
				return ((char*)d);
		}
		d++;
	}
	return (0);
}
