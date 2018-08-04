/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 15:39:27 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/03 20:41:05 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_and_print(t_info *info)
{
	(info->str[0])++;
	check_flags(info);
	check_widths(info);
	check_precis(info);
	check_lengths(info);
	check_specis(info);
	get_andprint(info);
	reinit_struct(info);
}

int			ft_printf(char *str, ...)
{
	t_info	*info;
	va_list	args;
	int		count;

	setlocale(LC_ALL, "");
	if (!(info = (t_info*)malloc(sizeof(t_info))) || !(str))
		put_error();
	va_start(args, str);
	info->args = &args;
	info->str = &str;
	info->count = 0;
	reinit_struct(info);
	while (info->str[0][0])
		if (info->str[0][0] != '%')
		{
			ft_putchar(info->str[0][0]);
			(info->str[0])++;
			info->count++;
		}
		else
			check_and_print(info);
	count = info->count;
	free(info);
	va_end(args);
	return (count);
}
