/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 14:53:26 by bhamdi            #+#    #+#             */
/*   Updated: 2018/10/17 09:11:08 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	stock_exe(t_data *data, char *txt, int len)
{
	int i;

	i = 0;
	while (len--)
		data->exe[data->i++] = txt[i++];
}

void	filling(char *exe, t_data *data, t_option *flag)
{
	int len;
	int n;

	flag->sign < 0 ? (n = 1 && (flag->sign *= -1)) : (n = 0);
	(flag->speci == 's' && exe == 0) ? ((exe = "(null)") && (len = 5)) : 0;
	(len = ft_strlen(exe)) > flag->preci ? len = flag->preci : 0;
	(flag->speci == 's' && flag->preci >= 0) ? flag->sign -= len : 
		(flag->sign -= (len = ft_strlen(exe)));
	(flag->speci == 'c' && (exe[0] == 0 && exe[1] == 0)) ? flag->sign-- : 0;
	while (!n && flag->sign-- > 0)
	{
		if (flag->speci == '%')
			(flag->preci > 0 || flag->zero) ? (stock(data, "0", 1)) : 
				(stock(data, " ", 1));
		else
			stock(data, " ", 1);
	}
	stock(data, exe, len);
	while (n && flag->sign-- > 0 && (stock(data, " ", 1)));
}

char	*filling_i(int exe, t_data *data, t_option *flag)
{
	int n;
	int p;
	int len;

	(data->i = 0) ? ft_memset(data->exe, (int)"\0", data->i) : 0;
	exe < 0 ? (n = 1 && (exe *= -1)) : (n = 0);
	exe == 0 && (flag->preci == 0) ? (len = 0) : (len = ft_intlen(exe));
	flag->sign < 0 ? (p = 1 && (flag->sign *= -1)) : (p = 0);
	flag->space && (!flag->plus && !n) ? (data->exe[data->i++] = ' ') : 0;
	if (!p && ((flag->sign -= (data->i + len + n + flag->plus + (flag->preci >\
				len ? flag->preci - len : 0)))) > 0)
	{
		while (!flag->zero && flag->sign-- && (data->exe[data->i++] = ' '));
		(flag->zero && n) ? (data->exe[data->i++] = '-') : 0;
		while (flag->zero && flag->sign-- && (flag->plus ?\
				(data->exe[data->i++] = ' ') : (data->exe[data->i++] = '0')));
	}
	else if (flag->zero && n)
		data->exe[data->i++] = '-';
	flag->plus == 1 && !n ? (data->exe[data->i++] = '+') : 0;
	!flag->zero && n ? (data->exe[data->i++] = '-') : 0;
	if ((flag->preci -= (len + n)) > 0)
		while (n ? ((data->exe[data->i++] = '0') && flag->preci--) :
				(flag->preci-- && (data->exe[data->i++] = '0')));
	stock_exe(data, ft_lltoa(exe), len);
	if (p && (flag->sign -= data->i) > 0)
		while (flag->sign-- && (data->exe[data->i++] = ' '));
	
	return (data->exe);
}

char	*filling_l(long exe, t_data *data, t_option *flag)
{
	int n;
	int p;
	int len;

	(data->i = 0) ? ft_memset(data->exe, (int)"\0", data->i) : 0;
	exe < 0 ? (n = 1 && (exe *= -1)) : (n = 0);
	exe == 0 && (flag->preci == 0) ? (len = 0) : (len = ft_intlen(exe));
	flag->sign < 0 ? (p = 1 && (flag->sign *= -1)) : (p = 0);
	flag->space && (!flag->plus && !n) ? (data->exe[data->i++] = ' ') : 0;
	if (!p && ((flag->sign -= (data->i + len + n + flag->plus + (flag->preci >\
				len ? flag->preci - len : 0)))) > 0)
	{
		while (!flag->zero && flag->sign-- && (data->exe[data->i++] = ' '));
		(flag->zero && n) ? (data->exe[data->i++] = '-') : 0;
		while (flag->zero && flag->sign-- && (flag->plus ?\
				(data->exe[data->i++] = ' ') : (data->exe[data->i++] = '0')));
	}
	else if (flag->zero  && n)
		data->exe[data->i++] = '-';
	flag->plus == 1 && !n ? (data->exe[data->i++] = '+') : 0;
	!flag->zero && n ? (data->exe[data->i++] = '-') : 0;
	if ((flag->preci -= (len + n)) > 0)
		while (n ? ((data->exe[data->i++] = '0') && flag->preci--) :
				(flag->preci-- && (data->exe[data->i++] = '0')));
	stock_exe(data, ft_lltoa(exe), len);
	if (p && (flag->sign -= data->i) > 0)
		while (flag->sign-- && (data->exe[data->i++] = ' '));
	
	return (data->exe);
}

char	*filling_ll(long long exe, t_data *data, t_option *flag)
{
	int n;
	int p;
	int len;

	(data->i = 0) ? ft_memset(data->exe, (int)"\0", data->i) : 0;
	exe < 0 ? (n = 1 && (exe *= -1)) : (n = 0);
	exe == 0 && (flag->preci == 0) ? (len = 0) : (len = ft_intlen(exe));
	flag->sign < 0 ? (p = 1 && (flag->sign *= -1)) : (p = 0);
	flag->space && (!flag->plus && !n) ? (data->exe[data->i++] = ' ') : 0;
	if (!p && ((flag->sign -= (data->i + len + n + flag->plus + (flag->preci >\
				len ? flag->preci - len : 0)))) > 0)
	{
		while (!flag->zero && flag->sign-- && (data->exe[data->i++] = ' '));
		(flag->zero && n) ? (data->exe[data->i++] = '-') : 0;
		while (flag->zero && flag->sign-- && (flag->plus ?\
				(data->exe[data->i++] = ' ') : (data->exe[data->i++] = '0')));
	}
	else if (flag->zero  && n)
		data->exe[data->i++] = '-';
	flag->plus == 1 && !n ? (data->exe[data->i++] = '+') : 0;
	!flag->zero && n ? (data->exe[data->i++] = '-') : 0;
	if ((flag->preci -= (len + n)) > 0)
		while (n ? ((data->exe[data->i++] = '0') && flag->preci--) :
				(flag->preci-- && (data->exe[data->i++] = '0')));
	stock_exe(data, ft_lltoa(exe), len);
	if (p && (flag->sign -= data->i) > 0)
		while (flag->sign-- && (data->exe[data->i++] = ' '));
	
	return (data->exe);
}

char	*filling_im(intmax_t exe, t_data *data, t_option *flag)
{
	int n;
	int p;
	int len;

	(data->i = 0) ? ft_memset(data->exe, (int)"\0", data->i) : 0;
	exe < 0 ? (n = 1 && (exe *= -1)) : (n = 0);
	exe == 0 && (flag->preci == 0) ? (len = 0) : (len = ft_intlen(exe));
	flag->sign < 0 ? (p = 1 && (flag->sign *= -1)) : (p = 0);
	flag->space && (!flag->plus && !n) ? (data->exe[data->i++] = ' ') : 0;
	if (!p && ((flag->sign -= (data->i + len + n + flag->plus + (flag->preci >\
				len ? flag->preci - len : 0)))) > 0)
	{
		while (!flag->zero && flag->sign-- && (data->exe[data->i++] = ' '));
		(flag->zero && n) ? (data->exe[data->i++] = '-') : 0;
		while (flag->zero && flag->sign-- && (flag->plus ?\
				(data->exe[data->i++] = ' ') : (data->exe[data->i++] = '0')));
	}
	else if (flag->zero  && n)
		data->exe[data->i++] = '-';
	flag->plus == 1 && !n ? (data->exe[data->i++] = '+') : 0;
	!flag->zero && n ? (data->exe[data->i++] = '-') : 0;
	if ((flag->preci -= (len + n)) > 0)
		while (n ? ((data->exe[data->i++] = '0') && flag->preci--) :
				(flag->preci-- && (data->exe[data->i++] = '0')));
	stock_exe(data, ft_lltoa(exe), len);
	if (p && (flag->sign -= data->i) > 0)
		while (flag->sign-- && (data->exe[data->i++] = ' '));
	
	return (data->exe);
}

char	*filling_uint(unsigned int exe, t_data *data, t_option *flag)
{
	int p;
	int len;
	
	(data->i = 0) ? ft_memset(data->exe, (int)"\0", data->i) : 0;
	exe == 0 && (flag->preci == 0) ? (len = 0) : (len = ft_intlen(exe));
	flag->sign < 0 ? (p = 1 && (flag->sign *= -1)) : (p = 0);
	flag->space ? (data->exe[data->i++] = ' ') : 0;
	if (!p && ((flag->sign -= (data->i + len + (flag->preci >\
				len ? flag->preci - len : 0)))) > 0)
	{
		while (!flag->zero && flag->sign-- && (data->exe[data->i++] = ' '));
		while (flag->zero && flag->sign-- && ((flag->preci == -1) ? (data->exe
					[data->i++] = '0') : (data->exe[data->i++] = ' ')));
	}
	if ((flag->preci -= len) > 0)
		while (1 ? ((data->exe[data->i++] = '0') && --flag->preci) :
				(flag->preci-- && (data->exe[data->i++] = '0')));
	stock_exe(data, ft_ulltoa(exe),len);
	if (p && (flag->sign -= data->i) > 0)
		while (flag->sign-- && (data->exe[data->i++] = ' '));

	return (data->exe);
}

char	*filling_ul(unsigned long exe, t_data *data, t_option *flag)
{
	int p;
	int len;

	(data->i = 0) ? ft_memset(data->exe, (int)"\0", data->i) : 0;
	exe == 0 && (flag->preci == 0) ? (len = 0) : (len = ft_intlen(exe));
	flag->sign < 0 ? (p = 1 && (flag->sign *= -1)) : (p = 0);
	flag->space && !flag->plus ? (data->exe[data->i++] = ' ') : 0;
	if (!p && ((flag->sign -= (data->i + len + flag->plus + (flag->preci >\
				len ? flag->preci - len : 0)))) > 0)
	{
		while (!flag->zero && flag->sign-- && (data->exe[data->i++] = ' '));
		while (flag->zero && flag->sign-- && (flag->plus ? (data->exe[data->i++]
					   = ' ') : (data->exe[data->i++] = '0')));
	}
	flag->plus == 1 ? (data->exe[data->i++] = '+') : 0;
	if ((flag->preci -= len) > 0)
		while (1 ? ((data->exe[data->i++] = '0') && --flag->preci) :
				(flag->preci-- && (data->exe[data->i++] = '0')));
	stock_exe(data, ft_ulltoa(exe), len);
	if (p && (flag->sign -= data->i) > 0)
		while (flag->sign-- && (data->exe[data->i++] = ' '));

	return (data->exe);
}

char	*filling_ull(unsigned long long exe, t_data *data, t_option *flag)
{
	int p;
	int len;

	(data->i = 0) ? ft_memset(data->exe, (int)"\0", data->i) : 0;
	exe == 0 && (flag->preci == 0) ? (len = 0) : (len = ft_intlen(exe));
	flag->sign < 0 ? (p = 1 && (flag->sign *= -1)) : (p = 0);
	flag->space && !flag->plus ? (data->exe[data->i++] = ' ') : 0;
	if (!p && ((flag->sign -= (data->i + len + flag->plus + (flag->preci >\
				len ? flag->preci - len : 0)))) > 0)
	{
		while (!flag->zero && flag->sign-- && (data->exe[data->i++] = ' '));
		while (flag->zero && flag->sign-- && (flag->plus ? (data->exe[data->i++]
					   = ' ') : (data->exe[data->i++] = '0')));
	}
	flag->plus == 1 ? (data->exe[data->i++] = '+') : 0;
	if ((flag->preci -= len) > 0)
		while (1 ? ((data->exe[data->i++] = '0') && --flag->preci) :
				(flag->preci-- && (data->exe[data->i++] = '0')));
	stock_exe(data, ft_ulltoa(exe), ft_intlen(ft_atoi(ft_ulltoa(exe))));
	if (p && (flag->sign -= data->i) > 0)
		while (flag->sign-- && (data->exe[data->i++] = ' '));

	return (data->exe);
}
