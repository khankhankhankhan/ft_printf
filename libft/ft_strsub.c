/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 21:58:19 by hkang             #+#    #+#             */
/*   Updated: 2017/09/27 22:02:06 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *res;

	if (!s)
		return (0);
	res = ft_strnew(len);
	if (!res)
		return (0);
	if (len == 0)
		return (res);
	res = ft_strncpy(res, (s + start), len);
	return (res);
}
