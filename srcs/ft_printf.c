/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenais <mobenais@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:21:29 by mobenais          #+#    #+#             */
/*   Updated: 2025/11/18 18:23:26 by mobenais         ###   ########.fr       */
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
	return (0);
}

int	exec_bloc(va_list ptr, char c)
{
	if (ptr == NULL)
		return (0);
	if (ft_find_type(c) == 'd')
	{
		ft_putnbr(va_arg(ptr, int));
	}
//	else if(ft_find_type(c) == 'c')
//		ft_putchar(va_arg(ptr, int));
//	else if (ft_find_type(c) == 's')
//		ft_putstr(va_arg(ptr, char *));
	else if (ft_find_type(c) == 'p')
	{
		uintptr_t	p2;

		p2 = (uintptr_t)ptr;
		ft_putnbr_base(va_arg(ptr, uintptr_t), 0);
	}
//	else if (ft_find_type(c) == 'i')
//		ft_putnbr(va_arg(ptr, int));
//	else if (ft_find_type(c) == 'u')
//		ft_putnbr_uc(va_arg(ptr, unsigned int));
//	else if (ft_find_type(c) == 'x')
//		ft_print_nbrhexa(va_arg(ptr, unsigned int), c);
//	else if (ft_find_type(c) == 'X')
//		ft_print_nbrhexa(va_arg(ptr, unsigned int), c);
	return 1;
}

int	ft_printf(const char *str, ...)
{
	int	i;
	int	len;
	va_list	ptr;

	i = 0;
	len = 0;
	va_start(ptr, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] != 0)
			{
				exec_bloc(ptr, str[i]);
			}
			len =len + 1;
		}
		else
		{
			ft_putchar(str[i]);
			len++;
		}
		i++;
	}
	va_end(ptr);
	return (len);
}

#include <stdio.h>
int main(void)
{
	void *p;
	int n = 950;
	int k = 400;

	ft_printf("%p, %d, %d", p, n, k);
	ft_putchar('\n');
	printf("%p, %d, %d", p, n, k);
	return	(0);
}

