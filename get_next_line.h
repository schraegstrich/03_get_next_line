/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkirillo <lkirillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:20:16 by lkirillo          #+#    #+#             */
/*   Updated: 2024/01/13 15:50:36 by lkirillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*left_after_line(char *line_buffer);
char	*line_in_buffersize(int fd, char *remainder, char *buffer);

char	*ft_strdup(const char *str1);
void	*ft_memcpy(void *dst, const void *src, int n);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strlen(const char *str);

#endif
