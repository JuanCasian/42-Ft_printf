/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 20:14:21 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/03 21:14:18 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strtoupper(char **str)
{
	int i;

	i = -1;
	while (str[0][++i])
		str[0][i] = ft_toupper(str[0][i]);
}
