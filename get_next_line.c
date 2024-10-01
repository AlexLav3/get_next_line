/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:39:18 by elavrich          #+#    #+#             */
/*   Updated: 2024/10/02 00:21:48 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_utils.c"

char	*get_next_line(int fd)
{
	char	*f_line;

	f_line = read_from_f(fd);
	return (f_line);
}
int	main(void)
{
	int		fd;
	char	*next_line;

	fd = open("example.txt", O_RDONLY);
	next_line = get_next_line(fd);
	printf("%s\n", next_line);
	next_line = NULL;
	close(fd);
	return (0);
}
