/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenais <mobenais@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 01:03:06 by mobenais          #+#    #+#             */
/*   Updated: 2025/11/18 05:57:37 by mobenais         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putnbr_baseMIN(unsigned int nbr, int r)
{
	unsigned int	int_base;
    char    *base;

	if (r == 0)
	{
		ft_putstr("0x");
	}
    base = "0123456789abcdef";
	int_base = ft_strlen(base);
	if (nbr >= int_base)
	{
		ft_putnbr_baseMIN(nbr / int_base, 1);
	}
	ft_putchar(base[nbr % int_base]);
}

void	ft_putnbr_baseMAJ(unsigned int nbr, int r)
{
	unsigned int	int_base;
    char    *base;

	if (r == 0)
	{
		ft_putstr("0x");
	}
    base = "0123456789ABCDEF";
	int_base = ft_strlen(base);
	if (nbr >= int_base)
	{
		ft_putnbr_baseMAJ(nbr / int_base, 1);
	}
	ft_putchar(base[nbr % int_base]);
}

void	ft_putnbr(int nbr)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + '0');
}

void	ft_putnbr_uc(unsigned int nbr)
{
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + '0');
}

void	ft_print_nbrhexa(unsigned int nbr, char x)
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
		ft_print_nbrhexa(nbr / tab_int, x);
	ft_putchar(base[nbr %  tab_int]);
}
