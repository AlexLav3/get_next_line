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

	// initialize read_line to NULL if it hasn't been set yet
	// to ensure it can handle when read_line is initially NULL
	if(!s1)
	{
		s1 = malloc(1);
		if(!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	total_length = ft_strlen(s1) + ft_strlen(s2);
	concat = malloc(total_length + 1); // i think it wasnt needed but not sure, just deleted the cast :D
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
	free(s1); // probably can be done somewhere else for lenght, but i just did it here
				// basically once we join I free the old one
	return (concat);
}

char	*read_from_f(int fd, char *read_line)
{
	// no need for static it's reallocated on each function call
	char		*storage_l;
	int			bytes_read;

	storage_l = malloc(BUFFER_SIZE + 1);
	// if there is error you should free here
	if(!storage_l)
		return (NULL);
	// if (!read_line)
	// 	read_line = malloc(BUFFER_SIZE + 1); // dont know why do this :D
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, storage_l, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(storage_l);
			return (NULL);
		}
		// stop reading when we get to the EOF
		if (bytes_read == 0)
			break;
		storage_l[bytes_read] = '\0';
		read_line = ft_strjoin(read_line, storage_l);
		if (strchr(storage_l, '\n')) // need to stop when found \n and use your own strchr :D
			break;
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
	// fin_line = malloc(i + 2); // i feel like we can just use i here and + 1 is for '\n' and + 1 for '\0'
	fin_line = malloc(i + (str[i] == '\n' ? 2 : 1)); // just trying this chatgpt bullshit
	// obligatory check
	if(!fin_line)
		return (NULL);
	i = 0; // need to reset index to copy
	while (str[i] && str[i] != '\n')
	{
		fin_line[i] = str[i];
		i++;
	}
	// i feel like str[i] && str[i] one of them is enough :D
	if (str[i] == '\n')
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
	while (str[i] && str[i] != '\n') // changed logic a bit
		i++;
	// just freeing if no \n
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	remainder = malloc(ft_strlen(str) - i);
	// obligatory check
	if(!remainder)
		return (NULL);
	i++; // skip the newline here 
	while (str[i])
	{
		// this saves you 2 lines :P
		remainder[j++] = str[i++];
	}
	remainder[j] = '\0';
	free(str); // freeing old buffer
	return (remainder);
}
