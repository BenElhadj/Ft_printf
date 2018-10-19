/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:07:53 by bhamdi            #+#    #+#             */
/*   Updated: 2018/10/20 00:27:54 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <limits.h>

int		main(void)
{
	int r1 = 0, r2 = 0, x1 = 0, x2 = 0;
	printf("TEST Nº : 1\n\n");

	r1 = 	printf("VR:: [coco et %-#-#--24O titi%#012o]\n", 12, -874);
	r2 = ft_printf("ME:: [coco et %-#-#--24O titi%#012o]\n", 12, -874);
	printf("[VR][%d] - [ME][%d]\n", r1, r2);

	printf("\nTEST Nº : 2\n\n");

	x1 = 	printf("VR:: [%024hho et%#1.2o %0012.O]\n", (unsigned char)12, 0, 123654789);
	x2 = ft_printf("ME:: [%024hho et%#1.2o %0012.O]\n", (unsigned char)12, 0, 123654789);
	printf("[VR][%d] - [ME][%d]\n", x1, x2);

	printf("\nTEST Nº : 3\n\n");

	x1 = 	printf("VR:: [test%#.4o et %02o %0#14.0o!!]\n", 012, 036, 12587499);
	x2 = ft_printf("ME:: [test%#.4o et %02o %0#14.0o!!]\n", 012, 036, 12587499);
	printf("[VR][%d] - [ME][%d]\n", x1, x2);
	return (0);
}
