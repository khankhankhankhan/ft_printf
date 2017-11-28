/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 14:27:36 by hkang             #+#    #+#             */
/*   Updated: 2017/11/10 13:40:55 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
int		arg_process(va_list *ap, const char *format);
int 	ft_select(va_list *ap, const char *format, int *flag);
char	*ft_llitoa_base(long long int value, int base);

unsigned int	ft_getunsig_len(unsigned long long int value, int base);
unsigned int	ft_getsig_len(long long int value);
unsigned int	ft_getdouble_len(long double value,long double *limit);

const char	*get_flag(const char *format, int *flag, va_list *ap);
const char	*get_modify(const char *format, int *flag);
const char	*get_sig(const char *format, int *flag);
const char	*get_width(const char *format, int *flag, va_list *ap);

char	*ft_wchartostr(wchar_t const wc);
void ft_wstrtostr_preci(int *flag, wchar_t const *src);

int 	ft_print_s(va_list *ap, int *flag,char c);
int 	ft_print_base(va_list *ap, int base);
int 	   ft_print_decimal(va_list *ap, int *flag, char s);
void    ft_print_dec_right(char *res, int *flag, int f, int *l);
int 	ft_print_ch(va_list *ap, int *flag, char c);
int 	ft_print_octal(va_list *ap, int *flag, char s);
int 	ft_print_hex(va_list *ap, int *flag, char s);
int 	ft_print_nosignal(int *flag,const char *format);
int 	ft_print_point(va_list *ap, int *flag);
int		ft_print_undec(va_list *ap, int *flag, char s);
int		ft_print_float(va_list *ap, int *flag, char s);

char	*ft_itoa_base(uintmax_t num, uintmax_t base, int len, char c);
intmax_t	getnum_sig(va_list *ap, int *flag);
uintmax_t	getnum_unsig(va_list *ap, int *flag);

char	*get_int(va_list *ap, int *flag, char s, int *f);
char  *get_hex(va_list *ap, int *flag, char s, int *l);
char    *get_int_sig(int *flag, int f, int *l);


void  repeat_print_width(int *flag, int std, char c, int *len);
void  repeat_print_prec(int *flag, int std, char c, int *len);
#endif
