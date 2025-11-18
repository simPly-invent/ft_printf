/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenais <mobenais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 18:39:19 by mobenais          #+#    #+#             */
/*   Updated: 2025/11/18 18:16:54 by mobenais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <stdint.h>
#include <unistd.h>

void	ft_putchar(char c);
int		ft_strlen(char *s);
void	ft_putnbr(int nbr);
void	ft_putnbr_uc(unsigned int nbr);
void	ft_print_nbrhexa(unsigned int nbr, char x);
void	ft_putnbr_base(void *nbr, int r);
void	ft_putstr(char *s);
int	ft_calcpower(int n);
int	ft_stack_value(int nbr);


#endif
