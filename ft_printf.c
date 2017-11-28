/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 14:25:26 by hkang             #+#    #+#             */
/*   Updated: 2017/11/10 20:14:38 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, format);
	len = arg_process(&ap, format);
	va_end(ap);
	return (len);
}

int		arg_process(va_list *ap, const char *format)
{
	int		len;
	char	*start;
	int		i;
	int		j;
	int		flag[16];// for "#+ -0"and width, precision, hh, h, l, ll, j, t, z, q

	i = 0;
	start = (char*)format;
	len = 0;
	while (*format)
	{
		len++;
		if (*format == '%')
		{
			j = 0;
			while (j < 16)
			{
				flag[j] = 0;
				j++;
			}
			len--;
			write(1, start, i);
			format++;
			if (*format && ft_strchr("# 0+-123456789.*hljtzq", *format))
				format = get_flag(format, flag, ap);
			if (*format && ft_strchr("sSpdDioOuUxXcCfF", *format))
				len = len + ft_select(ap, format, flag);
			else
				len = len + ft_print_nosignal(flag, format);
			i = -1;
			if (*format)
				start = (char *)(format + 1);
		}
		i++;
		if (*format)
			format++;
	}
	write(1, start, i);
	return (len);
}

int		ft_select(va_list *ap, const char *format, int *flag)
{
	int len;
	len = 0;
	if (*format == 's' || *format == 'S')
		len = ft_print_s(ap, flag, *format);
	else if (*format == 'p')
		len = ft_print_point(ap, flag);
	else if (*format == 'd' || *format == 'D' || *format == 'i')
		len = ft_print_decimal(ap, flag, *format);
	else if (*format == 'o' || *format == 'O')
		len = ft_print_octal(ap, flag, *format);
	else if (*format == 'u' || *format == 'U')
		len = ft_print_undec(ap, flag, *format);
	else if (*format == 'x' || *format == 'X')
		len = ft_print_hex(ap, flag, *format);
	else if (*format == 'c' || *format == 'C')
		len = ft_print_ch(ap, flag, *format);
	else if (*format == 'f' || *format == 'F')
		len = ft_print_float(ap, flag, *format);
	return (len);
}

const char	*get_modify(const char *format, int *flag)
{
	while (*format && ft_strchr("hljtzq", *format))
	{
		if (*format == 'h' && flag[8] == 1)
			flag[7] = 1;
		else if(*format	== 'h')
			flag[8] = 1;
		else if(*format == 'l' && flag[10] == 1)
			flag[9] = 1;
		else if(*format == 'l')
			flag[10] = 1;
		else if(*format == 'j')
			flag[11] = 1;
		else if(*format == 't')
			flag[12] = 1;
		else if(*format == 'z')
			flag[13] = 1;
		else if(*format == 'q')
			flag[14] = 1;
		format++;
	}
	return (format);
}

const char	*get_sig(const char *format, int *flag)
{
	while (*format && ft_strchr("# 0+-", *format))
	{
		if (*format == '#')
			flag[0] = 1;
		else if (*format == '+')
			flag[1] = 1;
		else if (*format == ' ')
			flag[2] = 1;
		else if (*format == '-')
			flag[3] = 1;
		else if (*format == '0')
			flag[4] = 1;
		format++;
	}
	return(format);
}

const char	*get_width(const char *format, int *flag, va_list *ap)
{
	while (*format && ft_strchr(".0123456789*", *format))
	{
		if (*format == '.' || flag[15] == 1)
		{
			flag[15] = 1;
			format++;
			if (*format == '*')
			{
				flag[6] = va_arg(*ap, int);
				if (flag[6] < 0)
				{
					flag[6] = 0;
					flag[15] = 0;
				}
				format++;
			}
			else
			{
				flag[6] = ft_atoi(format);
				while (ft_isdigit(*format))
					format++;
			}
		}
		else if (ft_isdigit(*format))
		{
			flag[5] = ft_atoi(format);
			while (ft_isdigit(*format))
				format++;
		}
		else if (*format == '*')
		{
			flag[5] = va_arg(*ap, int);
			if (flag[5] < 0)
			{
				flag[5] = -flag[5];
				flag[3] = 1;
			}
			format++;
		}
	}
	return (format);
}

const char	*get_flag(const char *format, int *flag, va_list *ap)
{
	while (*format && ft_strchr("# 0+-hljtzq", *format))
	{
		format = get_sig(format, flag);
		format = get_modify(format, flag);
	}
	format = get_width(format, flag, ap);
	while (*format && ft_strchr("# 0+-hljtzq", *format))
	{
		format = get_sig(format, flag);
		format = get_modify(format, flag);
	}
	return (format);
}
