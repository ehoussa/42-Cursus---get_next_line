/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 03:43:30 by ebakchic          #+#    #+#             */
/*   Updated: 2022/02/24 04:04:29 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

char	*ft_calloc(int count, int size);
int		ft_strchr(char *ptr);
int		ft_strlen(char *ptr);
char	*ft_memcpy(char *dst, char *src, size_t n);
char	*ft_strjoin(char *saver, char *buf);
char	*get_next_line(int fd);

#endif
