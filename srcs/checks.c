/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 19:20:39 by jcasian           #+#    #+#             */
/*   Updated: 2018/07/31 20:51:08 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flags(t_info *info)
{
	while (is_flag(info->str[0][0]))
	{
		ft_putendl("Flag found");
		(info->str[0])++;
	}
}

void	check_widths(t_info *info)
{
	while (is_width(info->str[0][0]))
	{
		ft_putendl("Width found");
		(info->str[0])++;
	}
}

void	check_precis(t_info *info)
{
	while (is_preci(info->str[0][0]))
	{
		ft_putendl("Preci found");
		(info->str[0])++;
	}
}

void	check_lengths(t_info *info)
{
	while (is_length(info->str[0][0]))
	{
		ft_putendl("Length found");
		(info->str[0])++;
	}
}

void	check_specis(t_info *info)
{
	if (is_speci(info->str[0][0]))
	{
		ft_putendl("Speci found");
		(info->str[0])++;
	}
}
