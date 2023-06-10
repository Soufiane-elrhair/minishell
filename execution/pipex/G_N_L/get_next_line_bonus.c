/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selrhair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:24:21 by selrhair          #+#    #+#             */
/*   Updated: 2022/11/18 11:25:23 by selrhair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

char	*find_nl(char *store, int fd)
{
	char	*buff;
	int		i;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (free (store), NULL);
	buff[0] = '\0';
	while (!ft_strchr(buff, '\n'))
	{
		i = read (fd, buff, BUFFER_SIZE);
		if (i == 0)
			break ;
		if (i == -1)
			return (free (buff), free (store), NULL);
		buff[i] = '\0';
		store = ft_strjoin(store, buff);
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
	tmp = ft_strchr(store, '\n');
	if (!tmp)
	{
		free (store);
		return (0);
	}
	if (!tmp[1])
		return (free (tmp2), NULL);
	store = ft_strdup(tmp + 1);
	free (tmp2);
	return (store);
}

char	*get_next_line(int fd)
{
	static char	*store[OPEN_MAX];
	char		*line;

	store[fd] = find_nl(store[fd], fd);
	if (store[fd] == NULL)
		return (NULL);
	line = put_line(store[fd]);
	store[fd] = ft_skip(store[fd]);
	return (line);
}
