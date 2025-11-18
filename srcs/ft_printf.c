/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenais <mobenais@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:21:29 by mobenais          #+#    #+#             */
/*   Updated: 2025/11/18 05:58:10 by mobenais         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "../include/libft.h"

static char	ft_find_type(char c)
{
	int	i;
	char *base;

	base = "cspdiuxX";
	i = 0;
	while (base[i])
	{
		if(base[i] == c)
			return (c);
		i++;
	}
	return 0;
}

void	exec_bloc(va_list ptr, char c)
{
	if (ft_find_type(c) == 'd')
		ft_putnbr(va_arg(ptr, int));
	else if(ft_find_type(c) == 'c')
		ft_putchar(va_arg(ptr, int));
	else if (ft_find_type(c) == 's')
		ft_putstr(va_arg(ptr, char *));
	else if (ft_find_type(c) == 'p')
		ft_putnbr_baseMIN(va_arg(ptr, unsigned int), 0);
	else if (ft_find_type(c) == 'i')
		ft_putnbr(va_arg(ptr, int));
	else if (ft_find_type(c) == 'u')
		ft_putnbr_uc(va_arg(ptr, unsigned int));
	else if (ft_find_type(c) == 'x')
		ft_print_nbrhexa(va_arg(ptr, unsigned int), c);
	else if (ft_find_type(c) == 'X')
		ft_print_nbrhexa(va_arg(ptr, unsigned int), c);
}

int	ft_printf(const char *str, ...)
{
	int	i;
	va_list	ptr;

	i = 0;
	va_start(ptr, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			exec_bloc(ptr, str[i + 1]);
		}
		i++;
	}
	va_end(ptr);
	return 1;
}

#include <stdio.h>
int main(void)
{
	unsigned int	i = 250;
	int n = 95;
	int k = 4;

	ft_printf("%X", i);
	ft_putchar('\n');
	printf("%X", i);
	return	(0);
}

