/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:07:53 by bhamdi            #+#    #+#             */
/*   Updated: 2018/09/16 23:43:09 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int		main(void)
{
	//int i;
	//int n = -32768;
	//unsigned int u = 65535;
	//float f = (15);
	//int	intptr[4] = {24,42,17,27};
	////char str2[9] = "pointeur\0";
	//char *str = "string a afficher\0";
	//char c = 'a';
	//i = 0;

	/* 
	 i = printf("%% impression du %% ====> [%-7%]\nc impression du 'c' ====> [%5c]\ns impression du 'str' ====> [%-27s]\nd impression du -32768 ====> [%-9d]\nu impression du 7235 ====> [%-7u]\nf impression du 29.03  ====> [%f]\nn impression du *ptr ====> [%n]\np impression du 'pointeur' ====> [%p]\n", c, str, n, u, f, intptr, intptr);

	printf("\nprintf return(%d)\n", i);

	i = ft_printf("%% impression du %% ====> [%-7%]\nc impression du 'c' ====> [%5c]\ns impression du 'str' ====> [%-27s]\nd impression du -32768 ====> [%-9d]\nu impression du 7235 ====> [%-7u]\nf impression du 29.03  ====> [%f]\nn impression du *ptr ====> [%n]\np impression du 'pointeur' ====> [%p]\n", c, str, n, u, f, intptr, intptr);

	printf("\nft_printf return(%d)\n", i);
	*/
	int r1 = 0, r2 = 0, x1 = 0, x2 = 0;
	r1 = 	printf("VR:: [%+20.18d]\n", 1234567890);
	r2 = ft_printf("ME:: [%+20.18d]\n", 1234567890);

	printf("[VR][%d] - [ME][%d]\n", r1, r2);

	printf("radhoin TEST:\n");
	x1 = 	printf("VR:: [%+-15.10d]\n", 3959);
	x2 = ft_printf("ME:: [%+-15.10d]\n", 3959);
	printf("[VR][%d] - [ME][%d]\n", x1, x2);
	return (0);
}
