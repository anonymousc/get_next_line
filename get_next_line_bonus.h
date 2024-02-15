/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessadik <aessadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:09:05 by aessadik          #+#    #+#             */
/*   Updated: 2024/02/15 01:49:10 by aessadik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS
# define GET_NEXT_LINE_BONUS

# include <unistd.h>
char	*get_next_line(int fd);
char     *ft_strchr(const char *s, int c);
char    *ft_strjoin(char *s1, char *s2);
size_t  ft_strlen(const char *s);
void    *ft_memcpy(void *dst, const void *src, size_t n);
char   *read_file(int fd);
#endif