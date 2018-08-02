/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 15:21:51 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/02 15:45:16 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define NFLAGS 5
# define NLENGTHS 6
# define NSPECIS 14

typedef struct	s_info
{
	int		flags[NFLAGS];
	int		width;
	int		preci;
	int		lengths[NLENGTHS];
	char	speci;
	va_list	*args;
	char	**str;
	int		count;
	char	*res;
	int		leftpadded;
	int		zeropadded;
}				t_info;

enum			e_flags
{
	Fminus,
	Fplus,
	Fspace,
	Fhash,
	Fzero
};

enum			e_lengths
{
	Lhh,
	Lh,
	Ll,
	Lll,
	Lj,
	Lz
};

int				ft_printf(char *str, ...);
void			reinit_struct(t_info *info);
void			check_flags(t_info *info);
void			check_widths(t_info *info);
void			check_precis(t_info *info);
void			check_lengths(t_info *info);
void			check_specis(t_info *info);
void			print_var(t_info *info);
int				is_flag(char c);
int				is_width(char c);
int				is_preci(char c);
int				is_length(char c);
int				is_speci(char c);
void			put_error(void);
void			reinit_lengths(t_info *info);
void			check_lengthspt2(t_info *info);
char			*ft_itoalong(long long int n);
char			*ft_utoabase(unsigned long long int n, 
		unsigned long long int base);

#endif
