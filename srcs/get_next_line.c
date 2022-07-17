/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:02:14 by mmidon            #+#    #+#             */
/*   Updated: 2022/06/28 14:02:07 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	*get_backup_cut(char *backup, char *line)
{
	size_t	line_size;
	size_t	bcp_size;
	char	*backup_cut;

	if (backup == NULL || line == NULL)
		return (NULL);
	line_size = ft_strlen(line);
	bcp_size = ft_strlen(backup);
	if (line_size <= 0)
	{
		free(backup);
		return (NULL);
	}
	backup_cut = malloc(sizeof(char) * bcp_size - line_size + 1);
	ft_strlcpy(backup_cut, backup + line_size, bcp_size - line_size + 1);
	free(backup);
	return (backup_cut);
}

static char	*get_line(char *backup)
{
	char	*line;
	size_t	bcp_size;
	size_t	cut;

	if (!backup)
		return (NULL);
	bcp_size = ft_strlen(backup);
	cut = ft_strlen(ft_strchr(backup, '\n'));
	line = malloc(sizeof(char) * (bcp_size - cut + 3));
	ft_strlcpy(line, backup, bcp_size - cut + 2);
	return (line);
}

static char	*get_backup(char *backup, char *tmp)
{
	size_t	bcp_size;
	size_t	tmp_size;
	char	*new_bcp;

	if (!backup || !tmp)
		return (NULL);
	bcp_size = ft_strlen(backup);
	tmp_size = ft_strlen(tmp);
	new_bcp = malloc(sizeof(char) * bcp_size + tmp_size + 1);
	ft_strlcpy(new_bcp, backup, bcp_size + 1);
	ft_strcat(new_bcp, tmp);
	free(backup);
	return (new_bcp);
}

static char	*get_new_line(int fd, char *backup)
{
	char	*tmp;
	int		rd;

	tmp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!tmp)
	{
		free (backup);
		return (NULL);
	}
	rd = 42;
	while (rd != 0 && !ft_strchr(backup, '\n'))
	{
		rd = read(fd, tmp, BUFFER_SIZE);
		if (rd == -1)
		{
			free (tmp);
			free (backup);
			return (NULL);
		}
		tmp[rd] = 0;
		backup = get_backup(backup, tmp);
	}
	free(tmp);
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup[255];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 255)
		return (NULL);
	if (!backup[fd])
		backup[fd] = ft_strdup("");
	backup[fd] = get_new_line(fd, backup[fd]);
	if (!backup[fd])
		return (NULL);
	line = get_line(backup[fd]);
	backup[fd] = get_backup_cut(backup[fd], line);
	if (line[0] == 0 || line == NULL)
	{
		free (backup[fd]);
		free (line);
		return (NULL);
	}
	return (line);
}
