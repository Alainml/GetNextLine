/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almirand <almirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:46:42 by almirand          #+#    #+#             */
/*   Updated: 2022/04/28 17:39:47 by almirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <limits.h>

static char	*ft_update_static(char	*read_status, int line_size)
{
	char	*new_status;
	int		i;

	i = 0;
	if (!read_status[line_size])
	{
		free(read_status);
		return (NULL);
	}
	new_status = (char *)malloc((ft_strlen(read_status) - line_size + 1));
	if (!new_status)
		return (NULL);
	while (read_status[line_size])
		new_status[i++] = read_status[line_size++];
	new_status[i] = '\0';
	free (read_status);
	return (new_status);
}

static char	*ft_return_line(char	*read_buffer_fd)
{
	char	*line;
	int		index;
	int		line_jump;

	index = 0;
	line_jump = ft_strchr(read_buffer_fd, '\n');
	if (line_jump == -1)
		line_jump = ft_strlen(read_buffer_fd);
	line = (char *) malloc (sizeof(char) * line_jump + 1);
	if (!line)
		return (NULL);
	while (index < line_jump)
	{
		line[index] = read_buffer_fd[index];
		index++;
	}
	line[index] = '\0';
	return (line);
}

static char	*ft_read_buffer(char	*read_buffer, int fd)
{
	int		n_bytes;
	char	buffer[BUFFER_SIZE + 1];

	while (ft_strchr(read_buffer, '\n') == -1)
	{
		n_bytes = read(fd, buffer, BUFFER_SIZE);
		if (n_bytes == 0)
			break ;
		else if (n_bytes == -1)
			return (NULL);
		buffer[n_bytes] = '\0';
		read_buffer = ft_strjoin(read_buffer, buffer);
	}
	return (read_buffer);
}

char	*get_next_line(int fd)
{
	static char	*read_buffer[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!read_buffer[fd])
		read_buffer[fd] = ft_strdup("");
	read_buffer[fd] = ft_read_buffer(read_buffer[fd], fd);
	if (!read_buffer[fd] || !read_buffer[fd][0])
	{
		free(read_buffer[fd]);
		read_buffer[fd] = NULL;
		return (NULL);
	}
	line = ft_return_line(read_buffer[fd]);
	read_buffer[fd] = ft_update_static(read_buffer[fd], ft_strlen(line));
	return (line);
}

/* int main(void)
{
	char *name = "file1.txt";
	int fd = open(name, O_RDONLY);
	char	*line;
	int		i;

	i = 1;
	while (i++ <= 2)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	close(fd);
	i = 1;
	fd = open(name, O_RDONLY);
	while (i++ <= 6)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	close(fd);
} */
