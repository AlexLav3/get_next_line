/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:39:08 by elavrich          #+#    #+#             */
/*   Updated: 2024/10/06 16:26:56 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h> // for strchr delete later

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strlcpy(char *dst, char *src, size_t size);
int		ft_strlen(char *str);
char	*cut_line(char *str);
char	*get_rest(char *str);
char	*read_from_f(int fd, char *read_line);
char	*ft_strjoin(char *s1, char *s2);

#endif
