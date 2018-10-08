/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 14:53:26 by bhamdi            #+#    #+#             */
/*   Updated: 2018/09/28 03:29:12 by bhamdi           ###   ########.fr       */
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
	flag->sign -= (len = ft_strlen(exe));
	while (!n && flag->sign-- > 0 && (stock(data, " \0", 2)));
	stock(data, exe, len);
	while (n && flag->sign-- > 0 && (stock(data, " \0", 2)));
}

char	*filling_int(long exe, t_data *data, t_option *flag)
{
	int n;
	int p;
	int len;

	(data->i = 0) ? ft_memset(data->exe, (int)"\0", data->i) : 0;
	exe < 0 ? (n = 1 && (exe *= -1)) : (n = 0);
	len = ft_intlen(exe);
	flag->sign < 0 ? (p = 1 && (flag->sign *= -1)) : (p = 0);
	flag->space && (!flag->plus && !n) ? (data->exe[data->i++] = ' ') : 0;
	if (!p && ((flag->sign -= (data->i + len + n + flag->plus + (flag->preci >\
				len ? flag->preci - len : 0)))) > 0)
	{
		while (!flag->zero && flag->sign-- && (data->exe[data->i++] = ' '));
		n ? (data->exe[data->i++] = ' ') : 0;
		while (flag->zero && flag->sign-- && (data->exe[data->i++] = '0'));
	}
	flag->plus == 1 && !n ? (data->exe[data->i++] = '+') : 0;
	!flag->zero && n ? (data->exe[data->i++] = '-') : 0;
	if ((flag->preci -= (len + n)) > 0)
		while (n ? ((data->exe[data->i++] = '0') && flag->preci--) :
				(flag->preci-- && (data->exe[data->i++] = '0')));
	
	stock_exe(data, ft_itoa1(exe), len);
	if (p && (flag->sign -= data->i) > 0)
		while (flag->sign-- && (data->exe[data->i++] = ' '));

	return (data->exe);
}

char	*filling_uint(int exe, t_data *data, t_option *flag)
{
	int n;
	int p;
	int len;
	(data->i = 0) ? ft_memset(data->exe, (int)"\0", data->i) : 0;
	exe < 0 ? (n = 1 && (exe *= -1)) : (n = 0);
	len = ft_intlen(exe);
	flag->sign < 0 ? (p = 1 && (flag->sign *= -1)) : (p = 0);
	flag->space && (!flag->plus && !n) ? (data->exe[data->i++] = ' ') : 0;
	if (!p && ((flag->sign -= (data->i + len + n + flag->plus + (flag->preci >\
				len ? flag->preci - len : 0)))) > 0)
	{
		while (!flag->zero && flag->sign-- && (data->exe[data->i++] = ' '));
		n ? (data->exe[data->i++] = '-') : 0;
		while (flag->zero && flag->sign-- && (data->exe[data->i++] = '0'));
	}
	flag->plus == 1 && !n ? (data->exe[data->i++] = '+') : 0;
	n && !flag->zero ? (data->exe[data->i++] = '-') : 0;
	if ((flag->preci -= len) > 0)
		while (n ? ((data->exe[data->i++] = '0') && flag->preci--) :
				(flag->preci-- && (data->exe[data->i++] = '0')));
	stock_exe(data, ft_itoa1(exe), len);
	if (p && (flag->sign -= data->i) > 0)
		while (flag->sign-- && (data->exe[data->i++] = ' '));

	return (data->exe);
}
