#include "../include/printf.h"
#include <unistd.h>

void ft_putchar(int c, int *nb)
{
	write(1, &c, 1);
    *nb = *nb + 1;

}

char	ft_find_type(char c)
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
		write(1, "-2147483648", 11) ;
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