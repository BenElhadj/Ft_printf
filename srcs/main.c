/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:07:53 by bhamdi            #+#    #+#             */
/*   Updated: 2018/10/09 17:46:43 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <limits.h>

int		main(void)
{
	printf("TEST Nº : 1\n\n");

	int r1 = 0, r2 = 0, x1 = 0, x2 = 0;
	r1 = 	printf("VR:: [%llu]\n", (unsigned long long)-12345612220);
	r2 = ft_printf("ME:: [%llu]\n", (unsigned long long)-12345612220);
	printf("[VR][%d] - [ME][%d]\n", r1, r2);

	printf("\nTEST Nº : 2\n\n");

	x1 = 	printf("VR:: [%08i]\n", -71);
	x2 = ft_printf("ME:: [%08i]\n", -71);
	printf("[VR][%d] - [ME][%d]\n", x1, x2);

	printf("\nTEST Nº : 2\n\n");

	x1 = 	printf("VR:: [%+10.4d]\n", 0);
	x2 = ft_printf("ME:: [%+10.4d]\n", 0);
	printf("[VR][%d] - [ME][%d]\n", x1, x2);
	return (0);
}
