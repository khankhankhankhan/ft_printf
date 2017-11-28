/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 11:32:15 by hkang             #+#    #+#             */
/*   Updated: 2017/09/25 11:33:01 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int						res;

	res = (unsigned char)*s1 - (unsigned char)*s2;
	while (*s1 && *s2 && res == 0)
	{
		res = (unsigned char)*s1 - (unsigned char)*s2;
		s1++;
		s2++;
	}
	if (res != 0)
		return (res);
	res = (unsigned char)*s1 - (unsigned char)*s2;
	return (res);
}
