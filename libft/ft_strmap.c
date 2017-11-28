/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 21:34:22 by hkang             #+#    #+#             */
/*   Updated: 2017/09/27 22:11:04 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*res;

	i = 0;
	if (!s)
		return (0);
	res = ft_strnew(ft_strlen(s));
	if (res)
	{
		while (s[i])
		{
			*(res + i) = f(*(s + i));
			i++;
		}
	}
	return (res);
}
