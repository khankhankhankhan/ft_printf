/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 22:28:40 by hkang             #+#    #+#             */
/*   Updated: 2017/09/28 14:10:02 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*res;
	size_t	start;
	size_t	len;

	if (!s)
		return (0);
	start = 0;
	len = ft_strlen(s);
	if (!len)
		return ((char*)s);
	len--;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	if (start > len)
		return (ft_strsub(s, 0, 0));
	while ((s[len] == ' ' || s[len] == '\n' || s[len] == '\t') && (len > start))
		len--;
	len = len - start + 1;
	res = ft_strsub(s, start, len);
	return (res);
}
