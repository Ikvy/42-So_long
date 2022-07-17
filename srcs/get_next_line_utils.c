/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:30:11 by mmidon            #+#    #+#             */
/*   Updated: 2022/06/17 14:02:54 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

size_t	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (s[i])
	{
		if (str[i] == (char)c)
		{
			return ((char *)s + i);
		}
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	int	i;

	i = 0;
	if (dstsize > 0)
	{
		while (dstsize > 1 && src[i])
		{
			dst[i] = src[i];
			i++;
			dstsize--;
		}
		dst[i] = 0;
	}
	while (src[i] != 0)
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	if (!src)
		return (dest);
	if (!dest)
		return (src);
	i = ft_strlen(dest);
	j = 0;
	while (src[j])
	{
		dest[j + i] = src[j];
		j++;
	}
	dest[i + j] = 0;
	return (dest);
}

char	*ft_strdup(char	*src)
{
	char	*cp;
	int		i;

	i = 0;
	cp = malloc(sizeof(char) * (ft_strlen(src) + 1));
	while (src[i])
	{
		cp[i] = src[i];
		i++;
	}
	cp[i] = 0;
	return (cp);
}
