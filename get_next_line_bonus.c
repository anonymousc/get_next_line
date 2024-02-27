/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessadik <aessadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:30:35 by aessadik          #+#    #+#             */
/*   Updated: 2024/02/27 16:44:38 by aessadik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	find_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*set_buffer(char *buffer, char *line)
{
	int		len2;
	char	*tmp;

	len2 = ft_strlen(line);
	tmp = ft_strdup(buffer + len2);
	free(buffer);
	return (tmp);
}

char	*ft_freea(char *s)
{
	if (!s)
	{
		printf("Error\n");
		s = NULL;
		free(s);
	}
	return (NULL);
}

char	*ft_free(char *s)
{
	if (s)
	{
		s = NULL;
		free(s);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*ret_l;
	static char	*ret;
	int			i;

	i = 1;
	if (fd <= -1 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
		return (free(ret), NULL);
	while (i > 0)
	{
		buffer = (char *)malloc(BUFFER_SIZE * sizeof(char) + 1);
		ft_freea(buffer);
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
			return (ft_free(ret), free(buffer), NULL);
		buffer[i] = '\0';
		ret = ft_strjoin(ret, buffer);
		if (find_newline(buffer) != -1)
		{
			free(buffer);
			break ;
		}
		free(buffer);
	}
	return (ret_l = get_new_line(ret), ret = set_buffer(ret, ret_l), ret_l);
}
