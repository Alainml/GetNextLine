/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almirand <almirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:36:18 by almirand          #+#    #+#             */
/*   Updated: 2022/04/28 14:53:07 by almirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
int		ft_strchr(char *s, int c);
char	*ft_strjoin(char*s1, char *s2);
char	*ft_strdup(char *s1);
size_t	ft_strlcpy(char	*dst, char	*src, size_t dstsize);
size_t	ft_strlen(char *str);

#endif
