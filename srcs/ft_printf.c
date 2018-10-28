/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 02:20:55 by bhamdi            #+#    #+#             */
/*   Updated: 2018/10/28 07:48:51 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		processing(t_format *fmtptr, t_data *data)
{
	t_option	flag;

	init_option(&flag, &fmtptr->args, 1);
	fmtptr->i = find_define(&flag, fmtptr);
	apply_speci(data, &flag);
	return (fmtptr->i);
}

void	apply_speci(t_data *data, t_option *flag)
{
	flag->speci == '%' ? ft_percent(data, flag) : 0;
	flag->speci == 'c' ? ft_char(data, flag) : 0;
	flag->speci == 's' ? ft_str(data, flag) : 0;
	find("dDioOxX", flag->speci) ? ft_int(data, flag) : 0;
	find("uU", flag->speci) ? ft_uint(data, flag) : 0;
	find("fFeEaAgG", flag->speci) ? ft_double(data, flag) : 0;
	flag->speci == 'n' ? ft_pint(data, flag) : 0;
	flag->speci == 'p' ? ft_void(data, flag) : 0;
	init_option(flag, 0, 0);
}

int		ft_printf(const char *restrict format, ...)
{
	t_format	fmtptr;
	t_data		data;

	fmtptr.i = 0;
	fmtptr.j = 0;
	data.index = 0;
	data.len = 0;
	fmtptr.fmt = (char*)format;
	va_start(fmtptr.args, format);
	while (fmtptr.fmt[fmtptr.j])
		fmtptr.j++;
	while (fmtptr.i <= fmtptr.j)
		fmtptr.fmt[fmtptr.i] != '%' ? stock(&data, &(fmtptr.fmt[fmtptr.i++]),
				1) : (fmtptr.i = processing(&fmtptr, &data)) && (fmtptr.i++);
	va_end(fmtptr.args);
	return (data.len);
}
