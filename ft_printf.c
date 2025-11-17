/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenais <mobenais@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:21:29 by mobenais          #+#    #+#             */
/*   Updated: 2025/11/17 18:37:28 by mobenais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

static char	ft_find_type(char c)
{
	int	i;
	char *base;

	base = "cspdiuxX%";
	i = 0;
	while (base[i])
	{
		if(base[i] == c)
			return ((char)base[i]);
		i++;
	}
	return 0;
}

void	exec_bloc(va_list ptr, char c)
{

	if (ft_find_type(c) == 'd')
		va_arg(ptr, int);
	else if (ft_find_type(c) == 'c')
		ft_putchar(va_arg(ptr, int));
	if (ft_find_type(c) == 's')
		ft_putstr_fd(va_arg(ptr, char *), 1);
	else if (ft_find_type(c) == 'p')
		ft_putnbr_base(va_arg(ptr, void *));
	else if (ft_find_type(c) == 'i')
		ft_putnbr_integer(va_arg(ptr, int));
	else if (ft_find_type(c) == 'u')
		ft_putnbr_uc(va_arg(ptr, unsigned int));
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
}


int main(void)
{
	const char *str = "oui";
	ft_printf("%s", str);
	return	(0);
}


/* 

 * * * * * * * * * * * * * * *
 *	oui c'est beau	     *
 *                           *
 * * exemple d'utilisation * *

#include <stdio.h>
#include <stdarg.h>
main()
{
   float moyenne(int nombre, ...);
   printf("moyenne = %f\n", moyenne(4, 1, 2, 3, 4));
   printf("moyenne = %f\n",
           moyenne(5, 1, 2, 3, 4, 5));
}
float moyenne(int nombre, ...)
{
   int somme = 0, i;
   va_list arg;
   va_start(arg, nombre);
   for(i=0; i < nombre; i++)
     somme += va_arg(arg, int);
   va_end(arg);
   return somme/nombre;
}
*/
