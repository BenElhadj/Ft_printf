/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:07:53 by bhamdi            #+#    #+#             */
/*   Updated: 2018/10/11 15:40:23 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <limits.h>

int		main(void)
{
	int r1 = 0, r2 = 0, x1 = 0, x2 = 0;
	printf("TEST Nº : 1\n\n");

	r1 = 	printf("VR:: [%o]\n", 0);
	r2 = ft_printf("ME:: [%o]\n", 0);
	printf("[VR][%d] - [ME][%d]\n", r1, r2);

	printf("\nTEST Nº : 2\n\n");

	x1 = 	printf("VR:: [%o]\n", 145);
	x2 = ft_printf("ME:: [%o]\n", 145);
	printf("[VR][%d] - [ME][%d]\n", x1, x2);

	printf("\nTEST Nº : 3\n\n");

	x1 = 	printf("VR:: [%o]\n", -123654789);
	x2 = ft_printf("ME:: [%o]\n", -123654789);
	printf("[VR][%d] - [ME][%d]\n", x1, x2);
	return (0);
}
