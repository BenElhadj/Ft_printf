/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 12:01:09 by bhamdi            #+#    #+#             */
/*   Updated: 2018/09/24 12:01:14 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		print_hex(int nb)
{
	int		i;
	char	*s;

	if (!((s = (char*)malloc(sizeof(char) * 17))))
		return ;
	s = "0123456789abcdef";
	i = 0;
	if (nb >= 16)
	{
		print_hex(nb / 16);
		i = nb % 16;
		ft_putchar(s[i]);
	}
	else
		ft_putchar(s[nb]);
}
