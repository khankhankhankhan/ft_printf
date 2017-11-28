/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 11:30:02 by hkang             #+#    #+#             */
/*   Updated: 2017/09/25 11:31:34 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		ch;
	char	*save;

	save = 0;
	ch = c;
	if (ch == 0)
		return ((char*)(s + ft_strlen(s)));
	while (*s)
	{
		if (ch == *s)
			save = (char*)s;
		s++;
	}
	return (save);
}
