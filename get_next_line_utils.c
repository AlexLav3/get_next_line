/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:39:29 by elavrich          #+#    #+#             */
/*   Updated: 2024/10/06 17:09:01 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		total_length;
	char	*concat;

	if (!s1 || !s2)
		return (NULL);
	total_length = ft_strlen(s1) + ft_strlen(s2);
	concat = (char *)malloc((total_length + 1) * sizeof(char));
	if (!concat)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		concat[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		concat[i + j] = s2[j];
		j++;
	}
	concat[i + j] = '\0';
	return (concat);
}

char	*read_from_f(int fd, char *read_line)
{
	static char	*storage_l;
	int			bytes_read;

	storage_l = malloc(BUFFER_SIZE + 1);
	if (!read_line)
		read_line = malloc(BUFFER_SIZE + 1);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, storage_l, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(storage_l);
			return (NULL);
		}
		storage_l[bytes_read] = '\0';
		read_line = ft_strjoin(read_line, storage_l);
	}
	free(storage_l);
	return (read_line);
}

char	*cut_line(char *str)
{
	int		i;
	char	*fin_line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	fin_line = malloc(BUFFER_SIZE + 1);
	while (str[i] && str[i] != '\n')
	{
		fin_line[i] = str[i];
		i++;
	}
	if (str[i] && str[i] == '\n')
		fin_line[i++] = '\n';
	fin_line[i] = '\0';
	return (fin_line);
}

char	*get_rest(char *str)
{
	int		i;
	int		j;
	char	*remainder;

	j = 0;
	i = 0;
	while (str[j] && str[j] == '\n')
		j++;
	remainder = malloc(ft_strlen(str + j)) + 1;
	while (str[j])
	{
		remainder[i] = str[j];
		i++;
		j++;
	}
	remainder[i] = '\0';
	free(str);
	return (remainder);
}
