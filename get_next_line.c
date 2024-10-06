/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:39:18 by elavrich          #+#    #+#             */
/*   Updated: 2024/10/06 16:27:10 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_utils.c"

char	*get_next_line(int fd)
{
	static char	*st_line;
	char		*f_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	st_line = read_from_f(fd, st_line);
	if (!st_line)
		return (NULL);
	f_line = cut_line(st_line);
	st_line = get_rest(st_line);
	if (*st_line != '\0')
		f_line = ft_strjoin(f_line, st_line);
	return (f_line);
}

int	main(void)
{
	int		fd;
	char	*next_line;

	fd = open("example.txt", O_RDONLY);
	next_line = get_next_line(fd);
	printf("%s", next_line);
	// next_line = get_next_line(fd);
	// printf("%s", next_line);
	// next_line = get_next_line(fd);
	// printf("%s", next_line);
	// next_line = get_next_line(fd);
	//  printf("%s", next_line);
	// next_line = get_next_line(fd);
	// printf("%s", next_line);
	// next_line = get_next_line(fd);
	// printf("%s", next_line);
	// next_line = get_next_line(fd);
	// printf("%s", next_line);
	// next_line = get_next_line(fd);
	// printf("%s", next_line);
	// next_line = get_next_line(fd);
	// printf("%s", next_line);
	// next_line = get_next_line(fd);
	// printf("%s", next_line);
	// next_line = get_next_line(fd);
	// printf("%s", next_line);
	next_line = NULL;
	close(fd);
	return (0);
}
