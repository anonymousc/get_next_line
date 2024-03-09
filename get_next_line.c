/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessadik <aessadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:30:35 by aessadik          #+#    #+#             */
/*   Updated: 2024/03/10 00:45:38 by aessadik         ###   ########.fr       */
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
	int		len2;
	char	*tmp;
	
	if(!buffer)
		return (NULL);
	len2 = ft_strlen(line);
	tmp = ft_strdup(buffer + len2);
	free(buffer);
	return (tmp);
}

char	*ft_freea(char *s)
{
	if (!s)
	{
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
		buffer = (char *)malloc((size_t)(BUFFER_SIZE * sizeof(char) + 1));
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
 int main(int ac , char **av)
 {
 	int fd;
 	char *line;
 	 fd = open(av[1], O_RDONLY);
// 	 if (av[0])
// 	 {
// 	  printf("%s\n",get_next_line(0));
// 	 }
 	 while ((line = get_next_line(fd)))
 	 {
 	 	printf("%s", line);
 	 	free(line);
 	 }
	 system("leaks a.out");
 	 close(fd);
 	 return (0);
 }
