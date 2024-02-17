/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessadik <aessadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:09:20 by aessadik          #+#    #+#             */
/*   Updated: 2024/02/16 01:31:47 by aessadik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 3

#endif

size_t	ft_strlen(char *s);
char	*ft_strdup(const char *s1);
char    *ft_strchr(char *s);
char	*ft_strjoin(char *s, char *s1);
char	*read_file(int fd);
int	find_newline(char *str);
char *get_next_line(int fd);
char *ft_strrchr(char *s);
#endif