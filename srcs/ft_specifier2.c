/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 20:42:15 by bhamdi            #+#    #+#             */
/*   Updated: 2018/10/09 12:14:45 by bhamdi           ###   ########.fr       */
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
	if (flag->speci == 'U' || (flag->speci == 'u' &&
				(flag->length == 'l' || flag->length == 'L')))
	{
		exe = va_arg(*flag->argptr,unsigned long long);
		stock(data, filling_ull(exe, data, flag), data->i);
	}
	else
	{
		exe = va_arg(*flag->argptr, unsigned long);
		len = ft_intlen(exe);
		stock(data, filling_ul(exe, data, flag), data->i);
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
	filling(ft_itoa2(exe), data, flag);
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
