/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 22:11:13 by hkang             #+#    #+#             */
/*   Updated: 2017/09/27 22:08:59 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *res;

	if (!s1 || !s2)
		return (0);
	res = ft_strsub(s1, 0, (ft_strlen(s1) + ft_strlen(s2)));
	if (res)
		res = ft_strcat(res, s2);
	return (res);
}
