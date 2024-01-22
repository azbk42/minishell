/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:14:54 by azbk              #+#    #+#             */
/*   Updated: 2024/01/18 18:41:13 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_stash(int fd, char *stash)
{
	int		bytes_read;
	char	*str;

	bytes_read = 1;
	str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	while (!ft_strchr_g(stash, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, str, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(str);
			return (NULL);
		}
		str[bytes_read] = '\0';
		stash = ft_strjoin_gnl(stash, str);
	}
	free(str);
	return (stash);
}

static char	*ft_get_line(char *stash)
{
	int		i;
	char	*str;

	i = 0;
	if (!stash || stash[0] == '\0')
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		str[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		str[i] = stash[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_read_next_stash(char *stash)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_len_g(stash) - i + 1));
	if (!str)
		return (NULL);
	i++;
	while (stash[i])
		str[j++] = stash[i++];
	str[j] = '\0';
	free(stash);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

	if (!BUFFER_SIZE || BUFFER_SIZE < 0 || fd < 0)
		return (NULL);
	stash[fd] = ft_read_stash(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = ft_get_line(stash[fd]);
	stash[fd] = ft_read_next_stash(stash[fd]);
	return (line);
}
