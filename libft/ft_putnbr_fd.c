/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 19:50:49 by hkang             #+#    #+#             */
/*   Updated: 2017/09/27 22:12:15 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
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
		write(fd, "-", 1);
	}
	while (limit > 0)
	{
		c = 48 + n / limit * flag;
		write(fd, &c, 1);
		n = n % limit;
		limit = limit / 10;
	}
}
