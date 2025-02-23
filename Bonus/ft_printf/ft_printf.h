/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:36:28 by ael-jama          #+#    #+#             */
/*   Updated: 2024/12/01 10:35:41 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *s, ...);
int		ft_putstr(char *s);
int		ft_putchar(char c);
char	*ft_strchr(const char *s, int c);
int		ft_putexa(unsigned int nbr);
int		ft_putexamaj(unsigned int nbr);
int		ft_putnbrunsigned(unsigned int n);
int		ft_putnbr(int n);

#endif