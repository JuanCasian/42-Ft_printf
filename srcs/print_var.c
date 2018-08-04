/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 19:23:59 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/03 19:21:41 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	divide_byspeci(t_info *info)
{
	if (info->speci == 'U' || info->speci == 'u' || info->speci == 'o' ||
			info->speci == 'x' || info->speci == 'X' || info->speci == 'O' ||
			info->speci == 'b')
		handle_gunsigneds(info);
	else if (info->speci == 'd' || info->speci == 'i' || info->speci == 'D')
		handle_gsigneds(info);
	else if (info->speci == 's' || info->speci == 'S')
		handle_gstrs(info);		
	else  if (info->speci == 'p' || info->speci == 'P')
		handle_gaddress(info);
	else if (info->speci == '%')
		info->res = ft_strdup("%");
	else if (info->speci == 'c' || info->speci == 'C')
		handle_gchars(info);
}

void	print_var(t_info *info)
{
	int i;

	i = -1;
	divide_byspeci(info);
	apply_preci(info);
	apply_flags(info);
	apply_width(info);
	if (info->speci == 'S' || info->speci == 'C' || (info->lengths[Ll] == 1 &&
				(info->speci == 's' || info->speci == 'c')))
	{
		while(info->wres[++i])
			info->count += ft_putwchar(info->wres[i]);
		free(info->wres);
	}
	else
	{
		while (info->res[++i])
			ft_putchar(info->res[i]);
		free(info->res);
		info->count += i;
	}
}
