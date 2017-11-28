/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 18:53:40 by hkang             #+#    #+#             */
/*   Updated: 2017/09/27 22:14:12 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int		limit;
	int		flag;
	char	c;

	flag = 1;
	limit = 1000000000;
	while (n / limit == 0 && limit > 1)
		limit = limit / 10;
	if (n < 0)
	{
		flag = -1;
		write(1, "-", 1);
	}
	while (limit > 0)
	{
		c = 48 + n / limit * flag;
		write(1, &c, 1);
		n = n % limit;
		limit = limit / 10;
	}
}
