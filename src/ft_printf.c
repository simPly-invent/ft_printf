/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenais <mobenais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:21:29 by mobenais          #+#    #+#             */
/*   Updated: 2025/11/22 22:30:53 by mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

static void	exec_bloc(va_list ptr, char c, int *nb)
{
	if (c == 'd')
		ft_putnbr(va_arg(ptr, int), nb);
	else if (c == 'c')
		ft_putchar((char)va_arg(ptr, int), nb);
	else if (c == 's')
		ft_verif_str(va_arg(ptr, char *), nb);
	else if (c == 'p')
		ft_verif_addr(va_arg(ptr, void *), 0, nb);
	else if (c == 'i')
		ft_putnbr(va_arg(ptr, int), nb);
	else if (c == 'u')
		ft_putnbr_uc(va_arg(ptr, unsigned int), nb);
	else if (c == 'x')
		ft_print_nbrhexa(va_arg(ptr, int), c, nb);
	else if (c == 'X')
		ft_print_nbrhexa(va_arg(ptr, int), c, nb);
	else if (c == '%')
	{
		*nb += 1;
		write(1, "%", 1);
	}
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	ptr;
	int		len;

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
/*
#include <stdio.h>
int main(void)
{
	int a = 13;
	void *b;
	char c = 'c';
	int x = -1;
	int X = -1;
	char *s = NULL;
 	printf("%d\n", ft_printf("my printf : \nint d :%d\nvoid * : %p\nchar : %c\nHexIntMin %x\nHexIntMaj : %X\n pourcents : %%\n", a, b, c, x, X));
	ft_printf(" NULL %s NULL\n", s);
	printf("----------------------------------\n");
 	printf("%d\n", printf("rl printf : \nint d :%d\nvoid * : %p\nchar : %c\nHexIntMin %x\nHexIntMaj : %X\n pourcents : %%\n", a, b, c, x, X));
	printf(" NULL %s NULL\n", s);
 	return	(0);
}
*/
