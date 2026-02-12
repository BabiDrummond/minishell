/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:38:55 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/18 17:20:56 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

static size_t	gnl_strchr(char *s, char c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		if (s[i++] == c)
			return (i);
	return (0);
}

static char	*read_buffer(char *buffer, int fd)
{
	char	*temp;
	int		bytes;

	bytes = 1;
	if (!buffer)
		return (NULL);
	while (!gnl_strchr(buffer, '\n') && bytes > 0)
	{
		temp = malloc(BUFFER_SIZE + 1);
		if (!temp)
			return (NULL);
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buffer), free(temp), NULL);
		temp[bytes] = '\0';
		buffer = ft_strjoin_free(buffer, temp);
		if (!buffer)
			return (free(buffer), free(temp), NULL);
	}
	return (buffer);
}

static char	*read_line(char *buffer, char **line)
{
	char	*left;
	size_t	line_size;

	line_size = gnl_strchr(buffer, '\n');
	if (!line_size)
		line_size = ft_strlen(buffer);
	*line = ft_substr(buffer, 0, line_size);
	if (!*line)
		return (free(buffer), NULL);
	left = ft_substr(buffer, line_size, ft_strlen(buffer));
	if (!left)
		return (free(buffer), NULL);
	free(buffer);
	return (left);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_strdup("");
	buffer[fd] = read_buffer(buffer[fd], fd);
	if (!buffer[fd])
		return (NULL);
	if (!ft_strlen(buffer[fd]))
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	buffer[fd] = read_line(buffer[fd], &line);
	return (line);
}

// int main(void)
// {
// 	#include <stdio.h>
// 	#include <fcntl.h>
// 	# include <stdlib.h>
// 	# include <unistd.h>
// 	int fd = open("map01.ber", O_RDONLY);
// 	printf("main: %s", get_next_line(fd));
// 	printf("main: %s", get_next_line(fd));
// 	printf("main: %s", get_next_line(fd));
// 	printf("main: %s", get_next_line(fd));
// 	close(fd);
// }