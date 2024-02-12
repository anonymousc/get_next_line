/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessadik <aessadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:09:18 by aessadik          #+#    #+#             */
/*   Updated: 2024/02/12 21:25:13 by aessadik         ###   ########.fr       */
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
	char 	**tmp;
	char 	*stash;
	int		i;
	i = 0;
	ret = (char *)malloc(BUFFER_SIZE + 1);
	//ret[BUFFER_SIZE] = '\0';
	stash = (char *)malloc(1);
	stash[0] = '\0';
	//printf("%s",ret);
	//while (*ret)
	//{
		ret[0] = '\0';
		read(fd, ret,BUFFER_SIZE);
	// 	stash = ft_strjoin(stash , ret);
	// 	printf("%s",ret);
	// 	ret++;
	// }
	// printf("test\n");
	// while (ft_strchr(tmp[i], '\n'))
	// {
	// 	get(tmp[i]);		
	// 	//printf("test\n");
	// 	//tmp = get(ret);
	// 	read(fd, ret, BUFFER_SIZE);
	// 	//ft_strjoin(tmp,ret);	
	// 	i++;
	// }
	return (ret);
}

int	main(void)
{
	int fd = open("t.txt", O_RDONLY);
	char *s = get_next_line(fd);
	printf("<%s>\n", s);
}