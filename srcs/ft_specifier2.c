/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 20:42:15 by bhamdi            #+#    #+#             */
/*   Updated: 2018/11/01 15:57:13 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** %u
*/

void	ft_uint(t_data *data, t_option *flag)
{
	int					len;
	unsigned long long	exe;

	len = 0;
	if (flag->speci == 'U' || (flag->speci == 'u' && flag->length == 'l'))
	{
		exe = (unsigned long)va_arg(*flag->argptr, unsigned long);
		stock(data, filling_ul(exe, data, flag), data->i);
	}
	else if (flag->speci == 'u' && flag->length == 'L')
	{
		exe = (unsigned long long)va_arg(*flag->argptr, unsigned long long);
		stock(data, filling_ull(exe, data, flag), data->i);
	}
	else if (flag->speci == 'u' && find("jz", flag->length))
	{
		exe = (size_t)va_arg(*flag->argptr, size_t);
		stock(data, filling_ul(exe, data, flag), data->i);
	}
	else
	{
		exe = (unsigned int)va_arg(*flag->argptr, unsigned int);
		len = ft_intlen(exe);
		stock(data, filling_uint(exe, data, flag), data->i);
	}
}

/*
** %fFeEaAgG
*/

void	ft_double(t_data *data, t_option *flag)
{
	int				len;
	double			exe;

	len = 0;
	exe = va_arg(*flag->argptr, double);
	len = ft_intlen(exe);
	filling(ft_ulltoa((unsigned long long)exe), data, flag);
}

/*
** %n
*/

void	ft_pint(t_data *data, t_option *flag)
{
	int				len;
	int				*exe;

	len = 0;
	exe = va_arg(*flag->argptr, int*);
	len = ft_intlen((long)exe);
	filling(ft_lltoa((long)exe), data, flag);
}

/*
** %p
*/

void	ft_void(t_data *data, t_option *flag)
{
	int n;
	int len;

	len = 0;
	n = (flag->sign < 0 ? 1 && (flag->sign *= -1) : 0);
	data->type.exe_ll = (int64_t)va_arg(*flag->argptr, void*);
	data->type.exe_str = ft_lltoa_base(data->type.exe_ll, 16, 0);
	while (data->type.exe_str[len])
		len++;
	flag->sign -= (len + 1);
	while (!n && --flag->sign > 0)
		stock(data, " ", 1);
	stock(data, "0x", 2);
	stock(data, data->type.exe_str, len);
	while (n && --flag->sign > 0)
		stock(data, " ", 1);
}
