/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filling_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 14:53:26 by bhamdi            #+#    #+#             */
/*   Updated: 2018/11/11 00:29:53 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#define N i[0]
#define P i[1]
#define LEN i[2]

void	processe(int i[3], t_data *data, t_option *flag)
{
	if (!P && ((flag->sign -= (data->i + LEN + N + flag->plus + (flag->preci >
							LEN ? flag->preci - LEN : 0)))) > 0)
	{
		while (!flag->zero && flag->sign--)
			data->exe[data->i++] = ' ';
		(flag->zero && N) ? (data->exe[data->i++] = '-') : 0;
		while (flag->zero && flag->sign--)
			data->exe[data->i++] = (flag->plus ? ' ' : '0');
	}
	else if (flag->zero && N)
		data->exe[data->i++] = '-';
	flag->plus == 1 && !N ? (data->exe[data->i++] = '+') : 0;
	!flag->zero && N ? (data->exe[data->i++] = '-') : 0;
}

char	*filling_i(int exe, t_data *data, t_option *flag)
{
	int i[3];

	flag->sign > 0 ? flag->sign *= flag->neg : 0;
	flag->preci >= 0 ? flag->zero = 0 : 0;
	(data->i = 0) ? ft_memset(data->exe, (int)"\0", data->i) : 0;
	N = (exe < 0 ? 1 && (exe *= -1) : 0);
	N ? flag->plus = 0 : 0;
	flag->zero && flag->plus && flag->preci == -1 ? (flag->preci =
			(flag->sign - 1)) : 0;
	LEN = (exe == 0 && (flag->preci == 0) ? 0 : ft_intlen(exe));
	P = (flag->sign < 0 ? 1 && (flag->sign *= -1) : 0);
	flag->space && (!flag->plus && !N) ? (data->exe[data->i++] = ' ') : 0;
	processe(i, data, flag);
	if ((flag->preci -= LEN) >= 0)
		while (flag->preci--)
			data->exe[data->i++] = '0';
	stock_exe(data, ft_lltoa(exe), LEN);
	if (P && (flag->sign -= data->i) > 0)
		while (flag->sign--)
			data->exe[data->i++] = ' ';
	return (data->exe);
}

char	*filling_l(long exe, t_data *data, t_option *flag)
{
	int i[3];

	flag->sign > 0 ? flag->sign *= flag->neg : 0;
	flag->preci >= 0 ? flag->zero = 0 : 0;
	(data->i = 0) ? ft_memset(data->exe, (int)"\0", data->i) : 0;
	N = (exe < 0 ? 1 && (exe *= -1) : 0);
	N ? flag->plus = 0 : 0;
	flag->zero && flag->plus && flag->preci == -1 ? (flag->preci =
			(flag->sign - 1)) : 0;
	LEN = (exe == 0 && (flag->preci == 0) ? 0 : ft_intlen(exe));
	P = (flag->sign < 0 ? 1 && (flag->sign *= -1) : 0);
	flag->space && (!flag->plus && !N) ? (data->exe[data->i++] = ' ') : 0;
	processe(i, data, flag);
	if ((flag->preci -= LEN) >= 0)
		while (flag->preci--)
			data->exe[data->i++] = '0';
	stock_exe(data, ft_lltoa(exe), LEN);
	if (P && (flag->sign -= data->i) > 0)
		while (flag->sign--)
			data->exe[data->i++] = ' ';
	return (data->exe);
}

char	*filling_ll(long long exe, t_data *data, t_option *flag)
{
	int i[3];

	flag->sign > 0 ? flag->sign *= flag->neg : 0;
	flag->preci >= 0 ? flag->zero = 0 : 0;
	(data->i = 0) ? ft_memset(data->exe, (int)"\0", data->i) : 0;
	N = (exe < 0 ? 1 && (exe *= -1) : 0);
	N ? flag->plus = 0 : 0;
	flag->zero && flag->plus && flag->preci == -1 ? (flag->preci =
			(flag->sign - 1)) : 0;
	LEN = (exe == 0 && (flag->preci == 0) ? 0 : ft_intlen(exe));
	P = (flag->sign < 0 ? 1 && (flag->sign *= -1) : 0);
	flag->space && (!flag->plus && !N) ? (data->exe[data->i++] = ' ') : 0;
	processe(i, data, flag);
	if ((flag->preci -= LEN) >= 0)
		while (flag->preci--)
			data->exe[data->i++] = '0';
	stock_exe(data, ft_lltoa(exe), LEN);
	if (P && (flag->sign -= data->i) > 0)
		while (flag->sign--)
			data->exe[data->i++] = ' ';
	return (data->exe);
}

char	*filling_im(intmax_t exe, t_data *data, t_option *flag)
{
	int i[3];

	flag->sign > 0 ? flag->sign *= flag->neg : 0;
	flag->preci >= 0 ? flag->zero = 0 : 0;
	(data->i = 0) ? ft_memset(data->exe, (int)"\0", data->i) : 0;
	N = (exe < 0 ? 1 && (exe *= -1) : 0);
	N ? flag->plus = 0 : 0;
	flag->zero && flag->plus && flag->preci == -1 ? (flag->preci =
			(flag->sign - 1)) : 0;
	LEN = (exe == 0 && (flag->preci == 0) ? 0 : ft_intlen(exe));
	P = (flag->sign < 0 ? 1 && (flag->sign *= -1) : 0);
	flag->space && (!flag->plus && !N) ? (data->exe[data->i++] = ' ') : 0;
	processe(i, data, flag);
	if ((flag->preci -= LEN) >= 0)
		while (flag->preci--)
			data->exe[data->i++] = '0';
	stock_exe(data, ft_lltoa(exe), LEN);
	if (P && (flag->sign -= data->i) > 0)
		while (flag->sign--)
			data->exe[data->i++] = ' ';
	return (data->exe);
}
