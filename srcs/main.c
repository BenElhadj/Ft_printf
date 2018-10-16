/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:07:53 by bhamdi            #+#    #+#             */
/*   Updated: 2018/10/16 18:12:51 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <limits.h>

int		main(void)
{
	int data;
	int r1 = 0, r2 = 0, x1 = 0, x2 = 0;
	printf("TEST Nº : 1\n\n");

	r1 = 	printf("VR:: [%hho]\n", -22);
	r2 = ft_printf("ME:: [%hho]\n", -22);
	printf("[VR][%d] - [ME][%d]\n", r1, r2);

	printf("\nTEST Nº : 2\n\n");

	x1 = 	printf("VR:: [%ho]\n", -22);
	x2 = ft_printf("ME:: [%ho]\n", -22);
	printf("[VR][%d] - [ME][%d]\n", x1, x2);

	printf("\nTEST Nº : 3\n\n");

	x1 = 	printf("VR:: [%20p]\n", &data);
	x2 = ft_printf("ME:: [%20p]\n", &data);
	printf("[VR][%d] - [ME][%d]\n", x1, x2);
	return (0);
}
