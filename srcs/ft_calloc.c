/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:20:12 by mmidon            #+#    #+#             */
/*   Updated: 2022/07/11 14:31:46 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	res = (void *)malloc (size * count);
	if (!res)
		return (NULL);
	ft_bzero(res, count * size);
	return (res);
}
