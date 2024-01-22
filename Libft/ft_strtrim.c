/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:01:40 by azbreak           #+#    #+#             */
/*   Updated: 2023/11/08 15:20:33 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	is_sep(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	len_str(char const *str, char const *set)
{
	int	count_start;
	int	len;
	int	count_end;

	len = 0;
	count_start = 0;
	while (str[len])
		len++;
	count_end = len;
	while (is_sep(str[count_start], set))
		count_start++;
	while (is_sep(str[count_end - 1], set))
		count_end--;
	count_end = len - count_end;
	len = len - count_start - count_end;
	if (len < 0)
		len = 0;
	return (len);
}

static char	*print_tab(size_t end, size_t start, char const *s1, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (ft_calloc(1, 1));
	while (start < end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	len;
	size_t	end;
	size_t	start;

	start = 0;
	end = 0;
	len = len_str(s1, set);
	while (is_sep(s1[start], set))
		start++;
	while (s1[end])
		end++;
	while (is_sep(s1[end - 1], set))
		end--;
	str = print_tab(end, start, s1, len);
	return (str);
}
// int main()
// {
// 	char *s;
// 	s = ft_strtrim("oxsalutoxxoxo", "ox");
// 	printf("%s| \n", s);
// 	free(s);

// }