/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:25:25 by hkang             #+#    #+#             */
/*   Updated: 2017/11/10 13:47:16 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char  *get_octal(va_list *ap, int *flag, char s, int *l)
{
	uintmax_t num;
	unsigned int len;
	char *res;

	if (s == 'O')
		flag[10] = 1;
	num = getnum_unsig(ap, flag);
	len = ft_getunsig_len(num, 8);
	res = ft_itoa_base((uintmax_t)num, 8, len, '0');
	if (flag[15] == 1 && flag[6] == 0 && num == 0)
		res[0] = '\0';
	*l = ft_strlen(res);
	if (flag[0] == 1 && !(flag[15] == 0 && num == 0))
	{
		flag[5]--;
		(*l)++;
	}
	if (flag[0] == 1 && flag[6] > (int)ft_strlen(res))
		flag[6]--;
	if (flag[4] == 0 && flag[3] == 0)
		repeat_print_width(flag, (int)ft_strlen(res), ' ', l);
	if (!(flag[15] == 0 && num == 0) && flag[0] == 1)
		 write(1, "0", 1);
	return (res);
}


int		ft_print_octal(va_list *ap, int *flag, char s)
{
	char *res;
	int l;


	res = get_octal(ap, flag, s, &l);
	if (flag[3] == 1 || flag[4] == 0)
		repeat_print_prec(flag, (int)ft_strlen(res), '0', &l);
	if (flag[3] == 0 && flag[4] == 1)
		repeat_print_width(flag, (int)ft_strlen(res), '0', &l);
	write(1, res, ft_strlen(res));
	repeat_print_width(flag, (int)ft_strlen(res), ' ', &l);

	free(res);
	return (l);
}
