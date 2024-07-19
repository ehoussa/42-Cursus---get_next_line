/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 03:43:08 by ebakchic          #+#    #+#             */
/*   Updated: 2022/02/24 03:43:25 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*ft_calloc(int count, int size);
int		ft_strchr(char *ptr);
int		ft_strlen(char *ptr);
char	*ft_memcpy(char *dst, char *src, size_t n);
char	*ft_strjoin(char *saver, char *buf);
char	*get_next_line(int fd);

#endif
