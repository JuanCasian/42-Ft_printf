/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoabaseuintmax.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 13:58:44 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/05 13:59:03 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digits(uintmax_t n, uintmax_t base)
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

static char	get_char(uintmax_t n)
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

static char	*is_zero(uintmax_t n)
{
	char	*res;

	if (n != 0)
		return (NULL);
	if (!(res = ft_strdup("0")))
		print_error();
	return (res);
}


char		*ft_utoabaseuintmax(uintmax_t n, uintmax_t base)
{
	char	*res;
	int		i;

	if ((res = is_zero(n)))
		return (res);
	i = count_digits(n, base);
	if (!(res = ft_strnew(i)))
		print_error();
	i--;
	while (n != 0)
	{
		res[i] = get_char(n % base);
		i--;
		n /= base;
	}
	return (res);
}
