/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 19:08:36 by hkang             #+#    #+#             */
/*   Updated: 2017/11/10 13:44:35 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	getnum_sig(va_list *ap, int *flag)
{
	intmax_t n;

	if (flag[9] == 1)
		n = va_arg(*ap, long long int);
	else if (flag[10] == 1)
		n = va_arg(*ap, long int);
	else if (flag[11] == 1)
		n = va_arg(*ap, intmax_t);
	else if (flag[13] == 1)
		n = va_arg(*ap, ssize_t);
	else if (flag[7] == 1)
	{
		n = va_arg(*ap, int);
		n = (char)n;
	}
	else if (flag[8] == 1)
	{
		n = va_arg(*ap, int);
		n = (short)n;
	}
	else
		n = va_arg(*ap, int);
	return (n);
}

uintmax_t	getnum_unsig(va_list *ap, int *flag)
{
	uintmax_t n;
	if (flag[9] == 1)
		n = va_arg(*ap, unsigned long long int);
	else if (flag[10] == 1)
		n = va_arg(*ap, unsigned long int);
	else if (flag[11] == 1)
		n = va_arg(*ap, uintmax_t);
	else if (flag[13] == 1)
		n = va_arg(*ap, size_t);
	else if (flag[7] == 1)
	{
		n = va_arg(*ap, unsigned int);
		n = (unsigned char)n;
	}
	else if (flag[8] == 1)
	{
		n = va_arg(*ap, unsigned int);
		n = (unsigned short)n;
	}
	else
		n = va_arg(*ap, unsigned int);
	return (n);
}


int	ft_print_nosignal(int *flag, const char *format)
{
	int len;

	if (!(*format))
		return (0);
	len = 1;
	if (flag[3] == 1)
	{
		write(1, format, 1);
		flag[5]--;
		while (flag[5] > 0)
		{
			write(1, " ", 1);
			flag[5]--;
			len++;
		}
	}
	else if (flag[3] == 0)
	{
		while (flag[5] > 1)
		{
			if (flag[4] == 1)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			flag[5]--;
			len++;
		}
		write(1, format, 1);
	}
	return (len);
}
