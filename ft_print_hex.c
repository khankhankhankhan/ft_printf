/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:25:25 by hkang             #+#    #+#             */
/*   Updated: 2017/11/10 14:24:00 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char  *get_hex(va_list *ap, int *flag, char s, int *l)
{
	uintmax_t num;
	unsigned int len;
	char *res;

	num = getnum_unsig(ap, flag);
	len = ft_getunsig_len(num, 16);
	res = ft_itoa_base((uintmax_t)num, 16, len, s - 23);
	if (flag[15] == 1 && flag[6] == 0 && num == 0)
		res[0] = '\0';
	*l = ft_strlen(res);
	if (*l != 0 && num == 0)
	{
			write(1, "0", 1);
			return (NULL);
	}
	if (flag[5] == 0 && flag[6] == 0 && num == 0 && *l == 0)
			return (NULL);
	return (res);
}

void  ft_print_hex_per(char s, int *l)
{
	write(1, "0", 1);
	write(1, &s, 1);
	*l = *l + 2;
}

int		ft_print_hex(va_list *ap, int *flag, char s)
{

	char *res;
	int l;

	res = get_hex(ap, flag, s, &l);
	if (!res)
		return (l);
	if (flag[0] == 1)
		flag[5] = flag[5] - 2;
	if (flag[0] == 1 && flag[4] == 0 && flag[3] == 0)
		repeat_print_width(flag, (int)ft_strlen(res), ' ', &l);
	if (flag[0] == 1)
		ft_print_hex_per(s, &l);
	if (flag[0] == 0 && flag[4] == 0 && flag[3] == 0)
		repeat_print_width(flag, (int)ft_strlen(res), ' ', &l);
	if (flag[4] == 1 && flag[3] == 0)
		repeat_print_width(flag, (int)ft_strlen(res), '0', &l);
	if (flag[4] == 0 && flag[3] == 0)
		repeat_print_prec(flag, (int)ft_strlen(res), '0', &l);
	write(1, res, ft_strlen(res));
	repeat_print_width(flag, (int)ft_strlen(res), ' ', &l);
	free(res);
	return (l);
}
