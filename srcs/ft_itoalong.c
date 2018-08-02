/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 13:54:23 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/02 14:28:17 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*check_specialcase(long long int n)
{
	char *res;

	if (n == -9223372036854775807)
	{
		if ((res = ft_strdup("-9223372036854775807")))
			return (res);
		else
			put_error();
	}
	else if (n == 0)
	{
		if ((res = ft_strdup("0")))
			return (res);
		else
			put_error();
	}
	return (NULL);
}

static int	find_numlength(long long int n)
{
	int i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoalong(long long int n)
{
	char	*res;
	int		i;
	
	if ((res = check_specialcase(n)))
		return (res);
	i = find_numlength(n);
	if (n < 0)
		i++;
	if (!(res = ft_strnew(i)))
		put_error();
	if (n < 0)
	{
		res[0] = '-';
		n = n * (-1);
	}
	i--;
	while (n != 0)
	{
		res[i] = (char)(n % 10) + '0';
		i--;
		n /= 10;
	}
	return (res);
}
