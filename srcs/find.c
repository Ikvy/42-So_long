/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:29:04 by mmidon            #+#    #+#             */
/*   Updated: 2022/07/14 16:30:09 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

size_t	find_next_thing(char *map, size_t pos, char select)
{
	pos++;
	while (map[pos] != select && map[pos] && pos < ft_strlen(map))
		pos++;
	if (pos == ft_strlen(map))
		pos = 0;
	return (pos);
}

size_t	find_first_thing(char *map, char select)
{
	size_t	i;

	i = 0;
	while (map[i] != select && map[i])
		i++;
	return (i);
}
