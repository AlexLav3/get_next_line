/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:39:08 by elavrich          #+#    #+#             */
/*   Updated: 2024/10/15 21:55:51 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char		*get_next_line(int fd);
int			ft_strlen(char *str);
char		*cut_line(char *str);
char		*get_rest(char *str);
char		*ft_strjoin(char *s1, char *s2);
char		*read_from_f(int fd, char *read_line);
const char	*ft_strchr(const char *s, char c);
void		ft_free(char *str);

#endif
