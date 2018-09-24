/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <imhaimou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 17:25:46 by imhaimou          #+#    #+#             */
/*   Updated: 2018/06/17 18:18:17 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa_base(int nb, int b)
{
	int			i;
	char		*tab;
	long long	v;

	if (b < 2 || b > 16)
		return (NULL);
	if (nb == 0 && b == 10)
		return ("0");
	if (nb == -2147483648)
		return ("-2147483648");
	v = nb > 0 ? (long long)nb : (long long)nb * (-1);
	i = (nb < 0 && b == 10) ? ft_len_base(v, b) + 1 : ft_len_base(v, b);
	if (!(tab = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	tab[i--] = '\0';
	while (i >= 0)
	{
		tab[i] = v % b > 9 ? (v % b) + 55 : (v % b) + 48;
		v /= b;
		i--;
	}
	if (nb < 0 && b == 10)
		tab[0] = '-';
	return (tab);
}
