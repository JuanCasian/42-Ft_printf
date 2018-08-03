/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 15:42:24 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/02 21:07:28 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	char *str;
	int i;
	int j;
	int c;

	c = L'и';
	str = "Hello World";
	printf("-----Original Result------\n");

	i = printf("%lc\n", c);

	printf("Chars printed %d\n", i);
	printf("-------YOUR  Result-------\n");

	j = ft_printf("%lc\n", c);

	printf("Chars printed %d\n", j);
//	while (1);
	return (0);
}
