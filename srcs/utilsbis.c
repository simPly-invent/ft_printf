/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsbis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenais <mobenais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 01:03:06 by mobenais          #+#    #+#             */
/*   Updated: 2025/11/20 12:52:29 by mobenais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putstr(char *str, int *nb)
{
	write(1, str, ft_strlen(str));
	*nb = *nb + ft_strlen(str);
}

int	ft_verif_addr(void *ptr, int r, int *nb)
{
	if (!ptr)
	{
		*nb += 5;
		return (write(1, "(nil)", 5));
	}
	ft_putnbr_baseaddr((unsigned long)ptr, r, nb);
	return (0);
}

void	ft_putnbr_baseaddr(unsigned long nbr, int r, int *nb)
{
	unsigned int	int_base;
	char			*base;

	if (r == 0)
		ft_putstr("0x", nb);
	base = "0123456789abcdef";
	int_base = ft_strlen(base);
	if (nbr >= int_base)
	{
		ft_putnbr_baseaddr(nbr / int_base, 1, nb);
	}
	ft_putchar(base[nbr % int_base], nb);
}

void	ft_print_nbrhexa(unsigned int nbr, char x, int *nb)
{
	char			*base;
	unsigned int	tab_int;

	base = NULL;
	tab_int = 16;
	if (x == 'X')
		base = "0123456789ABCDEF";
	else if (x == 'x')
		base = "0123456789abcdef";
	if (nbr >= tab_int)
		ft_print_nbrhexa(nbr / tab_int, x, nb);
	ft_putchar(base[nbr % tab_int], nb);
}
