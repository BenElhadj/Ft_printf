/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filling_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 14:53:26 by bhamdi            #+#    #+#             */
/*   Updated: 2018/11/10 23:10:25 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*filling_i(int exe, t_data *data, t_option *flag)
{
	int n;
	int p;
	int len;

	flag->sign > 0 ? flag->sign *= flag->neg : 0;
	flag->preci >= 0 ? flag->zero = 0 : 0;
	(data->i = 0) ? ft_memset(data->exe, (int)"\0", data->i) : 0;
	n = (exe < 0 ? 1 && (exe *= -1) : 0);
	n ? flag->plus = 0 : 0;
	flag->zero && flag->plus && flag->preci == -1 ? (flag->preci =
			(flag->sign - 1)) : 0;
	len = (exe == 0 && (flag->preci == 0) ? 0 : ft_intlen(exe));
	p = (flag->sign < 0 ? 1 && (flag->sign *= -1) : 0);
	flag->space && (!flag->plus && !n) ? (data->exe[data->i++] = ' ') : 0;
	if (!p && ((flag->sign -= (data->i + len + n + flag->plus + (flag->preci >
							len ? flag->preci - len : 0)))) > 0)
	{
		while (!flag->zero && flag->sign--)
			data->exe[data->i++] = ' ';
		(flag->zero && n) ? (data->exe[data->i++] = '-') : 0;
		while (flag->zero && flag->sign--)
			(flag->plus ? (data->exe[data->i++] = ' ') :
			(data->exe[data->i++] = '0'));
	}
	else if (flag->zero && n)
		data->exe[data->i++] = '-';
	flag->plus == 1 && !n ? (data->exe[data->i++] = '+') : 0;
	!flag->zero && n ? (data->exe[data->i++] = '-') : 0;
	if ((flag->preci -= len) >= 0)
		while (flag->preci--)
			data->exe[data->i++] = '0';
	stock_exe(data, ft_lltoa(exe), len);
	if (p && (flag->sign -= data->i) > 0)
		while (flag->sign--)
			data->exe[data->i++] = ' ';
	return (data->exe);
}

char	*filling_l(long exe, t_data *data, t_option *flag)
{
	int n;
	int p;
	int len;

	flag->sign > 0 ? flag->sign *= flag->neg : 0;
	flag->preci >= 0 ? flag->zero = 0 : 0;
	(data->i = 0) ? ft_memset(data->exe, (int)"\0", data->i) : 0;
	n = (exe < 0 ? 1 && (exe *= -1) : 0);
	n ? flag->plus = 0 : 0;
	flag->zero && flag->plus && flag->preci == -1 ? (flag->preci =
			(flag->sign - 1)) : 0;
	len = (exe == 0 && (flag->preci == 0) ? 0 : ft_intlen(exe));
	p = (flag->sign < 0 ? 1 && (flag->sign *= -1) : 0);
	flag->space && (!flag->plus && !n) ? (data->exe[data->i++] = ' ') : 0;
	if (!p && ((flag->sign -= (data->i + len + n + flag->plus + (flag->preci >
							len ? flag->preci - len : 0)))) > 0)
	{
		while (!flag->zero && flag->sign--)
			data->exe[data->i++] = ' ';
		(flag->zero && n) ? (data->exe[data->i++] = '-') : 0;
		while (flag->zero && flag->sign--)
			data->exe[data->i++] = (flag->plus ? ' ' : '0');
	}
	else if (n && flag->zero)
		data->exe[data->i++] = '-';
	flag->plus == 1 && !n ? (data->exe[data->i++] = '+') : 0;
	!flag->zero && n ? (data->exe[data->i++] = '-') : 0;
	if ((flag->preci -= len) >= 0)
		while (flag->preci--)
			data->exe[data->i++] = '0';
	stock_exe(data, ft_lltoa(exe), len);
	if (p && (flag->sign -= data->i) > 0)
		while (flag->sign--)
			data->exe[data->i++] = ' ';
	return (data->exe);
}

char	*filling_ll(long long exe, t_data *data, t_option *flag)
{
	int n;
	int p;
	int len;

	flag->sign > 0 ? flag->sign *= flag->neg : 0;
	flag->preci >= 0 ? flag->zero = 0 : 0;
	(data->i = 0) ? ft_memset(data->exe, (int)"\0", data->i) : 0;
	n = (exe < 0 ? 1 && (exe *= -1) : 0);
	n ? flag->plus = 0 : 0;
	flag->zero && flag->plus && flag->preci == -1 ? (flag->preci =
			(flag->sign - 1)) : 0;
	len = (exe == 0 && (flag->preci == 0) ? 0 : ft_intlen(exe));
	p = (flag->sign < 0 ? 1 && (flag->sign *= -1) : 0);
	flag->space && (!flag->plus && !n) ? (data->exe[data->i++] = ' ') : 0;
	if (!p && ((flag->sign -= (data->i + len + n + flag->plus + (flag->preci >
							len ? flag->preci - len : 0)))) > 0)
	{
		while (!flag->zero && flag->sign--)
			data->exe[data->i++] = ' ';
		(flag->zero && n) ? (data->exe[data->i++] = '-') : 0;
		while (flag->zero && flag->sign--)
			data->exe[data->i++] = (flag->plus ? ' ' : '0');
	}
	else if (n && flag->zero)
		data->exe[data->i++] = '-';
	flag->plus == 1 && !n ? (data->exe[data->i++] = '+') : 0;
	!flag->zero && n ? (data->exe[data->i++] = '-') : 0;
	if ((flag->preci -= len) >= 0)
		while (flag->preci--)
			data->exe[data->i++] = '0';
	stock_exe(data, ft_lltoa(exe), len);
	if (p && (flag->sign -= data->i) > 0)
		while (flag->sign--)
			data->exe[data->i++] = ' ';
	return (data->exe);
}

char	*filling_im(intmax_t exe, t_data *data, t_option *flag)
{
	int n;
	int p;
	int len;

	flag->sign > 0 ? flag->sign *= flag->neg : 0;
	flag->preci >= 0 ? flag->zero = 0 : 0;
	(data->i = 0) ? ft_memset(data->exe, (int)"\0", data->i) : 0;
	n = (exe < 0 ? 1 && (exe *= -1) : 0);
	n ? flag->plus = 0 : 0;
	flag->zero && flag->plus && flag->preci == -1 ? (flag->preci =
			(flag->sign - 1)) : 0;
	len = (exe == 0 && (flag->preci == 0) ? 0 : ft_intlen(exe));
	p = (flag->sign < 0 ? 1 && (flag->sign *= -1) : 0);
	flag->space && (!flag->plus && !n) ? (data->exe[data->i++] = ' ') : 0;
	if (!p && ((flag->sign -= (data->i + len + n + flag->plus + (flag->preci >
							len ? flag->preci - len : 0)))) > 0)
	{
		while (!flag->zero && flag->sign--)
			data->exe[data->i++] = ' ';
		(flag->zero && n) ? (data->exe[data->i++] = '-') : 0;
		while (flag->zero && flag->sign--)
			data->exe[data->i++] = (flag->plus ? ' ' : '0');
	}
	else if (n && flag->zero)
		data->exe[data->i++] = '-';
	flag->plus == 1 && !n ? (data->exe[data->i++] = '+') : 0;
	!flag->zero && n ? (data->exe[data->i++] = '-') : 0;
	if ((flag->preci -= len) >= 0)
		while (flag->preci--)
			data->exe[data->i++] = '0';
	stock_exe(data, ft_lltoa(exe), len);
	if (p && (flag->sign -= data->i) > 0)
		while (flag->sign--)
			data->exe[data->i++] = ' ';
	return (data->exe);
}
