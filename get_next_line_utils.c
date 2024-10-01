/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:39:29 by elavrich          #+#    #+#             */
/*   Updated: 2024/10/02 00:27:12 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*b;

	b = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		b[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}
int	is_newl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
static char	*read_from_f(int fd)
{
	char	*fin_line;
	int		bytes_read;
	int		i;

	fin_line = ft_calloc(3 + 1, sizeof(char));
	i = ft_strlen(fin_line);
	if (!fin_line)
		return (NULL);
	bytes_read = read(fd, fin_line, i);
	if (bytes_read <= 0)
		return (NULL);
	return (fin_line);
}
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && !is_newl(str))
	{
		i++;
	}
	return (i);
}
