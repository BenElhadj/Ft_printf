/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filling.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 14:53:26 by bhamdi            #+#    #+#             */
/*   Updated: 2018/11/10 16:11:41 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	filling_o(char *exe, t_data *data, t_option *flag)
{
	int		len;
	int		n;
	int		p;
	int		i;

	i = 0;
	p = flag->preci;
	flag->sign > 0 ? flag->sign *= flag->neg : 0;
	n = (flag->sign < 0 ? 1 && (flag->sign *= -1) : 0);
	len = (((int)ft_strlen(exe) < (flag->preci - flag->sharp)) ?
			(flag->preci - flag->sharp) : ft_strlen(exe));
	(ft_atoll(exe) >= 0) && flag->sharp ? (len += 1) &&
		(flag->preci += 1) : 0;
	flag->sharp && !ft_atoll(exe) && !(flag->preci) ? flag->sign += 1 : 0;
	!n && (flag->sign -= ((ft_strlen(exe) && p >= 0 && flag->sharp &&
			!flag->zero) ? 1 : len));
	!n && !flag->sharp && !flag->zero && p == 0 && !ft_atoll(exe) ?
		flag->sign += len : 0;
	while (!n && flag->sign-- > 0)
		stock(data, ((flag->zero && p == -1) ? "0" : " "), 1);
	n && find("oO", flag->speci) && flag->sharp && flag->zero && (ft_atoll(exe)
	== 0 ? stock(data, "0", flag->preci - flag->sharp) : stock(data, "0", 1));
	flag->sign -= (len = ft_strlen(exe));
	if ((flag->preci -= (len + flag->sharp)) > 0)
	{
		flag->sign -= flag->preci;
		i = flag->preci;
		flag->preci = -1;
	}
	while (!n && flag->sign-- > 0)
		flag->zero && flag->preci != -1 && flag->preci != -2 && !flag->sharp ?
		stock(data, "0", 1) : stock(data, " ", 1);
	n && flag->sign < p && ft_strlen(exe) && !flag->zero && !flag->sharp &&
		flag->preci != -1 ? i += flag->preci : 0;
	while (i-- > 0)
		stock(data, "0", 1);
	find("oO", flag->speci) && flag->sharp && ft_atoll(exe) &&
		!(flag->preci > (int)ft_strlen(exe) || flag->preci == -1) && (!n ?
			stock(data, "0", 1) : stock(data, "0", 1) && (flag->sign -= 1));
	if ((p == 0) && !ft_atoll(exe))
		flag->sharp ? stock(data, exe, len) : stock(data, "0", 0);
	else
		stock(data, exe, len);
	while (n && flag->sign-- > 0)
		stock(data, " ", 1);
}

void	filling_x(char *exe, t_data *data, t_option *flag)
{
	int		len;
	int		sn;
	int		i;
	int		p;
	int		n;

	n = 1;
	i = (flag->preci == 0 ? 1 : 0);
	p = flag->preci;
	flag->sign > 0 ? flag->sign *= flag->neg : 0;
	sn = (flag->sign < 0 ? 1 && (flag->sign *= -1) : 0);
	len = ((ft_atoll(exe) == 0 && !find("ABCDEFabcdef", *exe)) ?
		ft_strlen(exe) && (n = 0) : (ft_strlen(exe) + (flag->sharp * 2)));
	flag->sign = (flag->sign > len ? flag->sign - len : 0);
	i ? flag->zero = 0 : 0;
	(!n && (p == 1 || p == -1) && (!flag->sign || (flag->zero &&
		flag->sign == 1))) ? stock(data, "0", 1) && flag->sign-- : 0;
	if (flag->preci > (len - (flag->sharp * 2)))
		flag->preci -= (len - (flag->sharp * 2));
	else
		p ? flag->preci = 0 : 0;
	if (flag->preci > 0)
		(flag->sign > flag->preci && n ? (flag->sign -= flag->preci) : 0);
	!sn && flag->sharp && flag->sign && !flag->zero && flag->preci &&
		n ? flag->sign = 0 : 0;
	while (!sn && flag->sign && !flag->zero && flag->sign-- > 0)
		stock(data, " ", 1);
	while (!sn && !flag->zero && flag->sign-- > 0)
		!i && p && !flag->preci ? stock(data, " ", 1) : stock(data, "0", 1);
	flag->speci == 'X' && flag->sharp && (ft_atoll(exe) || find("ABCDEF",
		*exe)) && !(flag->preci > (int)ft_strlen(exe) && p == -1) && (!sn ?
		stock(data, "0X", 2) : stock(data, "0X", 1));
	flag->speci == 'x' && flag->sharp && (ft_atoll(exe) || find("abcdef",
		*exe)) && !(flag->preci > (int)ft_strlen(exe) && p == -1) && (!sn ?
		stock(data, "0x", 2) : stock(data, "0x", 2));
	while (!sn && flag->zero && flag->sign && flag->sign-- > 0)
		!i && p > 0 ? stock(data, " ", 1) : stock(data, "0", 1);
	while (n && flag->preci > flag->sign && flag->preci && flag->preci-- > 0)
		stock(data, "0", 1);
	while (!sn && !flag->zero && flag->sign-- > 0)
		!i && p && !flag->preci ? stock(data, " ", 1) : stock(data, "0", 1);
	while (p != 1 && !flag->sharp && flag->preci && flag->preci-- > 0)
		stock(data, "0", 1);
	stock(data, exe, len);
	while (sn && flag->sign-- > 0)
		stock(data, " ", 1);
}
