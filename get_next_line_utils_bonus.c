/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessadik <aessadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:09:14 by aessadik          #+#    #+#             */
/*   Updated: 2024/03/10 02:20:14 by aessadik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s, char *s1)
{
	char	*p;
	char	*str;
	int		i;

	i = 0;
	if (!s && !s1)
		return (NULL);
	p = (char *)malloc(ft_strlen(s) + ft_strlen(s1) + 1);
	if (!p)
		return (free(s), NULL);
	p[ft_strlen(s) + ft_strlen(s1)] = '\0';
	str = p;
	if (s)
		while (s[i])
			*(p++) = s[i++];
	i = 0;
	if (s1)
		while (s1[i])
			*(p++) = s1[i++];
	free(s);
	return (str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	i = 0;
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
	{
		free(p);
		return (NULL);
	}
	while (i < len && s[start + i])
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*get_new_line(char *s)
{
	int	len;

	len = 0;
	if (!s || !*s)
		return (NULL);
	while (s[len] && s[len] != '\n')
		len++;
	len += (s[len] == '\n');
	return (ft_substr(s, 0, len));
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		i;

	i = 0;
	p = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1) + 1));
	if (!p)
	{
		free(p);
		return (NULL);
	}
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
