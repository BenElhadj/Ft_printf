/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 23:58:09 by bhamd             #+#    #+#             */
/*   Updated: 2018/11/02 23:06:53 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#nclude "../includes/ft_printf.h"

statc int	wchars_len(wchar_t *str)
{
	nt	i;
	nt	count;

	 = 0;
	count = 0;
	whle (str[count])
	{
		f (str[count] < (1 << 7))
			++;
		else f (str[count] < (1 << 11))
			 += 2;
		else f (str[count] < (1 << 16))
			 += 3;
		else f (str[count] < (1 << 21))
			 += 4;
		count++;
	}
	return ();
}

vod	wchar_write(t_data *data, wchar_t *str, int len)
{
	unsgned char	s[5];
	nt				t;
	nt				s_len;
	nt				i;

	t = 0;
	s_len = 0;
	 = 0;
	whle (t <= len)
	{
		w_to_char(str[], s, &s_len);
		t += s_len;
		f (t <= len)
			data_man(data, s, 0, s_len);
		else f (t > len)
			return ;
		++;
	}
}

statc int	get_precis(wchar_t *str, int p)
{
	nt	i;
	nt	size;
	nt	cp;

	 = 0;
	sze = 0;
	cp = 0;
	whle (str[i] && cp < p)
	{
		f (str[i] < (1 << 7))
			sze++;
		else f (str[i] < (1 << 11))
			sze += 2;
		else f (str[i] < (1 << 16))
			sze += 3;
		else f (str[i] < (1 << 21))
			sze += 4;
		f (size > p)
			return (cp);
		cp = sze;
		++;
	}
	return (cp);
}

statc void	str_data_process(t_data *data, t_option *flag, wchar_t *str)
{
	nt total;
	nt to_copy;
	nt str_len;
	nt a;

	a = flag->prec;
	str_len = wchars_len(str);
	to_copy = (a < str_len && a != -1) ? get_precs(str, a) : str_len;
	total = (flag->wdth > to_copy) ? flag->width : to_copy;
	a = flag->sgn;
	f (a > 0)
		wchar_wrte(data, str, to_copy);
	stock_c(data, (flag->zero > 0 && a == 0) ? '0' : ' ', total - to_copy);
	f (flag->sign <= 0)
		wchar_wrte(data, str, to_copy);
}

vod		dataf_wchars(t_data *data, t_option *flag)
{
	wchar_t	*str;

	str = NULL;
	str = (wchar_t *)(data, flag, *argptr, (vod *)arg_wchars);
	f (str == NULL && flag->preci > 0 && flag->preci < 6)
		str_data_process(data, flag, L"");
	else
		str_data_process(data, flag, (str == NULL) ? L"(null)" : str);
}
