/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 15:09:07 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/02 15:45:51 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	find_numlength(unsigned long long int n, int base)
{
	int i;

	i = 0;
	while (n != 0)
	{
		n /= base;
		i++;
	}
	return (i);
}

static char	*is_zero(unsigned long long int n)
{
	char *res;

	if (n == 0)
	{
		if ((res = ft_strdup("0")))
			return (res);
		else
			put_error();
	}
	return (NULL);
}

static char	find_char(unsigned long long int n)
{
	char	vals[16];
	int		i;

	i = -1;
	while (++i < 10)
		vals[i] = (char)(i + '0');
	vals[10] = 'a';
	vals[11] = 'b';
	vals[12] = 'c';
	vals[13] = 'd';
	vals[14] = 'e';
	vals[15] = 'f';
	return (vals[n]);
}

char		*ft_utoabase(unsigned long long int n, unsigned long long int base)
{
	char	*res;
	int		i;

	if ((res = is_zero(n)))
		return (res);
	i = find_numlength(n, base);
	if (!(res = ft_strnew(i)))
		put_error();
	i--;
	while (n != 0)
	{
		res[i] = find_char(n % base);
		i--;
		n /= base;
	}
	return (res);
}
