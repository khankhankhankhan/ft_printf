/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:44:07 by hkang             #+#    #+#             */
/*   Updated: 2017/11/16 18:44:32 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_wch(va_list *ap, int *flag)
{
	wchar_t	num;
	char		*str;
	int			len;
	int			l;

	l = 0;
	num = va_arg(*ap, wchar_t);
	str = ft_wchartostr(num);
	len = ft_strlen(str);
	if (len == 0)
		len++;
	if (flag[3] == 0 && flag[4] == 1)
		repeat_print_width(flag, len, '0', &l);
	if (flag[3] == 0 && flag[4] == 0)
		repeat_print_width(flag, len, ' ', &l);
	write(1, str, len);
	l = l + len;
	if (flag[3] == 1)
	 	repeat_print_width(flag, len, ' ', &l);
	free(str);
	return (l);
}

int		ft_print_ch(va_list *ap, int *flag, char c)
{
	int num;
	int l;

	l = 0;
	if (flag[10] == 1 || c == 'C')
		return (ft_print_wch(ap, flag));
	num = va_arg(*ap, int);
	if (flag[3] == 0)
	{
		if (flag[4] == 1)
			repeat_print_width(flag, 1, '0', &l);
		else
			repeat_print_width(flag, 1, ' ', &l);
	}
	write(1, &num, 1);
	l++;
	if (flag[3] == 1)
		repeat_print_width(flag, 1, ' ', &l);
	return (l);
}
