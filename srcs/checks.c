/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 19:20:39 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/01 19:26:28 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flags(t_info *info)
{
	while (is_flag(info->str[0][0]))
	{
		if (info->str[0][0] == '-')
			info->flags[Fminus] = 1;
		else if (info->str[0][0] == '+')
			info->flags[Fplus] = 1;
		else if (info->str[0][0] == ' ')
			info->flags[Fspace] = 1;
		else if (info->str[0][0] == '#')
			info->flags[Fhash] = 1;
		else if (info->str[0][0] == '0')
			info->flags[Fzero] = 1;
		(info->str[0])++;
	}
}

void	check_widths(t_info *info)
{
	while (is_width(info->str[0][0]))
	{
		if (info->str[0][0] >= '0' && info->str[0][0] <= '9')
		{
			info->width = ft_atoi(info->str[0]);
			while (info->str[0][0] >= '0' && info->str[0][0] <= '9')
				(info->str[0])++;
		}
		else if (info->str[0][0] == '*')
		{
			info->width = va_arg(info->args[0], int);
			(info->str[0])++;
		}
	}
}

void	check_precis(t_info *info)
{
	while (is_preci(info->str[0][0]))
	{
		(info->str[0])++;
		if (info->str[0][0] >= '0' && info->str[0][0] <= '9')
		{
			info->preci = ft_atoi(info->str[0]);
			while (info->str[0][0] >= '0' && info->str[0][0] <= '9')
				(info->str[0])++;
		}
		else if (info->str[0][0] == '*')
		{
			info->preci= va_arg(info->args[0], int);
			(info->str[0])++;
		}
		else if (info->str[0][0] != '-')
		{
			info->preci= 0;
			(info->str[0])++;
		}
		else
			(info->str[0])++;
	}
}

void	check_lengths(t_info *info)
{
	while (is_length(info->str[0][0]))
	{
		if (info->str[0][0] == 'h')
		{
			if (info->str[0][1] == 'h')
			{
				reinit_lengths(info);
				info->lengths[Lhh] = 1;
				(info->str[0])++;
			}
			else
			{
				reinit_lengths(info);
				info->lengths[Lh] = 1;
			}
		}
		else if (info->str[0][0] == 'j')
		{
			reinit_lengths(info);
			info->lengths[Lj] = 1;
		}
		else
			check_lengthspt2(info);
		(info->str[0])++;
	}
}

void	check_specis(t_info *info)
{
	if (is_speci(info->str[0][0]))
	{
		info->speci = info->str[0][0];
		(info->str[0])++;
	}
	else
		put_error();
}
