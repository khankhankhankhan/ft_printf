/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 17:25:14 by hkang             #+#    #+#             */
/*   Updated: 2017/09/18 17:31:47 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *src1, const void *src2, size_t n)
{
	unsigned char s1;
	unsigned char s2;

	while (n--)
	{
		s1 = *(unsigned char*)src1;
		s2 = *(unsigned char*)src2;
		if (s1 == s2)
		{
			src1++;
			src2++;
		}
		else
			return (s1 - s2);
	}
	return (0);
}
