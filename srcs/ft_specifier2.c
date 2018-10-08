/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 20:42:15 by bhamdi            #+#    #+#             */
/*   Updated: 2018/09/21 00:44:24 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** %u
*/

void	ft_uint(t_data *data, t_option *flag)
{
	int				len;
	unsigned int	exe;

	len = 0;
	exe = va_arg(*flag->argptr, unsigned int);
	len = ft_intlen(exe);
	stock(data, filling_int(exe, data, flag), data->i);
//	filling(ft_itoa1(exe), data, flag);
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
