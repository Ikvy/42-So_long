/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:08:45 by mmidon            #+#    #+#             */
/*   Updated: 2022/06/15 10:34:02 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_putnbr_p(unsigned long long x, char *base)
{
	int	c;

	c = 0;
	if (x < 16)
		c += ft_putcharv2(base[x]);
	else
	{
		c += ft_putnbr_p(x / 16, base);
		c += ft_putcharv2(base[x % 16]);
	}
	return (c);
}
