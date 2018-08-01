/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_tests.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 20:24:31 by jcasian           #+#    #+#             */
/*   Updated: 2018/07/31 20:41:24 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_flag(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0')
		return (1);
	return (0);
}

int	is_width(char c)
{
	if ((c >= '0' && c <= '9') || c == '*')
		return (1);
	return (0);
}

int	is_preci(char c)
{
	if (c == '.')
		return (1);
	return (0);
}

int	is_length(char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z')
		return (1);
	return (0);
}

int	is_speci(char c)
{
	if (c == '%' || c == 's' || c == 'S' || c == 'p' || c == 'd' ||
			c == 'D' || c == 'i' || c == 'o' || c == 'O' || c == 'u' ||
			c == 'U' || c == 'x' || c == 'X' || c == 'c' || c == 'C')
		return (1);
	return (0);
}
