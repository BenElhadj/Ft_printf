/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 02:20:55 by bhamdi            #+#    #+#             */
/*   Updated: 2018/08/02 06:13:44 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	find(const char *s, char c)
{
	int			i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (c);
		i++;
	}
	return (0);
}

int		find_define(t_option *flag, t_format *fmtptr)
{
	fmtptr->i++;
	fmtptr->i <= fmtptr->j && fmtptr->fmt[fmtptr->i] == '#' ? fmtptr->i++ &&
		(flag->sharp = 1) : 0;
	fmtptr->i <= fmtptr->j && fmtptr->fmt[fmtptr->i] == '0' ? fmtptr->i++ &&
		(flag->zero = 1) : 0;
	fmtptr->i <= fmtptr->j && fmtptr->fmt[fmtptr->i] == ' ' ? fmtptr->i++ &&
		(flag->space = 1) : 0;
	fmtptr->i <= fmtptr->j && find(FLAGS, fmtptr->fmt[fmtptr->i]) ?
		flag->sign = ft_atoi1(fmtptr) : 0;
	fmtptr->i <= fmtptr->j && find(WIDTH, fmtptr->fmt[fmtptr->i]) ?
		(fmtptr->fmt[fmtptr->i] != '*' ? (flag->i_width = ft_atoi1(fmtptr)) :
		 (flag->c_width = 1) && (fmtptr->i)++) : 0;
	fmtptr->fmt[fmtptr->i] == '.' && fmtptr->i++ ? (fmtptr->fmt[fmtptr->i] ==
			'*' ? flag->c_preci = 1 : (flag->i_preci = ft_atoi1(fmtptr))) : 0;
	if (fmtptr->i <= fmtptr->j && find(LENGTH, fmtptr->fmt[fmtptr->i]))
	{
		flag->length[0] = fmtptr->fmt[fmtptr->i++];
		((flag->length[0] == 'h' && fmtptr->fmt[fmtptr->i] == 'h') &&
		 fmtptr->i++) ? flag->length[1] = 'h' : 0;
		((flag->length[0] == 'l' && fmtptr->fmt[fmtptr->i] == 'l') &&
		 fmtptr->i++) ? flag->length[1] = 'l' : 0;
	}
	find(SPECIFIER, fmtptr->fmt[fmtptr->i]) ? flag->speci = find(SPECIFIER,
			fmtptr->fmt[fmtptr->i]) : fmtptr->i-- && error(1);
	return (fmtptr->i);
}

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
	find("dioxX", flag->speci) ? ft_int(data, flag) : 0;
	flag->speci == 'u' ? ft_uint(data, flag) : 0;
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
