/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 14:12:24 by hkang             #+#    #+#             */
/*   Updated: 2017/09/27 22:15:48 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**res;
	size_t	size;
	size_t	i;

	size = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
			size++;
		i++;
	}
	res = (char**)ft_memalloc((sizeof(res) * size) + 1);
	if (!res)
		return (0);
	i = 0;
	res = ft_strgetworld(s, res, size, c);
	return (res);
}
