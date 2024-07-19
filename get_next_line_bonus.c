/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 03:41:45 by ebakchic          #+#    #+#             */
/*   Updated: 2022/02/24 04:39:23 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h" 

char	*ft_linechr(char *saver)
{
	int		i;
	char	*str;

	i = 0;
	if (!saver[0])
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
	char	*buf;
	int		rb;

	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	rb = 1;
	while (ft_strchr(saver) == 0 && rb != 0)
	{
		rb = read(fd, buf, BUFFER_SIZE);
		if (rb == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[rb] = '\0';
		saver = ft_strjoin(saver, buf);
	}
	free(buf);
	return (saver);
}

char	*get_next_line(int fd)
{
	static char	*saver[1024];
	char		*retur;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	saver[fd] = ft_read(fd, saver[fd]);
	if (!saver[fd])
		return (NULL);
	retur = ft_linechr(saver[fd]);
	saver[fd] = ft_save(saver[fd]);
	return (retur);
}
