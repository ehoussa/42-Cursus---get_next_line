/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 03:41:09 by ebakchic          #+#    #+#             */
/*   Updated: 2022/02/24 14:30:55 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_linechr(char *saver)
{
	int		i;
	char	*str;

	i = 0;
	if (!saver[i])
		return (NULL);
	while (saver[i] && saver[i] != '\n')
		i++;
	str = ft_calloc(sizeof(char), i + 2);
	if (!str)
		return (NULL);
	ft_memcpy(str, saver, i + 1);
	return (str);
}

char	*ft_save(char *saver)
{
	int		i;
	char	*str;

	i = 0;
	while (saver[i] && saver[i] != '\n')
		i++;
	if (saver[i] == '\0')
	{
		free(saver);
		return (NULL);
	}
	str = ft_calloc(sizeof(char), ft_strlen(saver) - i + 1);
	if (!str)
		return (NULL);
	i++;
	ft_memcpy(str, saver + i, ft_strlen(saver) - i);
	free(saver);
	return (str);
}

char	*ft_read(int fd, char *saver)
{
	char	*buff;
	int		rb;

	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (NULL);
	rb = 1;
	while (ft_strchr(saver) == 0 && rb != 0)
	{
		rb = read(fd, buff, BUFFER_SIZE);
		if (rb == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rb] = '\0';
		saver = ft_strjoin(saver, buff);
	}
	free(buff);
	return (saver);
}

char	*get_next_line(int fd)
{
	static char	*saver;
	char		*retur;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saver = ft_read(fd, saver);
	if (!saver)
		return (NULL);
	retur = ft_linechr(saver);
	saver = ft_save(saver);
	return (retur);
}
