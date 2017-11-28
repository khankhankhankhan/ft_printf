/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 19:49:40 by hkang             #+#    #+#             */
/*   Updated: 2017/11/06 12:03:49 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_getunsig_len(unsigned long long int value, int base)
{
	unsigned int len;
	unsigned long long int b;

	b = (unsigned long long int)base;
	len = 1;
	while (value / b != 0)
	{
		len++;
		value = value / b;
	}
	return (len);
}

unsigned int	ft_getsig_len(long long int value)
{
	unsigned int len;

	len = 1;
	if (value < 0)
		len++;
	while (value / 10 != 0)
	{
		len++;
		value = value / 10;
	}
	return (len);
}

unsigned int	ft_getdouble_len(long double value, long double *limit)
{
	unsigned int len;

	len = 2;
	*limit = 1;
	if (value < 0)
		len++;
	while (value > 10 || value < -10)
	{
		len++;
		value = value / 10;
		*limit = (*limit) * 10;
	}
	return (len);
}

char	*ft_itoa_base(uintmax_t num, uintmax_t base, int len, char c)
{
	char *res;

	res = ft_strnew(len);
	if (num == 0)
		res[0] = '0';
	while (len-- > 0)
	{
			if (num % base >= 10)
				res[len] = c + num % base - 10;
			else
				res[len] = '0' + num % base;
			num = num / base;
	}
	return (res);
}

char	*ft_llitoa_base(long long int value, int base)
{
	unsigned long long int	res;
	unsigned int	len;
	unsigned long long int	b;
	char			*final;

	if (base < 2 || base > 16)
		return (0);
	res = (unsigned long long int)value;
	b = (unsigned long long int)base;
	len = ft_getunsig_len(res, base);
	final = (char*)malloc(sizeof(char*) * (len + 1));
	if (!final)
		return (0);
	if (res == 0)
		final[0] = '0';
	final[len] = '\0';
	while (res != 0)
	{
		len--;
		if (base >= 10 && res % b >= 10)
			final[len] = res % b - 10 + 'a';
		else
			final[len] = res % b + '0';
		res = res / b;
	}
	return (final);
}
