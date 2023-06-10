/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selrhair <selrhair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 09:18:12 by selrhair          #+#    #+#             */
/*   Updated: 2023/06/08 09:20:12 by selrhair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

int	ft_strncmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

static void	ft_free(int n, char **ptr)
{
	while (n >= 0)
	{
		free (ptr [n]);
		n--;
	}
	free (ptr);
}

static int	ft_strcount(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		return (-1);
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			count++;
		i++;
		if (s[i] == '\0' && s[i - 1] != c)
			count++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		n;
	char	**ptr;

	i = 0;
	n = 0;
	ptr = (char **) malloc ((ft_strcount(s, c) + 1) * sizeof(char *));
	if (!ptr || !s)
		return (0);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		j = i;
		while (s[j] && s[j] != c)
			j++;
		if (i != j)
			ptr[n++] = ft_substr(s, i, (j - i));
		if (!ptr)
			ft_free(n, ptr);
		i = j;
	}
	ptr[n] = 0;
	return (ptr);
}
