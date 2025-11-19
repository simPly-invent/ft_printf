/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenais <mobenais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:21:29 by mobenais          #+#    #+#             */
/*   Updated: 2025/11/19 15:09:41 by mobenais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "../include/ft_printf.h"



static void	exec_bloc(va_list ptr, char c, int *nb)
{
	if (ft_find_type(c) == 'd')
		ft_putnbr(va_arg(ptr, int), nb);
	else if(ft_find_type(c) == 'c')
		ft_putchar((char)va_arg(ptr, int), nb);
	else if (ft_find_type(c) == 's')
		ft_putstr(va_arg(ptr, char *), nb);
	else if (ft_find_type(c) == 'p')
		ft_putnbr_baseaddr(va_arg(ptr, unsigned long), 0, nb);
	else if (ft_find_type(c) == 'i')
		ft_putnbr(va_arg(ptr, int), nb);
	else if (ft_find_type(c) == 'u')
		ft_putnbr_uc(va_arg(ptr, unsigned int), nb);
	else if (ft_find_type(c) == 'x')
		ft_print_nbrhexa(va_arg(ptr, unsigned int), c, nb);
	else if (ft_find_type(c) == 'X')
		ft_print_nbrhexa(va_arg(ptr, unsigned int), c, nb);
}

int	ft_printf(const char *str, ...)
{
	int	i;
	va_list	ptr;
	int	len;

	i = 0;
	len = 0;
	va_start(ptr, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1])
			{
				i++;
				exec_bloc(ptr, str[i], &len);
			}
		}
		else
		{
			ft_putchar(str[i], &len);
		}
		i++;
	}
	va_end(ptr);
	return (len);
}

// #include <stdio.h>
// int main(void)
// {
// 	char *s = "sardoche";

// 	printf("%d\n", ft_printf("%s", s));
// 	printf("%d\n", printf("%s", s));
// 	return	(0);
// }

