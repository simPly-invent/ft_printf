/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenais <mobenais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 18:39:19 by mobenais          #+#    #+#             */
/*   Updated: 2025/11/19 15:58:52 by mobenais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <stdint.h>
#include <unistd.h>
#include <stdint.h>

void	ft_putstr(char *str, int *nb);
void	ft_putnbr_baseaddr(unsigned long nbr, int r, int *nb);
void	ft_print_nbrhexa(unsigned int nbr, char x, int *nb);
void    ft_putchar(int c, int *nb);
char	ft_find_type(char c);
void	ft_putnbr(int nbr, int *nb);
void	ft_putnbr_uc(unsigned int nbr, int *nb);
int     ft_strlen(char *s);
int     ft_printf(const char *str, ...);
#endif
