/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 03:46:04 by ebakchic          #+#    #+#             */
/*   Updated: 2022/02/24 03:46:18 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_calloc(int count, int size)
{
	char	*ptr;
	int		i;

	if (count == 0 || size == 0)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < (count * size))
		ptr[i++] = '\0';
	return (ptr);
}

int	ft_strchr(char *ptr)
{
	int	j;

	if (!ptr)
		return (0);
	j = 0;
	while (ptr[j] && ptr[j] != '\0')
	{
		if (ptr[j] == '\n')
			return (1);
		j++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_memcpy(char *dst, char *src, size_t n)
{
	size_t	i;

	if (n == 0)
		return (dst);
	if (!src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

char	*ft_strjoin(char *saver, char *buf)
{
	char	*ptr;

	ptr = ft_calloc(ft_strlen(saver) + ft_strlen(buf) + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, saver, ft_strlen(saver));
	ft_memcpy(ptr + ft_strlen(saver), buf, ft_strlen(buf));
	free(saver);
	return (ptr);
}
