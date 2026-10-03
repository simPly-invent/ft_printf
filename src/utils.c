/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenais <mobenais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 22:56:10 by mobenais          #+#    #+#             */
/*   Updated: 2025/11/19 23:14:22 by mobenais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <limits.h>

void	ft_putchar(int c, int *nb)
{
	write(1, &c, 1);
	*nb = *nb + 1;
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putnbr(int nbr, int *nb)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		*nb = *nb + 11;
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar('-', nb);
		nbr = -nbr;
	}
	if (nbr >= 10)
		ft_putnbr(nbr / 10, nb);
	ft_putchar(nbr % 10 + '0', nb);
}

void	ft_putnbr_uc(unsigned int nbr, int *nb)
{
	if (nbr >= 10)
		ft_putnbr(nbr / 10, nb);
	ft_putchar(nbr % 10 + '0', nb);
}
