/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:39:29 by elavrich          #+#    #+#             */
/*   Updated: 2024/10/17 19:15:31 by elavrich         ###   ########.fr       */
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

	total_length = ft_strlen(s1) + ft_strlen(s2);
	concat = malloc((total_length + 1));
	if (!concat)
		return (free(s1), NULL);
	i = -1;
	while (s1[++i])
		concat[i] = s1[i];
	j = -1;
	while (s2[++j])
		concat[i + j] = s2[j];
	concat[i + j] = '\0';
	free(s1);
	return (concat);
}

int	ft_strchr(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			return (1);
		}
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}
