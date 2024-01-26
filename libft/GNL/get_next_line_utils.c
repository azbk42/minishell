/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:15:05 by azbk              #+#    #+#             */
/*   Updated: 2023/12/29 15:47:27 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr_g(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return (s);
	return (NULL);
}

size_t	ft_len_g(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *buffer, char *str)
{
	char	*new_str;
	int		i;
	int		j;

	if (!buffer)
	{
		buffer = (char *)malloc(sizeof(char) * 1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	if (!str)
		return (NULL);
	new_str = malloc(sizeof(char) * (ft_len_g(buffer) + ft_len_g(str) + 1));
	if (!new_str)
		return (NULL);
	i = -1;
	while (buffer[++i])
		new_str[i] = buffer[i];
	j = 0;
	while (str[j])
		new_str[i++] = str[j++];
	new_str[i] = '\0';
	free(buffer);
	return (new_str);
}
