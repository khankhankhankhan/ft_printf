/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:47:38 by hkang             #+#    #+#             */
/*   Updated: 2017/11/16 18:48:10 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_wchartostr(wchar_t const wc)
{
	char *conv;

	conv = ft_strnew(5);
	if (wc <= 0x7F)
		conv[0] = (char)wc;
	else if (wc <= 0x7FF)
	{
		conv[0] = (wc >> 6) + 0xC0;
		conv[1] = (wc & 0x3F) + 0x80;
	}
	else if (wc <= 0xFFFF)
	{
		conv[0] = (wc >> 12) + 0xE0;
		conv[1] = ((wc >> 6) & 0x3F) + 0x80;
		conv[2] = (wc & 0x3F) + 0x80;
	}
	else if (wc <= 0x10FFFF)
	{
		conv[0] = (wc >> 18) + 0xF0;
		conv[1] = ((wc >> 12) & 0x3F) + 0x80;
		conv[2] = ((wc >> 6) & 0x3F) + 0x80;
		conv[3] = (wc & 0x3F) + 0x80;
	}
	return (conv);
}

void ft_wstrtostr_preci(int *flag, wchar_t const *src)
{
	size_t	i;
	size_t	last;

	i = 0;
	last = 0;
	while (*src && (i <= (size_t)flag[6]))
	{
		last = i;
		if (*src <= 0x7F)
			i++;
		else if (*src <= 0x7FF)
			i += 2;
		else if (*src <= 0xFFFF)
			i += 3;
		else if (*src <= 0x10FFFF)
			i += 4;
		if (*src)
			src++;
	}
	flag[6] = (i <= (size_t)flag[6]) ? i : last;
}

char	*ft_wstrtostr(wchar_t const *src)
{
	char *str;
	char *prev;
	char *next;

	if (!(str = ft_strnew(1)))
		return ((char *)NULL);
	while (*src)
	{
		prev = str;
		if (!(next = ft_wchartostr(*src)))
			return ((char *)NULL);
		if (!(str = ft_strjoin(prev, next)))
			return ((char *)NULL);
		if (*src)
			src++;
		ft_strdel(&prev);
		ft_strdel(&next);
	}
	return (str);
}

char		*ft_print_wstr(va_list *ap, int *flag)
{
	wchar_t	*s;
	char *str;
	s = va_arg(*ap, wchar_t*);
	if (!s)
		return (0);
	str = ft_wstrtostr(s);
	if (flag[15] == 1 || flag[6] > 0)
	{
		ft_wstrtostr_preci(flag, s);
		str = ft_strsub(str, 0, flag[6]);
	}
	return (str);
}

/*char		*ft_print_str_null(int *f)
{
	char *s;

	s = ft_strnew(6);
	s[0] = '(';
	s[1] = 'n';
	s[2] = 'u';
	s[3] = 'l';
	s[4] = 'l';
	s[5] = ')';
	return (s);
}*/

int		ft_print_s(va_list *ap, int *flag, char c)
{
	char *s;
	int l;
	int f;

	l = 0;
	f = 0;
	if (flag[10] == 1 || c == 'S')
		s = ft_print_wstr(ap, flag);
	else
		s = va_arg(*ap, char*);
	if (!s)
		//s = ft_print_str_null();
	{
		s = "(null)";
		f = 1;
	}
	if (flag[15] == 0 || flag[6] >= (int)ft_strlen(s))
		flag[6] = (int)ft_strlen(s);
	if (flag[3] == 0 && flag[4] == 1)
		repeat_print_width(flag, flag[6], '0', &l);
	else if (flag[3] == 0 && flag[4] == 0)
		repeat_print_width(flag, flag[6], ' ', &l);
	write(1, s, flag[6]);
	l = l + flag[6];
	if (flag[3] == 1)
		repeat_print_width(flag, l, ' ', &l);
	//ft_bzero(s, ft_strlen(s));
	if ((flag[10] == 1 || c == 'S') && !f)
		free(s);
	return (l);
}
