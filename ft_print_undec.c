/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_undec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:07:39 by hkang             #+#    #+#             */
/*   Updated: 2017/11/13 13:07:44 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char  *get_undec(va_list *ap, int *flag, char s, int *l)
{
	uintmax_t num;
	unsigned int len;
	char *res;

	if (s == 'U')
		flag[10] = 1;
	num = getnum_unsig(ap, flag);
	len = ft_getunsig_len(num, 10);
	res = ft_itoa_base((uintmax_t)num, 10, len, '0');
	if (flag[15] == 1 && flag[6] == 0 && num == 0)
		res[0] = '\0';
	*l = ft_strlen(res);
	return (res);
}

int		ft_print_undec(va_list *ap, int *flag, char s)
{
	char *res;
	int l;

	res = get_undec(ap, flag, s, &l);
	if (flag[3] == 1)
	{
		repeat_print_prec(flag, (int)ft_strlen(res), '0', &l);
		write(1, res, ft_strlen(res));
		repeat_print_width(flag, (int)ft_strlen(res), ' ', &l);
	}
	if (flag[6] < (int)ft_strlen(res))
		flag[6] = (int)ft_strlen(res);
	if (flag[3] == 0)
	{
		if (flag[4] == 1)
			repeat_print_width(flag, flag[6], '0', &l);
		else if (flag[4] == 0)
			repeat_print_width(flag, flag[6], ' ', &l);
		repeat_print_prec(flag, (int)ft_strlen(res), '0', &l);
		write(1, res, ft_strlen(res));
	}
	free(res);
	return (l);
}
