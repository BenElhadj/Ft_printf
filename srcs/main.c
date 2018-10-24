/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:07:53 by bhamdi            #+#    #+#             */
/*   Updated: 2018/10/24 21:27:51 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <limits.h>

int		main(void)
{
	int x1 = 0, x2 = 0;
	printf("TEST Nº : 1\n\n");

	x1 = 	printf("VR:: [%04.2o] [%#2o] [%#-8.3o]\n", 0,0,0);
	x2 = ft_printf("ME:: [%04.2o] [%#2o] [%#-8.3o]\n", 0,0,0);
	printf("[VR][%d] - [ME][%d]\n", x1, x2);

	printf("\nTEST Nº : 2\n\n");

	x1 = 	printf("VR:: [%#5.4o] et [%3.4o] [%012O]\n", 22, 0, 123654789);
	x2 = ft_printf("ME:: [%#5.4o] et [%3.4o] [%012O]\n", 22, 0, 123654789);
	printf("[VR][%d] - [ME][%d]\n", x1, x2);

	printf("\nTEST Nº : 3\n\n");

	x1 = 	printf("VR:: [test[%#.5o] et [%02o] [%0#14.o]!!]\n", 015, 036, 12587499);
	x2 = ft_printf("ME:: [test[%#.5o] et [%02o] [%0#14.o]!!]\n", 015, 036, 12587499);
	printf("[VR][%d] - [ME][%d]\n", x1, x2);
	return (0);
}
