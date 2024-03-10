/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessadik <aessadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:30:35 by aessadik          #+#    #+#             */
/*   Updated: 2024/03/10 02:25:35 by aessadik         ###   ########.fr       */
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

	if (!buffer || !*buffer)
		return (free(buffer), NULL);
	len2 = ft_strlen(line);
	tmp = ft_strdup(buffer + len2);
	free(buffer);
	return (tmp);
}

char	*ft_free(char *s)
{
	if (s)
		free(s = NULL);
	return (NULL);
}

char	*read_line(char *ret, int fd)
{
	int		i;
	char	*buffer;

	i = 1;
	buffer = (char *)malloc((size_t)(BUFFER_SIZE * sizeof(char) + 1));
	if (!buffer)
		return (NULL);
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
			return (ft_free(ret), free(buffer), NULL);
		buffer[i] = '\0';
		ret = ft_strjoin(ret, buffer);
		if (find_newline(buffer) != -1)
			break ;
	}
	return (free(buffer), ret);
}

char	*get_next_line(int fd)
{
	char		*ret_l;
	static char	*ret[1024];

	if (fd <= -1 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647 || fd > 1024)
		return (NULL);
	ret[fd] = read_line(ret[fd], fd);
	ret_l = get_new_line(ret[fd]);
	ret[fd] = set_buffer(ret[fd], ret_l);
	return (ret_l);
}
