/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:07:53 by bhamdi            #+#    #+#             */
/*   Updated: 2018/11/02 22:25:56 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <limits.h>

int		main(void)
{
	int x1 = 0, x2 = 0;
/*	printf("TEST Nº : 1\n\n");
	
x1 = 	printf("VR:: [%#7.5X] [%0006.2x] [%lX]\n", 0xab, 0x876, 0xff11ff11ff1);
x2 = ft_printf("ME:: [%#7.5X] [%0006.2x] [%lX]\n", 0xab, 0x876, 0xff11ff11ff1);
	printf("[VR][%d] - [ME][%d]\n", x1, x2);
*/
	printf("\nTEST Nº : 2\n\n");

	x1 = 	printf("VR:: [%5.o] [%5.0o] [%-5.10o]\n", 0, 0, 2500);
	x2 = ft_printf("ME:: [%5.o] [%5.0o] [%-5.10o]\n", 0, 0, 2500);
	printf("[VR][%d] - [ME][%d]\n", x1, x2);

	printf("\nTEST Nº : 3\n\n");

	x1 = 	printf("VR:: [%.o] [%#5.0o] [%-5.10o]\n", 0, 0, 2500);
	x2 = ft_printf("ME:: [%.o] [%#5.0o] [%-5.10o]\n", 0, 0, 2500);
	printf("[VR][%d] - [ME][%d]\n", x1, x2);
	
	return (0);
}
