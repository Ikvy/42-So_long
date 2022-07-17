/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:09:30 by mmidon            #+#    #+#             */
/*   Updated: 2022/06/15 10:33:49 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_puthexa(char select, unsigned int x)
{
	char	*base;
	int		c;

	c = 0;
	if (select == 'x' || select == 'p')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (select == 'p')
		c += ft_putstrv2("0x");
	c += ft_putnbrhexa(x, base);
	return (c);
}
