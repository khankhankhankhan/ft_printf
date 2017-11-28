/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 16:13:57 by hkang             #+#    #+#             */
/*   Updated: 2017/09/27 22:10:40 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*res;
	int		size;

	size = ft_getnsize(n);
	res = ft_strnew(size);
	if (!res)
		return (0);
	if (n == 0)
		res[0] = '0';
	if (n < 0)
		res[0] = '-';
	while (n)
	{
		size--;
		if (n < 0)
			res[size] = 48 - n % 10;
		else
			res[size] = 48 + n % 10;
		n = n / 10;
	}
	return (res);
}
