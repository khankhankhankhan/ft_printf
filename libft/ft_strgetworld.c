/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgetworld.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 10:05:00 by hkang             #+#    #+#             */
/*   Updated: 2017/09/28 10:05:03 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strgetworld(char const *s, char **res, size_t size, char c)
{
	size_t		i;
	char const	*t;

	i = 0;
	while (i < size)
	{
		while (*s == c)
			s++;
		t = s;
		while (*s != c && *s)
			s++;
		res[i] = ft_strsub(t, 0, (s - t));
		i++;
	}
	res[i] = 0;
	return (res);
}
