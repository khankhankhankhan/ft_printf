/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 11:33:32 by hkang             #+#    #+#             */
/*   Updated: 2017/09/25 13:17:49 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *src)
{
	int flag;
	int res;

	flag = 1;
	res = 0;
	while ((*src == ' ' || *src == '\t' || *src == '\n' ||
			*src == '\v' || *src == '\f' || *src == '\r'))
		src++;
	if (*src == '-')
	{
		flag = -1;
		src++;
	}
	else if (*src == '+')
		src++;
	while (*src && *src >= '0' && *src <= '9')
	{
		res = res * 10 + flag * (*src - 48);
		src++;
	}
	return (res);
}
