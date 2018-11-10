/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_wchars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 07:36:15 by suddin            #+#    #+#             */
/*   Updated: 2018/11/06 03:29:01 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		wchars_len(wchar_t *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[count])
	{
		if (str[count] < (1 << 7))
			i++;
		else if (str[count] < (1 << 11))
			i += 2;
		else if (str[count] < (1 << 16))
			i += 3;
		else if (str[count] < (1 << 21))
			i += 4;
		count++;
	}
	return (i);
}

void	wchar_write(t_data *data, wchar_t *str, int len)
{
	unsigned char	s[5];
	int				t;
	int				s_len;
	int				i;

	t = 0;
	s_len = 0;
	i = 0;
	while (t <= len)
	{
		w_to_char(str[i], s, &s_len);
		t += s_len;
		if (t <= len)
			stock(data, (char*)s, s_len);
		else if (t > len)
			return ;
		i++;
	}
}

int		get_precis(wchar_t *str, int p)
{
	int	i;
	int	size;
	int	cp;

	i = 0;
	size = 0;
	cp = 0;
	while (str[i] && cp < p)
	{
		if (str[i] < (1 << 7))
			size++;
		else if (str[i] < (1 << 11))
			size += 2;
		else if (str[i] < (1 << 16))
			size += 3;
		else if (str[i] < (1 << 21))
			size += 4;
		if (size > p)
			return (cp);
		cp = size;
		i++;
	}
	return (cp);
}

void	str_data_process(t_data *data, t_option *flag, wchar_t *str)
{
	int total;
	int to_copy;
	int str_len;
	int a;

	a = flag->preci;
	str_len = wchars_len(str);
	to_copy = (a < str_len && a != -1) ? get_precis(str, a) : str_len;
	total = (flag->width > to_copy) ? flag->width : to_copy;
	a = flag->sign;
	if (a > 0)
		wchar_write(data, str, to_copy);
	dataset(data, (flag->zero > 0 && a == 0) ? '0' : ' ', total - to_copy);
	if (flag->sign <= 0)
		wchar_write(data, str, to_copy);
}
