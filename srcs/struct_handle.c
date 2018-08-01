/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 18:32:25 by jcasian           #+#    #+#             */
/*   Updated: 2018/07/31 18:50:27 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reinit_struct(t_info *info)
{
	int i;

	i = -1;
	while (++i < NFLAGS)
		info->flags[i] = -1;
	i = -1;
	while (++i < NWIDTHS)
		info->widths[i] = -1;
	i = -1;
	while (++i < NPRECIS)
		info->precis[i] = -1;
	i = -1;
	while (++i < NLENGTHS)
		info->lengths[i] = -1;
	i = -1;
	while (++i < NSPECIS)
		info->specis[i] = -1;
}
