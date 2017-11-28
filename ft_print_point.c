/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:42:35 by hkang             #+#    #+#             */
/*   Updated: 2017/11/16 18:42:38 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_point(va_list *ap, int *flag)
{
	unsigned long long int add;
	char *res;
	int len;
	int l;

	add = va_arg(*ap, unsigned long long int);
	res = ft_llitoa_base(add, 16);
	if (add == 0 && flag[15] == 1 && flag[6] == 0)
		res[0] = '\0';
	len = ft_strlen(res);
	l = len + 2;
	flag[5] = flag[5] - 2;
	if (flag[3] == 0 && flag[4] == 0)
		repeat_print_width(flag, (int)ft_strlen(res), ' ', &l);
	write(1, "0x", 2);
	if (flag[3] == 0 && flag[4] == 1)
		repeat_print_width(flag, (int)ft_strlen(res), '0', &l);
	else if ((flag[3] == 0 && flag[4] == 0) || flag[3] == 1)
		repeat_print_prec(flag, (int)ft_strlen(res), '0', &l);
	write(1, res, len);
	flag[5] = flag[5] - len + 1;
	repeat_print_width(flag, (int)ft_strlen(res), ' ', &l);
	free(res);
	return (l);
}
