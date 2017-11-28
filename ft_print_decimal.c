/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 20:10:46 by hkang             #+#    #+#             */
/*   Updated: 2017/11/10 20:10:49 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_int(va_list *ap, int *flag, char s, int *f)
{
	intmax_t num;
	unsigned int len;
	char		*res;

	*f = 1;
	if (s == 'D')
		flag[10] = 1;
	num = getnum_sig(ap, flag);
	len = ft_getsig_len(num);
	res = ft_strnew(len);
	if (num == 0)
		res[0] = '0';
	if (flag[15] == 1 && flag[6] == 0 && num == 0)
		res[0] = '\0';
	if (num < 0)
	{
		res[0] = '-';
		*f = -1;
	}
	while (num != 0 && len-- > 0)
	{
		res[len] = '0' + num % 10 * (*f);
		num = num / 10;
	}
	return (res);
}

void  repeat_print_width(int *flag, int std, char c, int *len)
{
		while (flag[5] > std && flag[5] > flag[6])
		{
			write(1, &c, 1);
			flag[5]--;
			(*len)++;
		}
}

char    *get_int_sig(int *flag, int f, int *l)
{
	char *temp;

	temp = ft_strnew(1);
	if (flag[1] == 1 && f == 1)
	{
		temp[0] = '+';
		flag[5]--;
		(*l)++;
	}
	if (f == -1)
	{
		temp[0] = '-';
		flag[5]--;
	}
	return (temp);
}

void  repeat_print_prec(int *flag, int std, char c, int *len)
{
		while (flag[6] > std)
		{
			write(1, &c, 1);
			flag[5]--;
			flag[6]--;
			(*len)++;
		}
}

int		ft_print_decimal(va_list *ap, int *flag, char s)
{
	char		*res;
	int f;
	int l;

	res = get_int(ap, flag, s, &f);
	l = ft_strlen(res);
	if (flag[2] == 1 && flag[1] == 0 && f == 1)
	{
		write(1, " ", 1);
		flag[5]--;
		l++;
	}
	if (flag[3] == 1)
	{
		if (flag[1] == 1 && f == 1)
			repeat_print_width(flag, flag[5] - 1, '+', &l);
		repeat_print_prec(flag, (int)ft_strlen(res), '0', &l);
		write(1, res, ft_strlen(res));
		repeat_print_width(flag, (int)ft_strlen(res), ' ', &l);
	}
	else if (flag[3] == 0)
		ft_print_dec_right(res, flag, f, &l);
	free(res);
	return (l);
}

void		ft_print_dec_right(char *res, int *flag, int f, int *l)
{
		char *temp;

		temp = get_int_sig(flag, f, l);
		if (f == -1)
			res++;
		if (flag[4] == 1 && flag[6] == 0)
		{
			write(1, temp, ft_strlen(temp));
			if (flag[15] == 0)
				repeat_print_width(flag, (int)ft_strlen(res), '0', l);
			else
				repeat_print_width(flag, (int)ft_strlen(res), ' ', l);
		}
		else if (flag[4] == 0 || flag[6] != 0)
		{
			repeat_print_width(flag, (int)ft_strlen(res), ' ', l);
      write(1, temp, ft_strlen(temp));
		}
		repeat_print_prec(flag, (int)ft_strlen(res), '0', l);
		write(1, res, ft_strlen(res));
	free(temp);
}
