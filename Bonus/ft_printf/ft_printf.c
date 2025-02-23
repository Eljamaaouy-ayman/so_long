/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 20:44:50 by ael-jama          #+#    #+#             */
/*   Updated: 2024/12/01 16:30:57 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putexah(unsigned long nbr)
{
	char			*s;
	unsigned long	a;
	int				count;

	count = 0;
	if (nbr == 0)
	{
		count += ft_putstr("(nil)");
		return (count);
	}
	s = "0123456789abcdef";
	if (nbr > 15)
		count += ft_putexah(nbr / 16);
	a = nbr % 16;
	write(1, &s[a], 1);
	count++;
	return (count);
}

int	ft_putpoint(void *nbr)
{
	int	count;

	count = 0;
	if (nbr != 0)
		count += ft_putstr("0x");
	count += ft_putexah((unsigned long)nbr);
	return (count);
}

int	ft_helper(char s, va_list args)
{
	int	count;

	count = 0;
	if (s == '%')
		count += ft_putchar('%');
	else if (s == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (s == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (s == 'x')
		count += ft_putexa(va_arg(args, unsigned int));
	else if (s == 'X')
		count += ft_putexamaj(va_arg(args, unsigned int));
	else if (s == 'p')
		count += ft_putpoint(va_arg(args, void *));
	else if (s == 'd' || s == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (s == 'u')
		count += ft_putnbrunsigned(va_arg(args, int));
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	args;

	if (s == NULL)
		return (-1);
	i = 0;
	if (s[i] == '%' && !s[i + 1])
		return (-1);
	count = 0;
	va_start(args, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%' && ft_strchr("cspdiuxX%", s[i + 1]))
		{
			i++;
			count += ft_helper(s[i], args);
		}
		else
			count += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (count);
}
