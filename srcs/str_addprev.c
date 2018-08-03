/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_addprev.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 19:03:13 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/02 19:21:02 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
