/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selrhair <selrhair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:39:34 by selrhair          #+#    #+#             */
/*   Updated: 2023/05/21 17:40:26 by selrhair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*ptr;

	i = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	ptr = (char *) malloc(len + 1);
	if (ptr == 0)
		return (0);
	while (i < len)
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
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
