/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filling.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 14:53:26 by bhamdi            #+#    #+#             */
/*   Updated: 2018/11/11 00:55:30 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#define I i[0]
#define N i[1]
#define P i[2]
#define LEN i[3]
#define SN i[4]

void	processe_o(int i[4], char *exe, t_data *data, t_option *flag)
{
	if ((flag->preci -= (LEN + flag->sharp)) > 0)
	{
		flag->sign -= flag->preci;
		I = flag->preci;
		flag->preci = -1;
	}
	while (!N && flag->sign-- > 0)
		flag->zero && flag->preci != -1 && flag->preci != -2 && !flag->sharp ?
		stock(data, "0", 1) : stock(data, " ", 1);
	N && flag->sign < P && ft_strlen(exe) && !flag->zero && !flag->sharp &&
		flag->preci != -1 ? I += flag->preci : 0;
	while (I-- > 0)
		stock(data, "0", 1);
	find("oO", flag->speci) && flag->sharp && ft_atoll(exe) &&
		!(flag->preci > (int)ft_strlen(exe) || flag->preci == -1) && (!N ?
			stock(data, "0", 1) : stock(data, "0", 1) && (flag->sign -= 1));
	if ((P == 0) && !ft_atoll(exe))
		flag->sharp ? stock(data, exe, LEN) : stock(data, "0", 0);
	else
		stock(data, exe, LEN);
	while (N && flag->sign-- > 0)
		stock(data, " ", 1);
}

void	filling_o(char *exe, t_data *data, t_option *flag)
{
	int		i[4];

	I = 0;
	P = flag->preci;
	flag->sign > 0 ? flag->sign *= flag->neg : 0;
	N = (flag->sign < 0 ? 1 && (flag->sign *= -1) : 0);
	LEN = (((int)ft_strlen(exe) < (flag->preci - flag->sharp)) ?
			(flag->preci - flag->sharp) : ft_strlen(exe));
	(ft_atoll(exe) >= 0) && flag->sharp ? (LEN += 1) &&
		(flag->preci += 1) : 0;
	flag->sharp && !ft_atoll(exe) && !(flag->preci) ? flag->sign += 1 : 0;
	!N && (flag->sign -= ((ft_strlen(exe) && P >= 0 && flag->sharp &&
			!flag->zero) ? 1 : LEN));
	!N && !flag->sharp && !flag->zero && P == 0 && !ft_atoll(exe) ?
		flag->sign += LEN : 0;
	while (!N && flag->sign-- > 0)
		stock(data, ((flag->zero && P == -1) ? "0" : " "), 1);
	N && find("oO", flag->speci) && flag->sharp && flag->zero && (ft_atoll(exe)
	== 0 ? stock(data, "0", flag->preci - flag->sharp) : stock(data, "0", 1));
	flag->sign -= (LEN = ft_strlen(exe));
	processe_o(i, exe, data, flag);
}

void	processe_x(int i[5], char *exe, t_data *data, t_option *flag)
{
	while (!SN && flag->sign && !flag->zero && flag->sign-- > 0)
		stock(data, " ", 1);
	while (!SN && !flag->zero && flag->sign-- > 0)
		!I && P && !flag->preci ? stock(data, " ", 1) : stock(data, "0", 1);
	flag->speci == 'X' && flag->sharp && (ft_atoll(exe) || find("ABCDEF",
		*exe)) && !(flag->preci > (int)ft_strlen(exe) && P == -1) && (!SN ?
		stock(data, "0X", 2) : stock(data, "0X", 1));
	flag->speci == 'x' && flag->sharp && (ft_atoll(exe) || find("abcdef",
		*exe)) && !(flag->preci > (int)ft_strlen(exe) && P == -1) && (!SN ?
		stock(data, "0x", 2) : stock(data, "0x", 2));
	while (!SN && flag->zero && flag->sign && flag->sign-- > 0)
		!I && P > 0 ? stock(data, " ", 1) : stock(data, "0", 1);
	while (N && flag->preci > flag->sign && flag->preci && flag->preci-- > 0)
		stock(data, "0", 1);
	while (!SN && !flag->zero && flag->sign-- > 0)
		!I && P && !flag->preci ? stock(data, " ", 1) : stock(data, "0", 1);
	while (P != 1 && !flag->sharp && flag->preci && flag->preci-- > 0)
		stock(data, "0", 1);
	stock(data, exe, LEN);
	while (SN && flag->sign-- > 0)
		stock(data, " ", 1);
}

void	filling_x(char *exe, t_data *data, t_option *flag)
{
	int		i[5];

	N = 1;
	I = (flag->preci == 0 ? 1 : 0);
	P = flag->preci;
	flag->sign > 0 ? flag->sign *= flag->neg : 0;
	SN = (flag->sign < 0 ? 1 && (flag->sign *= -1) : 0);
	LEN = ((ft_atoll(exe) == 0 && !find("ABCDEFabcdef", *exe)) ?
		ft_strlen(exe) && (N = 0) : (ft_strlen(exe) + (flag->sharp * 2)));
	flag->sign = (flag->sign > LEN ? flag->sign - LEN : 0);
	I ? flag->zero = 0 : 0;
	(!N && (P == 1 || P == -1) && (!flag->sign || (flag->zero &&
		flag->sign == 1))) ? stock(data, "0", 1) && flag->sign-- : 0;
	if (flag->preci > (LEN - (flag->sharp * 2)))
		flag->preci -= (LEN - (flag->sharp * 2));
	else
		P ? flag->preci = 0 : 0;
	if (flag->preci > 0)
		(flag->sign > flag->preci && N ? (flag->sign -= flag->preci) : 0);
	!SN && flag->sharp && flag->sign && !flag->zero && flag->preci &&
		N ? flag->sign = 0 : 0;
	processe_x(i, exe, data, flag);
}
