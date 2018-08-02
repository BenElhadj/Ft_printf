/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:07:53 by bhamdi            #+#    #+#             */
/*   Updated: 2018/08/02 10:16:11 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	int i;
	int n = -32768;
	unsigned int u = 65535;
	float f = 29.6563;
	int	intptr[4] = {24,42,17,27};
	//char str2[9] = "pointeur\0";
	char *str = "string a afficher\0";
	char c = 'a';
	i = 0;

	i = printf("%% impression du %% ====> [%-7%]\nc impression du 'c' ====> [%5c]\ns impression du 'str' ====> [%-27s]\nd impression du -32768 ====> [%-9d]\nu impression du 7235 ====> [%-7u]\nf impression du 29.03  ====> [%19f]\nn impression du *ptr ====> [%n]\np impression du 'pointeur' ====> [%p]\n", c, str, n, u, f, intptr, intptr);

	printf("\nprintf return(%d)\n", i);

	i = ft_printf("%% impression du %% ====> [%-7%]\nc impression du 'c' ====> [%5c]\ns impression du 'str' ====> [%-27s]\nd impression du -32768 ====> [%-9d]\nu impression du 7235 ====> [%-7u]\nf impression du 29.03  ====> [%19f]\nn impression du *ptr ====> [%n]\np impression du 'pointeur' ====> [%p]\n", c, str, n, u, f, intptr, intptr);

	printf("\nft_printf return(%d)\n", i);
	return (0);
}
