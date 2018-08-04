/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_manipulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 21:07:26 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/03 21:09:13 by jcasian          ###   ########.fr       */
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
		i++;
	}
	free(str);
	return (res);
}

char	*str_addprev(char *prefix, char *str)
{
	int		i;
	int		j;
	char	*res;

	j = -1;
	i = ft_strlen(prefix) + ft_strlen(str);
	if (!(res = ft_strnew(i)))
		put_error();
	while (prefix[++j])
		res[j] = prefix[j];
	i = 0;
	while (str[i])
	{
		res[j] = str[i];
		i++;
		j++;
	}
	free(str);
	return (res);
}
