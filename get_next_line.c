/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessadik <aessadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:30:35 by aessadik          #+#    #+#             */
/*   Updated: 2024/02/17 19:59:40 by aessadik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "get_next_line.h"
#include <fcntl.h>
char	*get_next_line(int fd)
{
	char	*buffer = 0;
	char	*return_line = 0;
	static char	*ret = 0;
	char 	*line_total = 0;
	int		i;
	i = 1;
	
	while (i > 0)
	{
		buffer = (char *)malloc(BUFFER_SIZE  * sizeof(char) + 1);
		if (!buffer)
			return (0);
		i = read(fd, buffer, BUFFER_SIZE);
		line_total = ft_strjoin(line_total, buffer);
		if (find_newline(buffer) != -1)
			break;
		free(buffer);
	}
	return_line = ft_strchr(line_total);
	ret = ft_strrchr(line_total);
	return (line_total);
}

// int	find_newline(char *str)
// {
// 	int i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '\n')
// 			return (i);
// 		i++;
// 	}
// 	return (-1);
// }
int	main(void)
{
	int fd = open("t.txt", O_RDONLY);
	//get_next_line(fd);
	// printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	// char *s = get_next_line(fd);

	int i = 0 ;
	while(i < 6)
	{
		 char  *s = get_next_line(fd);
		printf("%s", s);
		i++;
	}
	// printf("%s", s);
	return (0);		
}

// 0123456789
// 012345

// ret = 01234
// ret 
