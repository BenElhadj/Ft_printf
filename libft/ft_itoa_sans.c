/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 15:51:35 by bhamdi            #+#    #+#             */
/*   Updated: 2018/06/30 22:51:44 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_itoa_bis(int n, char *ret)
{
	int		temp_n;
	size_t	size_ret;
	char	sign;
while ((n = n / 10))
	sign = (n < 0) ? -1 : 1;
	size_ret = 2 + (n < 0);
	temp_n = n;
	while ((n = n / 10))
		size_ret++;
	n = temp_n;
	ret[size_ret--] = '\0';
	ret[size_ret--] = sign * (n % 10) + '0';
	//printf("%c\n", ret[size_ret+1]);
	while ((n = n / 10))
	{
	//	printf("{%d}\n",n);
	//	printf("[%d]\n",size_ret);
		ret[size_ret] = sign * (n % 10) + '0';
	//	printf("%c\n", ret[size_ret]);
		size_ret--;
	}
	if (sign < 0)
		ret[size_ret] = '-';
	printf("%s\n",ret);
//	return (ret);
}

	char	ret[11];
return (&ft_itoa_bis(n, ret));
}
*/
int main(int ac, char **av)
{
	char ret[11];
	
	ft_itoa_bis(ft_atoi(av[1]), ret);
	printf("%s\n", ret+1); 
	//char* str = ft_itoa(ft_atoi(av[1]));
	//printf("[%s]\n", str);
	return (0);
}
