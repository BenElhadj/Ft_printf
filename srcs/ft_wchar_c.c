/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 23:57:32 by bhamdi            #+#    #+#             */
/*   Updated: 2018/11/05 10:41:45 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

wchar_t	*arg_wcharc(int *read, int arg_num, t_data *data, t_option *flag)
{
	static wchar_t	i[2];

	i[0] = 0;
	if (arg_num > -1)
	{
		while ((*read) < (arg_num - 1))
		{
			va_arg(*flag->argptr, size_t);
			(*read)++;
		}
		(*read)++;
		i[0] = va_arg(*flag->argptr, wchar_t);
		return (i);
	}
	while ((*read) < (int)data->index)
	{
		va_arg(*flag->argptr, size_t);
		(*read)++;
	}
	(*read)++;
	data->index++;
	i[0] = va_arg(*flag->argptr, wchar_t);
	return (i);
}

void	w_to_charc(wchar_t c, t_data *data)
{
	if (c < (1 << 7))
		dataset(data, (unsigned char)(c), 1);
	else if (c < (1 << 11))
	{
		dataset(data, (unsigned char)((c >> 6) | 0xC0), 1);
		dataset(data, (unsigned char)((c & 0x3F) | 0x80), 1);
	}
	else if (c < (1 << 16))
	{
		dataset(data, (unsigned char)(((c >> 12)) | 0xE0), 1);
		dataset(data, (unsigned char)(((c >> 6) & 0x3F) | 0x80), 1);
		dataset(data, (unsigned char)((c & 0x3F) | 0x80), 1);
	}
	else if (c < (1 << 21))
	{
		dataset(data, (unsigned char)(((c >> 18)) | 0xF0), 1);
		dataset(data, (unsigned char)(((c >> 12) & 0x3F) | 0x80), 1);
		dataset(data, (unsigned char)(((c >> 6) & 0x3F) | 0x80), 1);
		dataset(data, (unsigned char)((c & 0x3F) | 0x80), 1);
	}
}

int		wcharc_len(wchar_t str)
{
	if (str < (1 << 7))
		return (1);
	else if (str < (1 << 11))
		return (2);
	else if (str < (1 << 16))
		return (3);
	else
		return (4);
}

void	char_data_process(t_data *data, t_option *flag, wchar_t str)
{
	int total;
	int to_copy;
	int a;

	to_copy = wcharc_len(str);
	total = (flag->width > to_copy) ? flag->width : to_copy;
	a = flag->sign;
	if (a > 0)
		w_to_charc(str, data);
	dataset(data, (flag->zero > 0 && a == 0) ? '0' : ' ', total - to_copy);
	if (flag->sign <= 0)
		w_to_charc(str, data);
}
