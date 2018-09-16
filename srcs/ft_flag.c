/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 14:53:26 by bhamdi            #+#    #+#             */
/*   Updated: 2018/09/16 23:43:06 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	stock_exe(t_data *data, char *txt, int len)
{
	int i;

	i = 0;
	while (len--)
		data->exe[data->i++] = txt[i++]; 
}

void	filling(char *exe, t_data *data, t_option *flag)
{
}
char	*filling_int(int exe, t_data *data, t_option *flag)
{
	int n;
	int p;
	int len;

	ft_memset(data->exe, (int)"\0", data->i);
	data->i = 0;
	exe < 0 ? (n = 1 && (exe *= -1)) : (n = 0);
	len =  ft_intlen(exe);
	flag->sign < 0 ? (p = 1 && (flag->sign *= -1)) : (p = 0);
	flag->space && (!flag->plus && !n) ? (data->exe[data->i++] = ' ') : 0;
	if (!p && ((flag->sign -= (data->i + len + n + flag->plus + (flag->preci > 
							len ? flag->preci - len : 0)))) > 0)
		while (flag->sign-- && (data->exe[data->i++] = ' '));
	flag->plus == 1 && !n ? (data->exe[data->i++] = '+') : 0;
	n ? (data->exe[data->i++] = '-') : 0;
	if ((flag->preci -= len) > 0)
		while (n ? ((data->exe[data->i++] = '0') && flag->preci--) :
				(flag->preci-- && (data->exe[data->i++] = '0')));
	stock_exe(data, ft_itoa1(exe), len);
	if (p && (flag->sign -= data->i) > 0)
		while (flag->sign-- && (data->exe[data->i++] = ' '));
	return (data->exe);
}
