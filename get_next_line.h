/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessadik <aessadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:09:20 by aessadik          #+#    #+#             */
/*   Updated: 2024/02/02 06:04:48 by aessadik         ###   ########.fr       */
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
char	*ft_substr(char const *s, unsigned int start, size_t len);
char    *get_next_line(int fd);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char    *ft_strchr(char *s,int c);
char	*ft_strjoin(char *s1, char *s2);
char	*get_first_line(char *next_line);

#endif