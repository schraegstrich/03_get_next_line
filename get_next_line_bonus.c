/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkirillo <lkirillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:20:24 by lkirillo          #+#    #+#             */
/*   Updated: 2024/01/13 17:56:27 by lkirillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*remainder[MAX_FD];
	char		*line;
	char		*buffer;

	buffer = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(remainder[fd]);
		free(buffer);
		remainder[fd] = NULL;
		return (NULL);
	}
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = line_in_buffersize(fd, remainder[fd], buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
	{
		remainder[fd] = NULL;
		return (NULL);
	}
	remainder[fd] = left_after_line(line);
	return (line);
}

char	*left_after_line(char *line_buffer)
{
	char	*remainder;
	size_t	i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == '\0')
		return (0);
	remainder = ft_substr(line_buffer, i + 1,
			ft_strlen(line_buffer) - i);
	if (remainder[0] == '\0')
	{
		free(remainder);
		remainder = NULL;
	}
	line_buffer[i + 1] = '\0';
	return (remainder);
}

char	*line_in_buffersize(int fd, char *remainder, char *buffer)
{
	int		res_read;
	char	*temp;

	res_read = 1;
	while (res_read > 0)
	{
		res_read = read(fd, buffer, BUFFER_SIZE);
		if (res_read == -1)
		{
			free(remainder);
			return (0);
		}
		else if (res_read == 0)
			break ;
		buffer[res_read] = 0;
		if (!remainder)
			remainder = ft_strdup("");
		temp = remainder;
		remainder = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (remainder);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}

// #include <fcntl.h>
// #include <stdio.h>
// #include <unistd.h>
// int	main(void)
// {
// 	int fd = open ("ft_vibes.txt", O_RDONLY);
// 	printf("The line is %s\n", get_next_line(fd + 1));
// 	printf("The line is %s\n", get_next_line(fd + 2));
// 	printf("The line is %s\n", get_next_line(fd + 3));
// 	printf("The line is %s\n", get_next_line(fd + 4));
// 	return (0);
// }