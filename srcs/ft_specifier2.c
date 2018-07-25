/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 20:42:15 by bhamdi            #+#    #+#             */
/*   Updated: 2018/07/25 21:51:19 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//%u
void	ft_uint(t_data *data, t_option *flag)
{
	int len;

	len = 0;
	unsigned int exe = (unsigned int)va_arg(*flag->argptr, unsigned int);
	len = ft_intlen(exe);

	stock(data, ft_itoa1(exe), len);
}

//%fFeEaAgG
void	ft_double(t_data *data, t_option *flag)
{
	int len;

	len = 0;
	double exe = (double)va_arg(*flag->argptr, double);
	len = ft_intlen(exe);
	
	stock(data, ft_itoa1(exe), len);
}

//%n
void	ft_pint(t_data *data, t_option *flag)
{
	int len;

	len = 0;
	int *exe = (int*)va_arg(*flag->argptr, int*);
	len = ft_intlen((long)exe);

	stock(data, ft_itoa1((long)exe), len);
}

//%p
void	ft_void(t_data *data, t_option *flag)
{
	int len;

	len = 0;
	void *exe = (void*)va_arg(*flag->argptr, void*);
	len = ft_intlen((long)exe);

	stock(data, ft_itoa1((long)exe), len);
}
