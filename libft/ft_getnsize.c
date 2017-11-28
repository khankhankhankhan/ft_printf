/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 19:27:03 by hkang             #+#    #+#             */
/*   Updated: 2017/09/27 21:51:21 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_getnsize(int n)
{
	int limit;
	int size;

	limit = 1;
	size = 1;
	while (n / limit != 0 && limit < 1000000000)
	{
		limit = limit * 10;
		size++;
	}
	if (n / limit != 0)
		size++;
	if (n > 0)
		size--;
	return (size);
}
