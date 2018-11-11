/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:00:38 by bhamdi            #+#    #+#             */
/*   Updated: 2018/11/11 01:34:55 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**%%cs
*/

void	ft_str(t_data *data, t_option *flag)
{
	char	exe_c[2];
	int		ascii;

	if (flag->speci == '%')
		filling("%\0", data, flag);
	else if (flag->speci == 'c' || find(SPECIFIER, flag->preci))
	{
		flag->length == 'l' ? flag->speci = 'C' : 0;
		if (flag->length != 'l')
		{
			ascii = (flag->speci == 'c' ? va_arg(*flag->argptr, int) :
				flag->speci);
			exe_c[0] = (char)ascii;
			exe_c[1] = '\0';
			filling(exe_c, data, flag);
		}
	}
	else if (flag->speci == 's')
		flag->length == 'l' ? flag->speci = 'S' :
			filling(va_arg(*flag->argptr, char*), data, flag);
	else if (flag->speci == 'C')
		filling_utf8_c(va_arg(*flag->argptr, wchar_t), data, flag);
	else if (flag->speci == 'S')
		filling_utf8_s(va_arg(*flag->argptr, wchar_t*), data, flag);
}

/*
**%dDi
*/

void	ft_int_di(t_data *data, t_option *flag)
{
	init_type(&data->type);
	(!flag->length && !(flag->speci == 'D')) ? stock(data, filling_i((
		data->type.exe_i = va_arg(*flag->argptr, int)), data, flag),
			data->i) : 0;
	(flag->length == 'h' && !(flag->speci == 'D')) ? stock(data,
		filling_i((data->type.exe_sh = (short)va_arg(*flag->argptr, int)),
			data, flag), data->i) : 0;
	(flag->length == 'H' && !(flag->speci == 'D')) ? stock(data, filling_i((
		data->type.exe_c = (char)va_arg(*flag->argptr, int)), data,
			flag), data->i) : 0;
	(flag->length == 'l' || flag->speci == 'D') ? stock(data, filling_l((
		data->type.exe_l = va_arg(*flag->argptr, long)), data, flag),
			data->i) : 0;
	(flag->length == 'L' && !(flag->speci == 'D')) ? stock(data, filling_ll((
		data->type.exe_ll = va_arg(*flag->argptr, long long)),
			data, flag), data->i) : 0;
	(flag->length == 'j' && !(flag->speci == 'D')) ? stock(data, filling_im((
		data->type.exe_im = va_arg(*flag->argptr, intmax_t)), data,
			flag), data->i) : 0;
	(flag->length == 'z' && !(flag->speci == 'D')) ? stock(data,
		filling_l((data->type.exe_ssi = va_arg(*flag->argptr, ssize_t)),
			data, flag), data->i) : 0;
}

/*
**%oO
*/

void	ft_int_o(t_data *data, t_option *flag)
{
	init_type(&data->type);
	!flag->length ? filling_o(ft_lltoa_base((unsigned long)va_arg(
		*flag->argptr, unsigned long), 8, 0), data, flag) : 0;
	(flag->length == 'h') ? filling_o(ft_lltoa_base((unsigned short)va_arg(
		*flag->argptr, unsigned int), 8, 0), data, flag) : 0;
	(flag->length == 'H') ? filling_o(ft_lltoa_base((unsigned char)va_arg(
		*flag->argptr, unsigned int), 8, 0), data, flag) : 0;
	(flag->length == 'l') || (flag->speci == 'D') ? filling_o(ft_lltoa_base(
		(long long)va_arg(*flag->argptr, long long), 8, 0), data, flag) : 0;
	(flag->length == 'L') ? filling_o(ft_lltoa_base((unsigned long long)
		va_arg(*flag->argptr, unsigned long long), 8, 0), data, flag) : 0;
	(flag->length == 'j') ? filling_o(ft_lltoa_base((intmax_t)va_arg(
		*flag->argptr, intmax_t), 8, 0), data, flag) : 0;
	(flag->length == 'z') ? filling_o(ft_lltoa_base((size_t)va_arg(
		*flag->argptr, size_t), 8, 0), data, flag) : 0;
}

/*
**%xX
*/

void	ft_int_x(t_data *data, t_option *flag)
{
	int i;

	init_type(&data->type);
	i = (flag->speci == 'X' ? 1 : 0);
	!flag->length ? filling_x(ft_lltoa_base((unsigned int)va_arg(
					*flag->argptr, unsigned int), 16, i), data, flag) : 0;
	flag->length == 'h' ? filling_x(ft_lltoa_base((short)va_arg(
					*flag->argptr, int), 16, i), data, flag) : 0;
	flag->length == 'H' ? filling_x(ft_lltoa_base((int)va_arg(
					*flag->argptr, int), 16, i), data, flag) : 0;
	flag->length == 'l' ? filling_x(ft_lltoa_base((long)va_arg(
					*flag->argptr, long), 16, i), data, flag) : 0;
	flag->length == 'L' ? filling_x(ft_lltoa_base((long long)va_arg(
					*flag->argptr, long long), 16, i), data, flag) : 0;
	flag->length == 'j' ? filling_x(ft_lltoa_base((intmax_t)va_arg(
					*flag->argptr, intmax_t), 16, i), data, flag) : 0;
	flag->length == 'z' ? filling_x(ft_lltoa_base((size_t)va_arg(
					*flag->argptr, size_t), 16, i), data, flag) : 0;
}
