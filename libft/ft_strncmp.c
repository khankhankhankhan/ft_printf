/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 13:21:09 by hkang             #+#    #+#             */
/*   Updated: 2017/09/25 13:21:24 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int res;

	if (!n)
		return (0);
	res = (unsigned char)*s1 - (unsigned char)*s2;
	while (!res && n > 0 && *s1 && *s2)
	{
		res = (unsigned char)*s1 - (unsigned char)*s2;
		s1++;
		s2++;
		n--;
	}
	if (!n)
		return (res);
	if (res == 0)
		res = (unsigned char)*s1 - (unsigned char)*s2;
	return (res);
}
