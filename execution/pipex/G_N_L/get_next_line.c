/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selrhair <selrhair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 07:50:53 by selrhair          #+#    #+#             */
/*   Updated: 2023/01/20 11:35:23 by selrhair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*find_nl(char *store, int fd)
{
	char	*buff;
	int		i;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (free (store), NULL);
	buff[0] = '\0';
	while (!ft_strchr1(buff, '\n'))
	{
		i = read (fd, buff, BUFFER_SIZE);
		if (i == 0)
			break ;
		if (i == -1)
			return (free (buff), free (store), NULL);
		buff[i] = '\0';
		store = ft_strjoin1(store, buff);
	}
	free (buff);
	return (store);
}

char	*put_line(char *store)
{
	char	*s;
	int		i;
	int		tmp;

	i = 0;
	if (store[0] == '\0')
		return (free(store), NULL);
	while (store[i] && store[i] != '\n' )
		i++;
	if (store[i] == '\n')
		i++;
	s = malloc (i + 1);
	if (!s)
		return (NULL);
	tmp = i;
	i = 0;
	while (i < tmp)
	{
		s[i] = store[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_skip(char *store)
{
	char	*tmp;
	char	*tmp2;

	tmp2 = store;
	tmp = ft_strchr1(store, '\n');
	if (!tmp)
	{
		free (store);
		return (0);
	}
	if (!tmp[1])
		return (free (tmp2), NULL);
	store = ft_strdup1(tmp + 1);
	free (tmp2);
	return (store);
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*line;

	store = find_nl(store, fd);
	if (store == NULL)
		return (NULL);
	line = put_line(store);
	store = ft_skip(store);
	return (line);
}
