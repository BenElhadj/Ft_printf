/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 02:20:55 by bhamdi            #+#    #+#             */
/*   Updated: 2018/10/09 17:56:45 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
	while (fmtptr->i <= fmtptr->j && fmtptr->fmt[fmtptr->i] == '#')
		fmtptr->i++ ? (flag->sharp = 1) : 0;
	while (fmtptr->i <= fmtptr->j && fmtptr->fmt[fmtptr->i] == ' ')
		fmtptr->i++ ? (flag->space = 1) : 0;
	while (fmtptr->i <= fmtptr->j && fmtptr->fmt[fmtptr->i] == '0')
		fmtptr->i++ ? (flag->zero = 1) : 0;
	while (fmtptr->i <= fmtptr->j && fmtptr->fmt[fmtptr->i] == '+')
		fmtptr->i++ ? (flag->plus = 1) : 0;
	while (fmtptr->i <= fmtptr->j && find(FLAGS, fmtptr->fmt[fmtptr->i]))
		flag->sign = ft_atoi1(fmtptr);
	fmtptr->i <= fmtptr->j && find(WIDTH, fmtptr->fmt[fmtptr->i]) ?
		(fmtptr->fmt[fmtptr->i] != '*' ? (flag->width = ft_atoi1(fmtptr)) :
		(flag->sign = va_arg(*flag->argptr, int)) && (fmtptr->i)++) : 0;
	fmtptr->fmt[fmtptr->i] == '.' && fmtptr->i++ ? (fmtptr->fmt[fmtptr->i] ==
		'*' ? (flag->preci = va_arg(*flag->argptr, int)) : (flag->preci = 
		ft_atoi1(fmtptr))) : 0;
	if (fmtptr->i <= fmtptr->j && find(LENGTH, fmtptr->fmt[fmtptr->i]))
	{
		flag->length = fmtptr->fmt[fmtptr->i++];
		((flag->length == 'h' && fmtptr->fmt[fmtptr->i] == 'h') &&
		fmtptr->i++) ? flag->length = 'H' : 0;
		((flag->length == 'l' && fmtptr->fmt[fmtptr->i] == 'l') &&
		fmtptr->i++) ? flag->length = 'L' : 0;
	}
	find(SPECIFIER, fmtptr->fmt[fmtptr->i]) ? flag->speci = find(SPECIFIER,
			fmtptr->fmt[fmtptr->i]) : fmtptr->i--;
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
