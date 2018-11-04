/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_w_to_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 23:07:34 by bhamdi            #+#    #+#             */
/*   Updated: 2018/11/04 02:08:08 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	w_to_char(wchar_t c, unsigned char *s, int *i)
{
	*i = 1;
	if (c < (1 << 7))
		*s++ = (unsigned char)(c);
	else if (c < (1 << 11))
	{
		*s++ = (unsigned char)((c >> 6) | 0xC0);
		*s++ = (unsigned char)((c & 0x3F) | 0x80);
		*i = 2;
	}
	else if (c < (1 << 16))
	{
		*s++ = (unsigned char)(((c >> 12)) | 0xE0);
		*s++ = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		*s++ = (unsigned char)((c & 0x3F) | 0x80);
		*i = 3;
	}
	else if (c < (1 << 21))
	{
		*s++ = (unsigned char)(((c >> 18)) | 0xF0);
		*s++ = (unsigned char)(((c >> 12) & 0x3F) | 0x80);
		*s++ = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		*s++ = (unsigned char)((c & 0x3F) | 0x80);
		*i = 4;
	}
	*s = 0;
}

wchar_t	*arg_wchars(int *read, int arg_num, t_data *data, t_option *flag)
{
	if (arg_num > -1)
	{
		while ((*read) < (arg_num - 1))
		{
			va_arg(*flag->argptr, size_t);
			(*read)++;
		}
		(*read)++;
		return (va_arg(*flag->argptr, wchar_t *));
	}
	while (*read < (int)data->index)
	{
		va_arg(*flag->argptr, char *);
		(*read)++;
	}
	(*read)++;
	data->index++;
	return (va_arg(*flag->argptr, wchar_t *));
}
