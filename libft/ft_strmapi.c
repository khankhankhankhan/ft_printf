/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 21:43:49 by hkang             #+#    #+#             */
/*   Updated: 2017/09/27 22:08:02 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			*(res + i) = f(i, *(s + i));
			i++;
		}
	}
	return (res);
}
