/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessadik <aessadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:30:35 by aessadik          #+#    #+#             */
/*   Updated: 2024/02/15 02:08:52 by aessadik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "get_next_line.h"
#include <fcntl.h>

char *get(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (s);
}
char	*get_next_line(int fd)
{
	static char	*ret;
	char 	*tmp;
	//char 	*stash;
	int		i;
	i = 0;
	ret = (char *)malloc(BUFFER_SIZE + 1);
	if (ret == NULL)
	 	return (NULL);
	i = read(fd, ret, BUFFER_SIZE);
	tmp = ret;
	while (*ret != '\n')
	{
		ret = calloc(BUFFER_SIZE + 1, sizeof(char));
		tmp = ft_strjoin(tmp, ret);
		ret++;
	}
	return (tmp);
}


int	main(void)
{
	int fd = open("t.txt", O_RDONLY);
	char *s = get_next_line(fd);
	printf("%s", s);
	return (0);		
}