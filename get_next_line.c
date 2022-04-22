/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almirand <almirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:46:42 by almirand          #+#    #+#             */
/*   Updated: 2022/04/22 15:04:07 by almirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <limits.h>
#define BUFFER_SIZE 1

static char	*ft_return_line(char	*read_buffer_fd)
{
	char	*line;
	char	*new_read_status;
	int		index;
	int		line_jump;

	index = 0;
	line_jump = ft_strchr(read_buffer_fd, '\n');
	line = (char *) malloc (sizeof(char) * line_jump + 1);
	while (index < line_jump)
	{
		line[index] = read_buffer_fd[index];
		index++;
	}
	line[index] = '\0';
	new_read_status = ft_strdup(&read_buffer_fd[index] + 1);
	free(read_buffer_fd);
	read_buffer_fd = ft_strdup(new_read_status);
	return (line);
}

static char	*ft_read_buffer(char	**read_buffer, int fd, char	*buffer)
{
	int		n_bytes;
	char	*aux;

	while (ft_strchr(read_buffer[fd], '\n') == -1)
	{
		n_bytes = read(fd, buffer, BUFFER_SIZE);
		if (n_bytes == 0)
			return (read_buffer[fd]);
		buffer[BUFFER_SIZE] = '\0';
		aux = ft_strjoin(read_buffer[fd], buffer);
		free (read_buffer[fd]);
		read_buffer[fd] = ft_strdup(aux);
	}
	return (ft_return_line(read_buffer[fd]));
}

char	*get_next_line(int fd)
{
	static char	*read_buffer[OPEN_MAX];
	char		buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (read(fd, buffer, BUFFER_SIZE) < 1)
		return (NULL);
	if (!read_buffer[fd])
		read_buffer[fd] = ft_strdup("");
	return (ft_read_buffer(read_buffer, fd, buffer));
}

/* int	main(void)
{
	int		fd = open("file1", O_RDONLY);
	char	*line;

	line = get_next_line(1000);
	printf("line = %s\n", line);
	free(line);
	close(fd);
	return (0);
}
 */
