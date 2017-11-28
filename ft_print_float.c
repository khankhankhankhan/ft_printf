/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:01:04 by hkang             #+#    #+#             */
/*   Updated: 2017/11/20 17:01:07 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int   get_float_bit(long double num, long double limit)
{
  long double temp;
  int i;

  temp = num / limit;
  //printf ("num = %Lf, limit = %Lf, temp = %Lf\n", num, limit, temp);
  i = 1;
  while (i < 10)
  {
    if (temp < i)
      return (i - 1);
    i++;
  }
  return (9);
  /*if (temp < 1.0)
    return (0);
  else if (temp < 2.0)
    return (1);
  else if (temp < 3.0)
    return (2);
  else if (temp < 4.0)
    return (3);
  else if (temp < 5.0)
    return (4);
  else if (temp < 6.0)
    return (5);
  else if (temp < 7.0)
    return (6);
  else if (temp < 8.0)
    return (7);
  else if (temp < 9.0)
    return (8);
  else
    return (9);

  if (temp >= 9.0)
    return (9);
  else if (temp >= 8.0)
    return (8);
  else if (temp >= 7.0)
    return (7);
  else if (temp >= 6.0)
    return (6);
  else if (temp >= 5.0)
    return (5);
  else if (temp >= 4.0)
    return (4);
  else if (temp >= 3.0)
    return (3);
  else if (temp >= 2.0)
    return (2);
  else if (temp >= 1.0)
    return (1);
  else
    return (0);*/
}

char  *get_float(va_list *ap, int *flag, char s, int *f)
{
	long double num;
  long double limit;
	unsigned int len;
	char *res;
  unsigned int i;
  int t;

  s = 'f';
	if (flag[10] == 1)
    num = va_arg(*ap, long double);
  else
    num = (long double)va_arg(*ap, double);
  //printf("s = %c, num = %Lf\n", s, num);
//  printf("llint num = %lld\n", (long long int)num);
	len = ft_getdouble_len(num, &limit);
//  printf("len = %d\n", len);
  if(flag[6] == 0)
    flag[6] = 6;
  res = ft_strnew(len + (unsigned int)flag[6] + 1);
  i = 0;
  if (num < 0.0)
  {
    *f = -1;
    res[0] = '-';
    i++;
  }
  res[len - 1] = '.';
  while (i < len + (unsigned int)flag[6] + 1)
  {
    if (i == len - 1)
      i++;
    t = get_float_bit((*f) * num, limit);
    //printf("num = %Lf, limit = %Lf, t = %d\n", num, limit,t);
    res[i] = t + '0';
    num = num - (*f) * limit * t;
    limit = limit / 10;
    //printf("num = %Lf, limit = %Lf, t = %d\n", num, limit,t);
    i++;
  }
  i--;
  if (res[i] < '5')
  {
    res[i] = '\0';
    return (res);
  }
  res[i] = '\0';
  i--;
  while (i > 0)
  {
    if (res[i] == '.')
      i--;
    if (res[i] == '9')
      res[i] = '0';
    else
    {
      res[i] = res[i] + 1;
      return (res);
    }
    i--;
  }
	return (res);
}

int		ft_print_float(va_list *ap, int *flag, char s)
{
  char		*res;
	int f;
	int l;

  f = 1;
	res = get_float(ap, flag, s, &f);
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

/*void		ft_print_dec_right(char *res, int *flag, int f, int *l)
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
}*/
