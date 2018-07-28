/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:07:53 by bhamdi            #+#    #+#             */
/*   Updated: 2018/07/28 21:01:34 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	int i;
	int n = -32768;
	unsigned int u = 65535;
	float f = 29.03;
	int	*intptr;
	char str2[9] = "pointeur\0";
	char *str = "str\0";
	char c = 'a';
	intptr = (void*)str2;
	i = 0;

	i = printf("%% impression du %% ====> [%%]\nc impression du 'c' ====> [%c]\ns impression du 'str' ====> [%s]\nd impression du 1985 ====> [%d]\nu impression du 7235 ====> [%u]\nf impression du 29.03  ====> [%f]\nn impression du *ptr ====> [%n]\np impression du 'pointeur' ====> [%p]\n", c, str, n, u, f, intptr, intptr);

	printf("\nprintf return(%d)\n", i);

	i = ft_printf("%% impression du %% ====> [%%]\nc impression du 'c' ====> [%c]\ns impression du 'str' ====> [%s]\nd impression du 1985 ====> [%d]\nu impression du 7235 ====> [%u]\nf impression du 29.03  ====> [%f]\nn impression du *ptr ====> [%n]\np impression du 'pointeur' ====> [%p]\n", c, str, n, u, f, intptr, intptr);

	printf("\nft_printf return(%d)\n", i);
	return (0);
}
