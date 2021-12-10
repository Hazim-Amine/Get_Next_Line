/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahazim <ahazim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:53:42 by ahazim            #+#    #+#             */
/*   Updated: 2021/12/09 12:35:54 by ahazim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_move(char *s1, char *s2, char *s)
{
	int	index;
	int	count;

	index = ft_strlen(s1);
	count = 0;
	if (s1)
	{
		while (s1[count])
		{
			s[count] = s1[count];
			count++;
		}
	}
	count = 0;
	while (s2[count])
	{
		s[index] = s2[count];
		index++;
		count++;
	}
	s[index] = '\0';
	return (s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	int		index;
	char	*cat;

	index = 0;
	if (!s1)
	{
		s1 = (char *)malloc(1);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	len = ft_strlen(s1);
	cat = malloc(len + ft_strlen(s2) + 1);
	if (!cat)
		return (NULL);
	cat = ft_move(s1, s2, cat);
	free(s1);
	return (cat);
}

size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	int	count;

	count = 0;
	if (!s)
		return (NULL);
	while (s[count] != (char)c)
	{
		if (s[count] == '\0')
			return (NULL);
		count++;
	}
	return ((char *)s);
}
