/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 14:53:26 by bhamdi            #+#    #+#             */
/*   Updated: 2018/11/11 09:24:01 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	stock_exe(t_data *data, char *txt, int len)
{
	int i;

	i = 0;
	while (len--)
		data->exe[data->i++] = txt[i++];
}

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

void	find_preci(t_option *flag, t_format *fmtptr)
{
	if (fmtptr->fmt[fmtptr->i] != '.' && fmtptr->fmt[fmtptr->i - 1] != '.')
	{
		while (fmtptr->i <= fmtptr->j && find(FLAGS, fmtptr->fmt[fmtptr->i]))
			flag->sign = (ft_atol_t(fmtptr) * flag->neg);
		if (fmtptr->i <= fmtptr->j && find(WIDTH, fmtptr->fmt[fmtptr->i]))
			(fmtptr->fmt[fmtptr->i] != '*' ? (flag->width =
			ft_atol_t(fmtptr)) : (flag->sign = (va_arg(*flag->argptr, int)
			* flag->neg)) && (fmtptr->i++));
	}
	if (fmtptr->fmt[fmtptr->i] == '.' && flag->preci == -1 && fmtptr->i++)
		(fmtptr->fmt[fmtptr->i] == '*' ? (flag->preci =
		va_arg(*flag->argptr, int)) && (fmtptr->i++) :
		((flag->preci = ft_atol_t(fmtptr))));
}

void	find_length(t_option *flag, t_format *fmtptr)
{
	flag->length = fmtptr->fmt[fmtptr->i++];
	((flag->length == 'h' && fmtptr->fmt[fmtptr->i] == 'h') &&
	fmtptr->i++) ? flag->length = 'H' : 0;
	((flag->length == 'l' && fmtptr->fmt[fmtptr->i] == 'l') &&
	fmtptr->i++) ? flag->length = 'L' : 0;
}

int		find_define(t_option *flag, t_format *fmtptr)
{
	int i;

	i = 0;
	while (!flag->speci && i++ != 9)
	{
		fmtptr->i++;
		while (fmtptr->i <= fmtptr->j && fmtptr->fmt[fmtptr->i] == '#')
			fmtptr->i++ ? (flag->sharp = 1) : 0;
		while (fmtptr->i <= fmtptr->j && fmtptr->fmt[fmtptr->i] == ' ')
			fmtptr->i++ ? (flag->space = 1) : 0;
		while (fmtptr->i <= fmtptr->j && fmtptr->fmt[fmtptr->i] == '-')
			fmtptr->i++ ? (flag->neg = -1) : 0;
		while (fmtptr->i <= fmtptr->j && fmtptr->fmt[fmtptr->i] == '+')
			fmtptr->i++ ? (flag->plus = 1) : 0;
		while (fmtptr->i <= fmtptr->j && fmtptr->fmt[fmtptr->i] == '0')
			fmtptr->i++ ? (flag->zero = 1) : 0;
		find("-.*0123456789", fmtptr->fmt[fmtptr->i]) ?
			find_preci(flag, fmtptr) : 0;
		if (fmtptr->i <= fmtptr->j && find(LENGTH, fmtptr->fmt[fmtptr->i]))
			find_length(flag, fmtptr);
		find(SPECIFIER, fmtptr->fmt[fmtptr->i]) ? flag->speci =
		find(SPECIFIER, fmtptr->fmt[fmtptr->i]) : (fmtptr->i -= 1);
	}
	return (fmtptr->i);
}
