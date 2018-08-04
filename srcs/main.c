/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 15:42:24 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/03 19:33:23 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{

	wchar_t  *s;
	s = (wchar_t*)malloc(sizeof(wchar_t) * 6);
	s[0] = 0x0438;
	s[1] = 0x0438;
	s[2] = 0x0438;
	s[3] = 0x0438;
	s[4] = 0x0438;
	s[5] = '\0';
	setlocale(LC_ALL, "");
	int i;
	int j;
	char *string = "hello";

//	while (1);
//
	   printf ("Characters: %c %c \n", 'a', 65);
   printf ("Decimals: %d %ld\n", 1977, 650000L);
   printf ("Preceding with blanks: %10d \n", 1977);
   printf ("Preceding with zeros: %010d \n", 1977);
   printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
   printf ("Width trick: %*d \n", 10, 10);
   printf ("%s \n", "string");
   printf("double  percent sign %%\n");
   printf("Pointer address %p or %#lx\n", &string, &string );

   ft_printf("------------------------------------------\n");

   
   ft_printf ("Characters: %c %c \n", 'a', 65);
   ft_printf ("Decimals: %d %D\n", 1977, 650000L);
   ft_printf ("Preceding with blanks: %10d \n", 1977);
   ft_printf ("Preceding with zeros: %010d \n", 1977);
   ft_printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
   ft_printf ("Width trick: %*d \n", 10, 10);
   ft_printf ("%s \n", "string");
   ft_printf("double  percent sign %%\n");
   ft_printf("Pointer address %p or %#lx\n", &string, &string );
   ft_printf ("Big S %S \n", L"h");         //representation letter as wide char

   ft_printf("------------------------------------------\n");
    	//Standard printf
	printf("%#10.7x, %#12o, % hhd, %c, %+.i, %-.i, %010u \n", 6996, 654, '*', 42, 21, -21, 99999999);

	//my printf
	ft_printf("%#10.7x, %#12o, % hhd, %c, %+.i, %-.i, %010u \n", 6996, 654, '*', 42, 21, -21, 99999999);

    ft_printf("------------------------------------------\n");

    ft_printf("%%\n");
    ft_printf("%d\n", 42);
    ft_printf("%d%d\n", 42, 41);
    ft_printf("%d%d%d\n", 42, 43, 44);
    ft_printf("%ld\n", 2147483647);
    ft_printf("%lld\n", 9223372036854775807);
    ft_printf("%x\n", 505);
    ft_printf("%X\n", 505);
    ft_printf("%p\n", &ft_printf);
    ft_printf("%20.15d\n", 54321);
    ft_printf("%-10d\n", 3);
    ft_printf("% d\n", 3);
    ft_printf("%+d\n", 3);
    ft_printf("%010d\n", 1);
    ft_printf("%hhd\n", 0);
    ft_printf("%jd\n", 9223372036854775807);
    ft_printf("%zd\n", 4294967295);
    ft_printf("%U\n", 4294967295);
    ft_printf("%u\n", 4294967295);
    ft_printf("%o\n", 40);
    ft_printf("%%#08x\n", 42);
    printf("%%#08x\n", 42);
    ft_printf("%x\n", 1000);
    ft_printf("%#X\n", 1000);
    ft_printf("%s\n", NULL);
    ft_printf("%s%s\n", "test", "test");
     ft_printf("%s%s%s\n", "test", "test", "test");
    ft_printf("%b\n",4);
    ft_printf("%C\n", 42);
	return (0);
}
