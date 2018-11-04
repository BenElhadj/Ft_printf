/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filling.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 14:53:26 by bhamdi            #+#    #+#             */
/*   Updated: 2018/11/04 08:02:30 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void    filling_utf8_c(wchar_t str, t_data *data, t_option *flag)
{
	int total;
	int to_copy;

	if (flag->speci == 'C')
	{
		to_copy = wcharc_len(str);
		total = (flag->width > to_copy) ? flag->width : to_copy;
		if (flag->sign > 0)
			w_to_charc(str, data);
		dataset(data, (flag->zero > 0 && flag->sign == 0) ? '0' :
				' ', total - to_copy);
		if (flag->sign <= 0)
			w_to_charc(str, data);
	}

}

void    filling_utf8_s(wchar_t *str, t_data *data, t_option *flag)
{
	int total;
	int to_copy;

	if (flag->speci == 'S')
	{
		to_copy = wcharc_len(str);
		total = (flag->width > to_copy) ? flag->width : to_copy;
		if (flag->sign > 0)
			w_to_charc(str, data);
		dataset(data, (flag->zero > 0 && flag->sign == 0) ? '0' :
				' ', total - to_copy);
		if (flag->sign <= 0)
			w_to_chars(str, data);
	}

}

void    filling(char *exe, t_data *data, t_option *flag)
{
	int len;
	int n;

	flag->sign > 0 ? flag->sign *= flag->neg : 0;
	flag->preci >= 0 ? flag->zero = 0 : 0;//****
	flag->sign < 0 ? (n = 1 && (flag->sign *= -1)) : (n = 0);
	(flag->speci == 's' && exe == 0) ? ((exe = "(null)") && (len = 5)) : 0;
	(len = ft_strlen(exe)) > flag->preci ? len = flag->preci : 0;
	(flag->speci == 's' && flag->preci >= 0) ? flag->sign -= len :
		(flag->sign -= (len = ft_strlen(exe)));
	while (!n && flag->sign-- > (flag->speci == 'c' && (exe[0] == 0 &&
				exe[1] == 0)) ? 1 : 0)
	{
		if (flag->speci == '%')
			(flag->preci > 0 || flag->zero) ? (stock(data, "0", 1)) :
				(stock(data, " ", 1));
		else
			stock(data, " ", 1);
	}
	(flag->speci == 'c' && (exe[0] == 0 && exe[1] == 0)) ? stock(data, exe, -2)
		&& flag->sign-- : 0;
	stock(data, exe, len);
	while (n && flag->sign-- > 0 && (stock(data, " ", 1)));
}

void	filling_o(char *exe, t_data *data, t_option *flag)
{
	int len;
	int n;
	int p;
	int i;
	char c;

	i = 0;
	p = flag->preci;
	flag->sign > 0 ? flag->sign *= flag->neg : 0;
	flag->sign < 0 ? (n = 1 && (flag->sign *= -1)) : (n = 0);
	(len = ft_strlen(exe)) < flag->preci ? len = (flag->preci ? flag->preci - 
			flag->sharp : flag->preci) : 0;
	(ft_atoll(exe) >= 0) && flag->sharp ? (len += 1) &&
		(flag->preci += 1) : 0;
	flag->sharp && !ft_atoll(exe) && !(flag->preci) ? flag->sign += 1 : 0;
	!n && (flag->sign -= ((ft_strlen(exe) && p >= 0 && flag->sharp &&
		!flag->zero) ? 1 : len));
	!n && !flag->sharp && !flag->zero && p == 0 && !ft_atoll(exe) ?
		flag->sign += len : 0;
	while (!n && flag->sign-- > 0 && (flag->zero && p == -1 ?
				(c = '0') : (c = ' ')) && (stock(data, &c, 1)));
	n && find("oO", flag->speci) && flag->sharp && flag->zero && (ft_atoll(exe) 
	== 0 ? stock(data, "0", flag->preci - flag->sharp): stock(data, "0", 1));
	flag->sign -= (len = ft_strlen(exe));
	if ((flag->preci -= (len + flag->sharp)) > 0)
		while (flag->preci-- > 0 && ++i ? flag->sign--: 0);
	while (!n && flag->sign-- > 0)
		flag->zero && flag->preci != -1 && flag->preci != -2 && !flag->sharp ?
			stock(data, "0", 1) : stock(data, " ", 1);
	n && flag->sign < p && ft_strlen(exe) && !flag->zero && !flag->sharp ?
		i += flag->preci : 0;
	while (i-- > 0 ? stock(data, "0", 1) : 0);
	find("oO", flag->speci) && flag->sharp && ft_atoll(exe) &&
		!(flag->preci > (int)ft_strlen(exe) || flag->preci == -1) && (!n ?
			stock(data, "0", 1) : stock(data, "0", 1) && (flag->sign -= 1));
	if ((p == 0) && !ft_atoll(exe))
		flag->sharp ? stock(data, exe, len) : stock(data, "0", 0);
	else
		stock(data, exe, len);
	while (n && flag->sign-- > 0 && (stock(data, " ", 1)));
}

void	filling_x(char *exe, t_data *data, t_option *flag)
{
	int len;//len exe
	int sn;//flag->sign == negative
	int i;//flag->preci = 0
	int p;//flag->preci
	int n;//le nombre == 0 ou plus

	n = 1;
	flag->preci == 0 ? (i = 1) : (i = 0);
	p = flag->preci;
	flag->sign > 0 ? flag->sign *= flag->neg : 0;
	flag->sign < 0 ? (sn = 1 && (flag->sign *= -1)) : (sn = 0);
	len = ((ft_atoll(exe) == 0 && !find("ABCDEFabcdef", *exe)) ?
		ft_strlen(exe) && (n = 0) : (ft_strlen(exe) + (flag->sharp * 2)));
	flag->sign  > len ? (flag->sign -= len) : (flag->sign = 0);
	i ? flag->zero = 0 : 0;

	(!n && (p == 1 || p == -1) && (!flag->sign || (flag->zero &&
		flag->sign == 1))) ? stock(data, "0", 1) && flag->sign-- : 0;
	if ((flag->preci > (len - (flag->sharp * 2)) ? (flag->preci -=
		(len - (flag->sharp * 2))) : (p ? flag->preci = 0 : 0)) > 0)
		(flag->sign > flag->preci && n ? (flag->sign -= flag->preci) : 0);
	!sn && flag->sharp && flag->sign && !flag->zero && flag->preci &&
		n ? flag->sign = 0 : 0;
	while (!sn && flag->sign && !flag->zero && flag->sign-- > 0)
		stock(data, " ", 1);
	while (!sn && !flag->zero && flag->sign-- > 0)
		!i && p && !flag->preci ? stock(data, " ", 1) : stock(data, "0", 1);
	flag->speci == 'X' && flag->sharp && (ft_atoll(exe) || find("ABCDEF",
		*exe)) && !(flag->preci > (int)ft_strlen(exe) && p == -1) && (!sn ?
		stock(data, "0X", 2) : stock(data, "0X", 1));
	flag->speci == 'x' && flag->sharp && (ft_atoll(exe) || find("abcdef",
		*exe)) && !(flag->preci > (int)ft_strlen(exe) && p == -1) && (!sn ?
		stock(data, "0x", 2) : stock(data, "0x", 2));
	while (n && flag->preci > flag->sign && flag->preci && flag->preci-- > 0)
		stock(data, "0", 1);
	while (!sn && flag->zero && flag->sign && flag->sign-- > 0)
		!i && p > 0 ? stock(data, " ", 1) : stock(data, "0", 1);
	while (!sn && !flag->zero && flag->sign-- > 0)
		!i && p && !flag->preci ? stock(data, " ", 1) : stock(data, "0", 1);
	while (p != 1 && !flag->sharp && flag->preci && flag->preci-- > 0)
		stock(data, "0", 1);
	stock(data, exe, len);
	while (sn && flag->sign-- > 0)
		stock(data, " ", 1);
}

char	*filling_i(int exe, t_data *data, t_option *flag)
{
	int n;
	int p;
	int len;

	flag->sign > 0 ? flag->sign *= flag->neg : 0;
	flag->preci >= 0 ? flag->zero = 0 : 0;//****
	(data->i = 0) ? ft_memset(data->exe, (int)"\0", data->i) : 0;
	exe < 0 ? (n = 1 && (exe *= -1)) : (n = 0);
	n ? flag->plus = 0 : 0;//****
	flag->zero && flag->plus && flag->preci == -1 ? (flag->preci = 
			(flag->sign -1)) : 0;//****
	exe == 0 && (flag->preci == 0) ? (len = 0) : (len = ft_intlen(exe));
	flag->sign < 0 ? (p = 1 && (flag->sign *= -1)) : (p = 0);
	flag->space && (!flag->plus && !n) ? (data->exe[data->i++] = ' ') : 0;
	if (!p && ((flag->sign -= (data->i + len + n + flag->plus + (flag->preci >
			len ? flag->preci - len : 0)))) > 0)
	{
		while (!flag->zero && flag->sign-- && (data->exe[data->i++] = ' '));
		(flag->zero && n) ? (data->exe[data->i++] = '-') : 0;
		while (flag->zero && flag->sign-- && (flag->plus ?
			(data->exe[data->i++] = ' ') : (data->exe[data->i++] = '0')));
	}
	else if (flag->zero && n)
		data->exe[data->i++] = '-';
	flag->plus == 1 && !n ? (data->exe[data->i++] = '+') : 0;
	!flag->zero && n ? (data->exe[data->i++] = '-') : 0;
	if ((flag->preci -= (len + n)) >= 0)
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

	flag->sign > 0 ? flag->sign *= flag->neg : 0;
	flag->preci >= 0 ? flag->zero = 0 : 0;//****
	(data->i = 0) ? ft_memset(data->exe, (int)"\0", data->i) : 0;
	exe < 0 ? (n = 1 && (exe *= -1)) : (n = 0);
	n ? flag->plus = 0 : 0;//****
	flag->zero && flag->plus && flag->preci == -1 ? (flag->preci = 
			(flag->sign -1)) : 0;//****
	exe == 0 && (flag->preci == 0) ? (len = 0) : (len = ft_intlen(exe));
	flag->sign < 0 ? (p = 1 && (flag->sign *= -1)) : (p = 0);
	flag->space && (!flag->plus && !n) ? (data->exe[data->i++] = ' ') : 0;
	if (!p && ((flag->sign -= (data->i + len + n + flag->plus + (flag->preci >
			len ? flag->preci - len : 0)))) > 0)
	{
		while (!flag->zero && flag->sign-- && (data->exe[data->i++] = ' '));
		(flag->zero && n) ? (data->exe[data->i++] = '-') : 0;
		while (flag->zero && flag->sign-- && (flag->plus ?
			(data->exe[data->i++] = ' ') : (data->exe[data->i++] = '0')));
	}
	else if (flag->zero  && n)
		data->exe[data->i++] = '-';
	flag->plus == 1 && !n ? (data->exe[data->i++] = '+') : 0;
	!flag->zero && n ? (data->exe[data->i++] = '-') : 0;
	if ((flag->preci -= (len + n)) >= 0)
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

	flag->sign > 0 ? flag->sign *= flag->neg : 0;
	flag->preci >= 0 ? flag->zero = 0 : 0;//****
	(data->i = 0) ? ft_memset(data->exe, (int)"\0", data->i) : 0;
	exe < 0 ? (n = 1 && (exe *= -1)) : (n = 0);
	n ? flag->plus = 0 : 0;//****
	flag->zero && flag->plus && flag->preci == -1 ? (flag->preci = 
			(flag->sign -1)) : 0;//****
	exe == 0 && (flag->preci == 0) ? (len = 0) : (len = ft_intlen(exe));
	flag->sign < 0 ? (p = 1 && (flag->sign *= -1)) : (p = 0);
	flag->space && (!flag->plus && !n) ? (data->exe[data->i++] = ' ') : 0;
	if (!p && ((flag->sign -= (data->i + len + n + flag->plus + (flag->preci >
				len ? flag->preci - len : 0)))) > 0)
	{
		while (!flag->zero && flag->sign-- && (data->exe[data->i++] = ' '));
		(flag->zero && n) ? (data->exe[data->i++] = '-') : 0;
		while (flag->zero && flag->sign-- && (flag->plus ?
			(data->exe[data->i++] = ' ') : (data->exe[data->i++] = '0')));
	}
	else if (flag->zero  && n)
		data->exe[data->i++] = '-';
	flag->plus == 1 && !n ? (data->exe[data->i++] = '+') : 0;
	!flag->zero && n ? (data->exe[data->i++] = '-') : 0;
	if ((flag->preci -= (len + n)) >= 0)
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

	flag->sign > 0 ? flag->sign *= flag->neg : 0;
	flag->preci >= 0 ? flag->zero = 0 : 0;//****
	(data->i = 0) ? ft_memset(data->exe, (int)"\0", data->i) : 0;
	exe < 0 ? (n = 1 && (exe *= -1)) : (n = 0);
	n ? flag->plus = 0 : 0;//****
	flag->zero && flag->plus && flag->preci == -1 ? (flag->preci = 
			(flag->sign -1)) : 0;//****
	exe == 0 && (flag->preci == 0) ? (len = 0) : (len = ft_intlen(exe));
	flag->sign < 0 ? (p = 1 && (flag->sign *= -1)) : (p = 0);
	flag->space && (!flag->plus && !n) ? (data->exe[data->i++] = ' ') : 0;
	if (!p && ((flag->sign -= (data->i + len + n + flag->plus + (flag->preci >
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
	if ((flag->preci -= (len + n)) >= 0)
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

	flag->sign > 0 ? flag->sign *= flag->neg : 0;
	flag->preci >= 0 ? flag->zero = 0 : 0;//****
	(data->i = 0) ? ft_memset(data->exe, (int)"\0", data->i) : 0;
	exe == 0 && (flag->preci == 0) ? (len = 0) : (len = ft_intlen(exe));
	flag->sign < 0 ? (p = 1 && (flag->sign *= -1)) : (p = 0);
	flag->space && flag->speci != 'u' ? (data->exe[data->i++] = ' ') : 0;
	if (!p && ((flag->sign -= (data->i + len + (flag->preci >
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

	flag->sign > 0 ? flag->sign *= flag->neg : 0;
	flag->preci >= 0 ? flag->zero = 0 : 0;//****
	(data->i = 0) ? ft_memset(data->exe, (int)"\0", data->i) : 0;
	exe == 0 && (flag->preci == 0) ? (len = 0) : (len = ft_intlen(exe));
	flag->sign < 0 ? (p = 1 && (flag->sign *= -1)) : (p = 0);
	flag->space && !flag->plus ? (data->exe[data->i++] = ' ') : 0;
	if (!p && ((flag->sign -= (data->i + len + flag->plus + (flag->preci >
				len ? flag->preci - len : 0)))) > 0)
	{
		while (!flag->zero && flag->sign-- && (data->exe[data->i++] = ' '));
		while (flag->zero && flag->sign-- && (flag->plus ?
				(data->exe[data->i++] = ' ') : (data->exe[data->i++] = '0')));
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

	flag->sign > 0 ? flag->sign *= flag->neg : 0;
	flag->preci >= 0 ? flag->zero = 0 : 0;//****
	(data->i = 0) ? ft_memset(data->exe, (int)"\0", data->i) : 0;
	exe == 0 && (flag->preci == 0) ? (len = 0) : (len = ft_intlen(exe));
	flag->sign < 0 ? (p = 1 && (flag->sign *= -1)) : (p = 0);
	flag->space && !flag->plus ? (data->exe[data->i++] = ' ') : 0;
	if (!p && ((flag->sign -= (data->i + len + flag->plus + (flag->preci >
				len ? flag->preci - len : 0)))) > 0)
	{
		while (!flag->zero && flag->sign-- && (data->exe[data->i++] = ' '));
		while (flag->zero && flag->sign-- && (flag->plus ?
				(data->exe[data->i++] = ' ') : (data->exe[data->i++] = '0')));
	}
	flag->plus == 1 ? (data->exe[data->i++] = '+') : 0;
	if ((flag->preci -= len) > 0)
		while (1 ? ((data->exe[data->i++] = '0') && --flag->preci) :
				(flag->preci-- && (data->exe[data->i++] = '0')));
	stock_exe(data, ft_ulltoa(exe), ft_intlen(ft_atoll(ft_ulltoa(exe))));
	if (p && (flag->sign -= data->i) > 0)
		while (flag->sign-- && (data->exe[data->i++] = ' '));
	return (data->exe);
}
