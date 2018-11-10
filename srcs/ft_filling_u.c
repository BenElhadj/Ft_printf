/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filling_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 23:08:00 by bhamdi            #+#    #+#             */
/*   Updated: 2018/11/09 09:49:31 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	filling_u(t_data *data, t_option *flag)
{
	while (!flag->zero && flag->sign && flag->sign--)
		data->exe[data->i++] = ' ';
	while (flag->zero && flag->sign && flag->sign--)
		flag->preci == -1 ? (data->exe[data->i++] = '0') :
			(data->exe[data->i++] = ' ');
}

char	*filling_uint(unsigned int exe, t_data *data, t_option *flag)
{
	int p;
	int len;

	flag->sign > 0 ? flag->sign *= flag->neg : 0;
	flag->preci >= 0 ? flag->zero = 0 : 0;
	(data->i = 0) ? ft_memset(data->exe, (int)"\0", data->i) : 0;
	len = (exe == 0 && flag->preci == 0 ? 0 : ft_intlen(exe));
	p = (flag->sign < 0 ? 1 && (flag->sign *= -1) : 0);
	flag->space && flag->speci != 'u' ? (data->exe[data->i++] = ' ') : 0;
	if (!p && ((flag->sign -= (data->i + len + (flag->preci >
							len ? flag->preci - len : 0)))) > 0)
		filling_u(data, flag);
	if ((flag->preci -= len) > 0)
		while (flag->preci > 0)
			(1 ? ((data->exe[data->i++] = '0') && --flag->preci)
			: (flag->preci-- && (data->exe[data->i++] = '0')));
	stock_exe(data, ft_ulltoa(exe), len);
	if (p && (flag->sign -= data->i) > 0)
		while (flag->sign--)
			data->exe[data->i++] = ' ';
	return (data->exe);
}

char	*filling_ul(unsigned long exe, t_data *data, t_option *flag)
{
	int p;
	int len;

	flag->sign > 0 ? flag->sign *= flag->neg : 0;
	flag->preci >= 0 ? flag->zero = 0 : 0;
	(data->i = 0) ? ft_memset(data->exe, (int)"\0", data->i) : 0;
	len = (exe == 0 && flag->preci == 0 ? 0 : ft_intlen(exe));
	p = (flag->sign < 0 ? 1 && (flag->sign *= -1) : 0);
	flag->space ? (data->exe[data->i++] = ' ') : 0;
	if (!p && ((flag->sign -= (data->i + len + (flag->preci > len ?
					flag->preci - len : 0)))) > 0)
		filling_u(data, flag);
	if ((flag->preci -= len) > 0)
		while (flag->preci > 0)
			(1 ? ((data->exe[data->i++] = '0') && --flag->preci)
			: (flag->preci-- && (data->exe[data->i++] = '0')));
	stock_exe(data, ft_ulltoa(exe), len);
	if (p && (flag->sign -= data->i) > 0)
		while (flag->sign--)
			data->exe[data->i++] = ' ';
	return (data->exe);
}

char	*filling_ull(unsigned long long exe, t_data *data, t_option *flag)
{
	int p;
	int len;

	flag->sign > 0 ? flag->sign *= flag->neg : 0;
	flag->preci >= 0 ? flag->zero = 0 : 0;
	(data->i = 0) ? ft_memset(data->exe, (int)"\0", data->i) : 0;
	len = (exe == 0 && flag->preci == 0 ? 0 : ft_intlen(exe));
	p = (flag->sign < 0 ? 1 && (flag->sign *= -1) : 0);
	flag->space ? (data->exe[data->i++] = ' ') : 0;
	if (!p && ((flag->sign -= (data->i + len + (flag->preci > len ?
				flag->preci - len : 0)))) > 0)
		filling_u(data, flag);
	if ((flag->preci - len) > 0 && (flag->sign -= data->i))
		while (flag->preci > 0)
			(1 ? ((data->exe[data->i++] = '0') && --flag->preci)
			: (flag->preci-- && (data->exe[data->i++] = '0')));
	stock_exe(data, ft_ulltoa(exe), ft_intlen(ft_atoll(ft_ulltoa(exe))));
	if (p && (flag->sign -= data->i) > 0)
		while (flag->sign && flag->sign--)
			data->exe[data->i++] = ' ';
	return (data->exe);
}
