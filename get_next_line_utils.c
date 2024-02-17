/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessadik <aessadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:09:14 by aessadik          #+#    #+#             */
/*   Updated: 2024/02/17 03:50:07 by aessadik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
	
}
char *ft_strjoin(char *s, char *s1)
{
    char *p;
	char *str;
    int  i = 0;
	
    if (!s && !s1)
		return (NULL);
    p = (char *)malloc(ft_strlen(s) + ft_strlen(s1) + 1);
	if (!p)
		return (NULL);
	str = p;
	if (s)
		while (s[i])
			*(p++) = s[i++];
	i = 0;
	if (s1)
    	while (s1[i])
    	    *(p++) = s1[i++];

    return(str);
}
char	*ft_strchr(char *s)
{
	int	index;
	int	len;
	char *line;

	if (!s)
		return (0);
	index = 0;
	len = ft_strlen(s);
	line = malloc(len + 1);
	if (!line)
		return (0);
	while (index < len && s[index] != '\n')
	{
		line[index] = s[index];
		index++;
	}
	if (s[index] == '\n')
	{
		line[index] = s[index];
		return (line);
	}
	return (0);
}
char	*ft_strrchr(char *s)
{
	int				i;
	unsigned char	*s1;

	i = ft_strlen(s);
	s1 = (unsigned char *)s;
	while (i >= 0)
	{
		if (s1[i] == '\n')
			return ((char *)(s1 + i));
		i--;
	}
	return (NULL);
}
// char	*get_first_line(char *next_line)
// {
// 	int		i;
// 	char	*new_line;

// 	i = 0;
// 	if (!*next_line)
// 		return (NULL);
// 	while (next_line[i] && next_line[i] != '\n')
// 		i++;
// 	if (next_line[i] == '\n')
// 		i++;
// 	new_line = (char *)malloc(i + 1);
// 	if (!new_line)
// 		return (NULL);
// 	i = 0;
// 	while (next_line[i] && next_line[i] != '\n')
// 	{
// 		new_line[i] = next_line[i];
// 		i++;
// 	}
// 	if (next_line[i] == '\n')
// 	{
// 		new_line[i] = next_line[i];
// 		i++;
// 	}
// 	return (new_line[i] = '\0', new_line);
// }

// char	*get_new_line(char *str)
// {
// 	int i;
// 	int i2;
// 	char *new_line;

// 	i = 0;
// 	while (str[i] && str[i] != '\n')
// 		i++;
// 	if (!str[i])
// 	{
// 		free(str);
// 		return (NULL);
		
// 	}
// 	new_line = (char *)malloc(ft_strlen(str) - i);
// 	if (!new_line)
// 		return (NULL);
// 	i++;
// 	i2 = 0;
// 	while (str[i])
// 		new_line[i2++] = str[i++];
// 	new_line[i2] = '\0';
// 	free(str);
// 	return (new_line);
// }

int	find_newline(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i++,i);
		i++;
	}
	return (-1);
}