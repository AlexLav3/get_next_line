/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:39:08 by elavrich          #+#    #+#             */
/*   Updated: 2024/10/02 23:26:53 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char		*get_next_line(int fd);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strlcpy(char *dst, char *src, size_t size);
int			ft_strlen(char *str);
char		*cut_line(char *str);
char		*get_rest(char *str);

#endif
