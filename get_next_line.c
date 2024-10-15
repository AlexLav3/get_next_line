/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:39:18 by elavrich          #+#    #+#             */
/*   Updated: 2024/10/15 20:01:34 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_from_f(int fd, char *read_line)
{
	char	*storage_l;
	int		bytes_read;

	storage_l = malloc(BUFFER_SIZE + 1);
	if (!storage_l)
		return (NULL);
	if (!read_line)
	{
		read_line = malloc(1);
		read_line[0] = '\0';
	}
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, storage_l, BUFFER_SIZE);
		if (bytes_read < 0)
			return ((free(storage_l), free(read_line)), (NULL));
		if (bytes_read == 0)
			break ;
		storage_l[bytes_read] = '\0';
		read_line = ft_strjoin(read_line, storage_l);
		if (!read_line)
			return ((free(read_line)), (NULL));
	}
	return (free(storage_l), (read_line));
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
	fin_line = malloc(i + 2);
	if (!fin_line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		fin_line[i] = str[i];
		i++;
	}
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
	while (str[j] && str[j] != '\n')
		j++;
	if (!str[j])
		return ((free(str)), (NULL));
	j++;
	remainder = malloc(ft_strlen(str) - j + 1);
	if (!remainder)
		return (NULL);
	while (str[j])
		remainder[i++] = str[j++];
	remainder[i] = '\0';
	free(str);
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*st_line;
	char		*f_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	st_line = read_from_f(fd, st_line);
	if (!st_line)
		return (NULL);
	f_line = cut_line(st_line);
	if (!f_line)
		return (NULL);
	st_line = get_rest(st_line);
	return (f_line);
}
// int	main(void)
// {
// 	int		fd;
// 	char	*next_line;

// 	fd = open("example.txt", O_RDONLY);
// 	next_line = get_next_line(fd);
// 	printf("%s", next_line);
// 	free(next_line);
// 	// next_line = get_next_line(fd);
// 	// printf("%s", next_line);
// 	// next_line = get_next_line(fd);
// 	// printf("%s", next_line);
// 	// next_line = get_next_line(fd);
// 	// printf("%s", next_line);
// 	// next_line = get_next_line(fd);
// 	// printf("%s", next_line);
// 	// next_line = get_next_line(fd);
// 	// printf("%s", next_line);
// 	// next_line = get_next_line(fd);
// 	// printf("%s", next_line);
// 	// next_line = get_next_line(fd);
// 	// printf("%s", next_line);
// 	// next_line = get_next_line(fd);
// 	// printf("%s", next_line);
// 	// next_line = get_next_line(fd);
// 	// printf("%s", next_line);
// 	// next_line = get_next_line(fd);
// 	// printf("%s", next_line);
// 	close(fd);
// 	return (0);
// }
