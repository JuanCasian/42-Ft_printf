/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_addsuf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 19:10:15 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/02 19:16:52 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*str_addsuf(char *suffix, char *str)
{
	char	*res;
	int		i;
	int		j;

	i = ft_strlen(suffix) + ft_strlen(str);
	if (!(res = ft_strnew(i)))
		put_error();
	j = -1;
	i = 0;
	while (str[++j])
		res[j] = str[j];
	while (suffix[i])
	{
		res[j] = suffix[i];
	}
	free(str);
	return (res);
}
