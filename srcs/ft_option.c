/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 21:47:52 by bhamdi            #+#    #+#             */
/*   Updated: 2018/10/28 07:34:21 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_intlen(unsigned long long n)
{
	int		i;

	i = 0;
	n <= 0 ? i++ : 0;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	flush_data(t_data *data)
{
	write(1, data->data, data->index);
	data->index = 0;
}

int		stock(t_data *data, char *fmt, int len)
{
	int	i;

	i = 0;
	while (fmt[i] && i < len)
	{
		data->index == SIZEBUF ? flush_data(data) : 0;
		data->data[data->index] = fmt[i];
		i++;
		data->index++;
		data->len++;
	}
	if (fmt[0] == 0 && fmt[1] == 0)
	{
		data->index == SIZEBUF ? flush_data(data) : 0;
		data->data[data->index] = fmt[i];
		i++;
		data->index++;
		data->len++;
	}
	flush_data(data);
	return (i);
}

void	init_option(t_option *flag, va_list *args, int bt)
{
	flag->sharp = 0;
	flag->zero = 0;
	flag->space = 0;
	flag->plus = 0;
	flag->sign = 0;
	flag->width = 0;
	flag->preci = -1;
	flag->length = '\0';
	flag->speci = '\0';
	bt == 1 ? flag->argptr = args : 0;
}

void	init_type(t_type *type)
{
	type->exe_i = 0;
	type->exe_sh = 0;
	type->exe_c = 0;
	type->exe_str = 0;
	type->exe_l = 0;
	type->exe_ll = 0;
	type->exe_im = 0;
	type->exe_si = 0;
	type->exe_ui = 0;
	type->exe_ush = 0;
	type->exe_uc = 0;
	type->exe_ul = 0;
	type->exe_ull = 0;
	type->exe_d = 0;
	type->exe_ld = 0;
	type->exe_int = 0;
	type->exe_void = 0;
}
