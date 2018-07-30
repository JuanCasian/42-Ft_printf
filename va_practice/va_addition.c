/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_addition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 15:04:15 by jcasian           #+#    #+#             */
/*   Updated: 2018/07/30 15:12:23 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int	va_addition(int n_elems, ...)
{
	int		sum;
	va_list	argptr;
	int		i;

	sum = 0;
	i = 0;
	va_start(argptr, n_elems);
	while (i < n_elems)
	{
		sum += va_arg(argptr, int);
		i++;
	}
	va_end(argptr);
	return (sum);
}

int	main(void)
{
	printf("Result of 3 args: %i\n", va_addition(3, 100, 200, 300));
	printf("Result of 5 args: %i\n", va_addition(5, 1, 2, 3, 4, 5));
	printf("Result of 7 args: %i\n", va_addition(7, 0, 0, 0, 0, 0, 0, 5));
	printf("Result of 10 args: %i\n", va_addition(10, 10, 10, 10, 10, 10,
				10, 10, 10, 10, 10));
	return (0);
}
