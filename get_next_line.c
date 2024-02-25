/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessadik <aessadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:30:35 by aessadik          #+#    #+#             */
/*   Updated: 2024/02/25 14:23:24 by aessadik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

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
	int		len;
	int		len2;
	char	*tmp;

	// len = ft_strlen(buffer);
	len2 = ft_strlen(line);
	tmp = ft_strdup(buffer + len2);
	free(buffer);
	// buffer = ft_strdup(tmp);
	// free(tmp);
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*return_line;
	static char	*ret;
	int			i;

	i = 1;
	return_line = 0;
	if (fd <= -1 || BUFFER_SIZE <= 0)
		return (0);
	while (i > 0)
	{
		buffer = (char *)malloc(BUFFER_SIZE * sizeof(char) + 1);
		if (!buffer)
			return (0);
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free (buffer);
			if (ret)
				free (ret);
			return (NULL);
			
		}
		buffer[i] = '\0';
		ret = ft_strjoin(ret, buffer);
		if (find_newline(buffer) != -1)
			break ;
		free(buffer);
	}
	return_line = get_new_line(ret);
	ret = set_buffer(ret, return_line);
	// printf("ret = %p\n", ret);
	// printf("return_line = %p\n", return_line);
	// printf("buffer = %p\n", buffer);
	return (return_line);
}

int ft_e(char *str)
{
	int fd;
	char *line;

	int i = 0;
	fd = open(str, O_RDONLY);
	while (i < 10)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
		free(line);
		i++;
	}
	// free(line);
	return (0);
}
int main(int ac, char **av)
{
	ft_e(av[1]);
	system("leaks a.out");
}
