/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahazim <ahazim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:39:50 by ahazim            #+#    #+#             */
/*   Updated: 2021/12/10 14:52:51 by ahazim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(char *str, int fd)
{
	int		index;
	char	*s;

	s = malloc(BUFFER_SIZE + 1);
	if (!s)
		return (NULL);
	index = 1;
	while (index && !ft_strchr(str, '\n'))
	{
		index = read (fd, s, BUFFER_SIZE);
		if (index == -1)
		{
			free(s);
			return (NULL);
		}
		s[index] = '\0';
		str = ft_strjoin(str, s);
	}
	free(s);
	return (str);
}

char	*ft_the_line(char	*str)
{
	int		index;
	char	*line;

	index = 0;
	if (!str[index])
		return (NULL);
	while (str[index] != '\n' && str[index] != '\0')
		index++;
	if (ft_strchr(str, '\n'))
		line = (char *)malloc(sizeof(char) * (index + 1));
	else
		line = (char *)malloc(sizeof(char) * (index + 2));
	index = 0;
	while (str[index] != '\n' && str[index] != '\0')
	{
		line[index] = str[index];
		index++;
	}
	if (str[index] == '\n')
		line[index++] = '\n';
	line[index] = '\0';
	return (line);
}

char	*ft_next_line(char *str)
{
	int		index;
	int		count;
	int		lenstr;
	char	*newstr;

	index = 0;
	while (str[index] != '\0' && str[index] != '\n')
		index++;
	if (!str[index])
	{
		free(str);
		return (NULL);
	}
	index++;
	count = 0;
	lenstr = ft_strlen(&str[index]);
	newstr = malloc(lenstr + 1);
	if (!newstr)
		return (NULL);
	while (str[index])
		newstr[count++] = str[index++];
	newstr[count] = '\0';
	free(str);
	return (newstr);
}

char	*get_next_line(int fd)
{
	static char	*str[1024];
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = ft_read_line(str[fd], fd);
	if (!str[fd])
		return (NULL);
	line = ft_the_line(str[fd]);
	str[fd] = ft_next_line(str[fd]);
	return (line);
}
