/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almirand <almirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:35:30 by almirand          #+#    #+#             */
/*   Updated: 2022/05/10 13:23:49 by almirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 * Finds the position of the given char in a string
 *
 * @param {s} String to search at
 * @param {c} Char to search for
 *
 * @return {i} Position of the found char
 */
int	ft_strchr(char *s, int c)
{
	int				index;
	unsigned char	ch;

	ch = (unsigned char)c;
	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] == ch)
			return (++index);
		index++;
	}
	return (-1);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
 * Copies a string
 *
 * @param {dst} String to copy at
 * @param {src} String to copy from
 * @param {dstsize} Size of destiny string
 *
 * @return {str} Copied string
 */
size_t	ft_strlcpy(char	*dst, char	*src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	i = ft_strlen(src);
	return (i);
}

/*
 * Concatenates two strings
 *
 * @param{s1} First string
 * @param{s2} Second string
 *
 * @return{join} Concatenated strings
 */
char	*ft_strjoin(char *s1, char *s2)
{
	char		*str;
	size_t		len_s1;
	size_t		len_s2;
	size_t		i;

	i = -1;
	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	i = 0;
	while (s2[i])
	{
		str[len_s1++] = s2[i++];
	}
	str[len_s1] = '\0';
	free(s1);
	return (str);
}

/*
 * Allocates and copies a string
 *
 * @param {s1} String to copy
 *
 * @return {str} New allocated string
 */
char	*ft_strdup(char *s1)
{
	char	*str;
	size_t	length;
	int		i;

	i = 0;
	length = ft_strlen(s1) + 1;
	str = malloc (sizeof(char) * length);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, length);
	return (str);
}
