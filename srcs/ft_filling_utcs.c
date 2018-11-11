/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filling_utf8_cs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 09:29:37 by bhamdi            #+#    #+#             */
/*   Updated: 2018/11/11 09:23:59 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	filling_utf8_c(wchar_t str, t_data *data, t_option *flag)
{
	int total;
	int to_copy;

	to_copy = wcharc_len(str);
	total = (flag->width > to_copy) ? flag->width : to_copy;
	if (flag->sign > 0)
		w_to_charc(str, data);
	dataset(data, (flag->zero > 0 && flag->sign == 0) ? '0' :
			' ', total - to_copy);
	if (flag->sign <= 0)
		w_to_charc(str, data);
}

void	filling_utf8_s(wchar_t *str, t_data *data, t_option *flag)
{
	int total;
	int to_copy;
	int str_len;

	str == 0 ? str = L"(null)" : 0;
	str_len = wchars_len(str);
	to_copy = (flag->preci < str_len && flag->preci != -1) ? get_precis(str,
			flag->preci) : str_len;
	total = (flag->width > to_copy) ? flag->width : to_copy;
	if (flag->sign > 0)
		wchar_write(data, str, to_copy);
	dataset(data, (flag->zero > 0 && flag->sign == 0) ? '0' : ' ',
			total - to_copy);
	if (flag->sign <= 0)
		wchar_write(data, str, to_copy);
}

void	filling(char *exe, t_data *data, t_option *flag)
{
	int len;
	int n;

	flag->sign > 0 ? flag->sign *= flag->neg : 0;
	flag->preci >= 0 ? flag->zero = 0 : 0;
	n = (flag->sign < 0 ? 1 && (flag->sign *= -1) : 0);
	if (flag->speci == 's' && exe == 0)
	{
		exe = "(null)";
		len = 5;
	}
	len = (int)ft_strlen(exe) > flag->preci ? flag->preci : ft_strlen(exe);
	(flag->speci == 's' && flag->preci >= 0) ? flag->sign -= len :
		(flag->sign -= (len = ft_strlen(exe)));
	while (!n && flag->sign-- > (flag->speci == 'c' && (exe[0] == 0 &&
					exe[1] == 0)) ? 1 : 0)
		(flag->speci == '%' && (flag->preci > 0 || flag->zero))
			? stock(data, "0", 1) : stock(data, " ", 1);
	(flag->speci == 'c' && (exe[0] == 0 && exe[1] == 0)) ? stock(data, exe, -2)
		&& flag->sign-- : 0;
	stock(data, exe, len);
	while (n && flag->sign-- > 0)
		stock(data, " ", 1);
}
