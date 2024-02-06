/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessadik <aessadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:09:18 by aessadik          #+#    #+#             */
/*   Updated: 2024/02/02 06:22:24 by aessadik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
char	*get_next_line(int fd)
{
	static char *ret;
	char *total;
	int i;
	total = (char *)malloc(BUFFER_SIZE + 1);
	total[BUFFER_SIZE] = 0;
	i = 0;
	while (ft_strchr(ret,'\n') && total[i])
	{
		i = read(fd, ret, BUFFER_SIZE);
		total[i] = *ret;
		i++;
	}
	
	return (ret);
}
int	main(void)
{
	int fd = open("t.txt", O_RDONLY);
	char *s = get_next_line(fd);
	printf("<%s>", s);
}