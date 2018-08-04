/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 18:32:25 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/03 14:57:47 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reinit_struct(t_info *info)
{
	int i;

	i = -1;
	while (++i < NFLAGS)
		info->flags[i] = -1;
	info->width= -1;
	info->preci= -1;
	i = -1;
	while (++i < NLENGTHS)
		info->lengths[i] = -1;
	info->speci = '~';
	info->leftpadded = -1;
	info->zeropadded = -1;
	info->res = NULL;
	info->wres = NULL;
}

void	reinit_lengths(t_info *info)
{
	int	i;

	i = -1;
	while (++i < NLENGTHS)
		info->lengths[i] = -1;
}
