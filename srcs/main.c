/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:07:53 by bhamdi            #+#    #+#             */
/*   Updated: 2018/10/31 17:30:53 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <limits.h>

int		main(void)
{
	int x1 = 0, x2 = 0;
	printf("TEST Nº : 1\n\n");

x1 = 	printf("VR:: [%0##0.4X]\n",0x037a);
x2 = ft_printf("ME:: [%0##0.4X]\n",0x037a);
	printf("[VR][%d] - [ME][%d]\n", x1, x2);

	printf("\nTEST Nº : 2\n\n");

	x1 = 	printf("VR:: [%#.4X]\n", 0xaef);
	x2 = ft_printf("ME:: [%#.4X]\n", 0xaef);
	printf("[VR][%d] - [ME][%d]\n", x1, x2);

	printf("\nTEST Nº : 3\n\n");

	x1 = 	printf("VR:: [%#.22zX]\n",0xff1144ff1144);
	x2 = ft_printf("ME:: [%#.22zX]\n",0xff1144ff1144);
	printf("[VR][%d] - [ME][%d]\n", x1, x2);
	return (0);
}
