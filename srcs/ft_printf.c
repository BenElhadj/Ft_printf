/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 02:20:55 by bhamdi            #+#    #+#             */
/*   Updated: 2018/07/28 20:00:07 by bhamdi           ###   ########.fr       */
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

int		find_int(t_option *flag, t_format *fmtptr, int a)
{
	int *c_var;
	int *i_var;

	a == 1 ? c_var = &flag->c_width : 0;
	a == 1 ? i_var = &flag->i_width : 0;
	a == 2 ? c_var = &flag->c_preci : 0;
	a == 2 ? i_var = &flag->i_preci : 0;
	if (fmtptr->fmt[fmtptr->i] == '*')
	{
		*c_var = 1;
		(fmtptr->i)++;
	}
	else if (fmtptr->fmt[fmtptr->i] >= '0' && fmtptr->fmt[fmtptr->i] <= '9')
		while (fmtptr->fmt[fmtptr->i] >= '0' && fmtptr->fmt[fmtptr->i] <= '9')
		{
			*i_var = ((*i_var * 10) + (fmtptr->fmt[fmtptr->i] - '0'));
			(fmtptr->i)++;
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
	fmtptr->i <= fmtptr->j && fmtptr->fmt[fmtptr->i] == '-' && (fmtptr->i++) ?
		flag->left = ft_atoi1(fmtptr) : 0;
	fmtptr->i <= fmtptr->j && fmtptr->fmt[fmtptr->i] == '+' && (fmtptr->i++) ?
		flag->sign = ft_atoi1(fmtptr) : 0;
	find(WIDTH, fmtptr->fmt[fmtptr->i]) ? find_int(flag, fmtptr, 1) : 0;
	fmtptr->fmt[fmtptr->i] == '.' && fmtptr->i++ ?
		find_int(flag, fmtptr, 2) : 0;
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
