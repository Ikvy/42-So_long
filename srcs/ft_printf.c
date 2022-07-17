/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 09:33:40 by mmidon            #+#    #+#             */
/*   Updated: 2022/06/15 10:32:53 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_to_many_lines(va_list *zoui, const char format)
{
	int	c;

	c = 0;
	if (format == 'c')
		c += ft_putcharv2(va_arg(*zoui, int));
	if (format == 's')
		c += ft_putstrv2(va_arg(*zoui, char *));
	if (format == 'd' || format == 'i')
		c += ft_putnbrv2(va_arg(*zoui, int));
	if (format == 'u')
		c += ft_putnbru2(va_arg(*zoui, unsigned int));
	if (format == 'x' || format == 'X')
		c += ft_puthexa(format, va_arg(*zoui, unsigned int));
	if (format == 'p')
		c += ft_put_p(format, va_arg(*zoui, unsigned long));
	if (format == '%')
		c += ft_putcharv2('%');
	return (c);
}

int	ft_printf(const char *format, ...)
{
	va_list	zoui;
	int		counter;

	counter = 0;
	va_start(zoui, format);
	while (*format)
	{
		if (*format == '%')
			counter += ft_to_many_lines(&zoui, *(++format));
		else
			counter += ft_putcharv2(*format);
		format++;
	}
	va_end(zoui);
	return (counter);
}
