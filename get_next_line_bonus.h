/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessadik <aessadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:09:20 by aessadik          #+#    #+#             */
/*   Updated: 2024/02/27 16:44:49 by aessadik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3

# endif

size_t	ft_strlen(char *s);
char	*ft_strdup(const char *s1);
char	*get_new_line(char *s);
char	*ft_strjoin(char *s, char *s1);
char	*read_file(int fd);
int		find_newline(char *str);
char	*get_next_line(int fd);
char	*ft_strrchr(char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*set_buffer(char *buffer, char *line);
#endif