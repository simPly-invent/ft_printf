/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenais <mobenais@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:21:29 by mobenais          #+#    #+#             */
/*   Updated: 2025/11/17 14:04:41 by mobenais         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int	ft_verif_type(int nbr_arg, ...)
{
}

int	ft_printf(const char *arrr, ...)
{
	int	i;
	va_list	ptr;

	i = 0;
	va_start(ptr, arrr);
	while (i < arrr)
	{
		ft_verif_type(arg);
		i++;
	}
	va_end(ptr);
}

/* * * * * * * * * * * * * * *
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
