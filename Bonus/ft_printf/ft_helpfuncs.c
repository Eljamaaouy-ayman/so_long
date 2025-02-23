/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpfuncs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:36:00 by ael-jama          #+#    #+#             */
/*   Updated: 2024/12/01 11:43:12 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	b;

	i = 0;
	b = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == b)
			return ((char *)(s + i));
		i++;
	}
	if (b == '\0')
		return ((char *)(s + i));
	return (NULL);
}

int	ft_putexa(unsigned int nbr)
{
	char			*s;
	unsigned int	a;
	int				count;

	count = 0;
	s = "0123456789abcdef";
	if (nbr > 15)
		count += ft_putexa(nbr / 16);
	a = nbr % 16;
	write(1, &s[a], 1);
	count++;
	return (count);
}

int	ft_putexamaj(unsigned int nbr)
{
	char			*s;
	unsigned int	a;
	int				count;

	count = 0;
	s = "0123456789ABCDEF";
	if (nbr > 15)
		count += ft_putexamaj(nbr / 16);
	a = nbr % 16;
	write(1, &s[a], 1);
	count++;
	return (count);
}

int	ft_putnbrunsigned(unsigned int n)
{
	char	c;
	int		count;

	count = 0;
	if (n > 9)
	{
		count += ft_putnbrunsigned(n / 10);
	}
	c = n % 10 + '0';
	write(1, &c, 1);
	count++;
	return (count);
}
