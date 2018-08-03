/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:00:38 by bhamdi            #+#    #+#             */
/*   Updated: 2018/08/03 06:36:05 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 *%%
 */

void	ft_percent(t_data *data, t_option *flag)
{
	char	exe;

	exe = '%';
	filling(" \0", "%\0", data, flag);
}

/*
 *%c
 */

void	ft_char(t_data *data, t_option *flag)
{
	char	exe[2];

	exe[0] = (char)va_arg(*flag->argptr, int);
	exe[1] = '\0';
	
	filling(" \0", exe, data, flag);
}

/*
 *%s
 */

void	ft_str(t_data *data, t_option *flag)
{
	int		len;
	char	*exe;

	len = 0;
	exe = (char*)va_arg(*flag->argptr, char*);
//printf("\nexe = [%s]\n",exe);
	while (exe[len])
		len++;
	filling(" \0", exe, data, flag);
}

/*
 *%dioxX
 */

void	ft_int(t_data *data, t_option *flag)
{
	int		len;
	int		exe;

	len = 0;
	exe = va_arg(*flag->argptr, unsigned int);
	len = ft_intlen(exe);
	filling(" \0", ft_itoa1(exe), data, flag);
}
