/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:37:36 by azbreak           #+#    #+#             */
/*   Updated: 2023/12/29 17:21:33 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *str, char sep)
{
	int	i;
	int	word;
	int	count;

	count = 0;
	word = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != sep)
		{
			if (!word)
			{
				count++;
				word = 1;
			}
		}
		else
			word = 0;
		i++;
	}
	return (count);
}

static int	len_word(char const *str, char sep)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != sep)
		i++;
	return (i);
}

static char	*ft_copy(char const *str, int size)
{
	char	*tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(char) * size + 1);
	if (!tab)
		return (NULL);
	while (i < size)
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

static char	**free_tab(char **tab, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		count_w;
	char	**tab;
	int		j;
	int		len;

	j = 0;
	i = 0;
	count_w = count_word(s, c);
	tab = malloc(sizeof(char *) * (count_w + 1));
	if (!tab)
		return (NULL);
	while (i < count_w)
	{
		while (s[j] == c)
			j++;
		len = len_word(&s[j], c);
		tab[i] = ft_copy(&s[j], len);
		if (!tab[i])
			return (free_tab(tab, i));
		j += len;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

// #include <stdio.h>

// int main()
// {
//     char *str = "    Salut a tous ici elouan   ";
//     char sep = ' ';
//     char **tab;
//     int i = 0;

//     tab = ft_split(str, sep);
//     while (tab[i])
//     {
//         printf("%s \n", tab[i]);
//         i++;
//     }
// }