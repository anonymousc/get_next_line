/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessadik <aessadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:09:14 by aessadik          #+#    #+#             */
/*   Updated: 2024/02/08 17:06:08 by aessadik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmpdst;
	unsigned char	*tmpsrc;
	unsigned int	index;

	index = 0;
	if (dst == src)
		return (dst);
	if (src == 0 && dst == 0)
		return (0);
	tmpdst = (unsigned char *)dst;
	tmpsrc = (unsigned char *)src;
	while (index < n)
	{
		tmpdst[index] = tmpsrc[index];
		index++;
	}
	return (dst);
}
size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s || *s != '\0')
		return (0);
	while (s[i])
		i++;
	return (i);
}
char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	size_t	l1;
	size_t	l2;

	//if (!(s1 || s2))
		//return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	p = (char *)malloc(l1 + l2 + 1);
	if (!p)
		return (NULL);
	ft_memcpy(p, s1, l1);
	ft_memcpy((p + l1), s2, l2);
	p[l1 + l2] = '\0';
	return (p);
}
char	*ft_strchr(char *s, int c)
{
	int	index;
	int	len;

	if (!s)
		return (NULL);
	index = 0;
	len = ft_strlen(s);
	while (index <= len)
	{
		if (s[index] == (unsigned char)c)
			return ((char *)(&s[index]));
		index++;
	}
	return (0);
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