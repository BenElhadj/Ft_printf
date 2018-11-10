/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 21:47:52 by bhamdi            #+#    #+#             */
/*   Updated: 2018/11/06 11:16:29 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	flush_data(t_data *data)
{
	write(1, data->data, data->index);
	data->index = 0;
}

int		dataset(t_data *data, char fmt, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		data->index == SIZEBUF ? flush_data(data) : 0;
		data->data[data->index] = fmt;
		i++;
		data->index++;
		data->len++;
	}
	if (len == -2)
	{
		data->index == SIZEBUF ? flush_data(data) : 0;
		data->data[data->index] = fmt;
		i++;
		data->index++;
		data->len++;
	}
	return (i);
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
	if (len == -2 && fmt[0] == 0 && fmt[1] == 0)
	{
		data->index == SIZEBUF ? flush_data(data) : 0;
		data->data[data->index] = fmt[i];
		i++;
		data->index++;
		data->len++;
	}
	return (i);
}

void	init_option(t_option *flag, va_list *args, int bt)
{
	flag->sharp = 0;
	flag->zero = 0;
	flag->space = 0;
	flag->plus = 0;
	flag->neg = 1;
	flag->sign = 0;
	flag->width = 0;
	flag->preci = -1;
	flag->length = '\0';
	flag->speci = '\0';
	bt == 1 ? flag->argptr = args : 0;
}

void	init_type(t_type *type)
{
	type->exe_ld = 0;
}
