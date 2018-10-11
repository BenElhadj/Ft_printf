/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 20:42:15 by bhamdi            #+#    #+#             */
/*   Updated: 2018/10/11 02:34:16 by bhamdi           ###   ########.fr       */
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
		exe = (unsigned long)va_arg(*flag->argptr,unsigned long);
		stock(data, filling_ul(exe, data, flag), data->i);
	}
	else if (flag->speci == 'u' && flag->length == 'L')
	{
		exe = (unsigned long long)va_arg(*flag->argptr,unsigned long long);
		stock(data, filling_ull(exe, data, flag), data->i);
	}
	else if (flag->speci == 'u' && flag->length == 'z')
	{
		exe = (size_t)va_arg(*flag->argptr,size_t);
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
	filling(ft_itoa3((unsigned long long)exe), data, flag);
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
	filling(ft_itoa1((long)exe), data, flag);
}

/*
** %p
*/

void	ft_void(t_data *data, t_option *flag)
{
	int				len;
	unsigned int	*exe;

	len = 0;
	exe = va_arg(*flag->argptr, unsigned int*);
	len = ft_intlen((long)exe);
	filling(ft_itoa1((long)exe), data, flag);
}
