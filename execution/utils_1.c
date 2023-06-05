/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selrhair <selrhair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:14:04 by selrhair          #+#    #+#             */
/*   Updated: 2023/05/23 16:29:32 by selrhair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_strncmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

t_list	*ft_lstnew(char *content)
{
	t_list	*ptr;

	ptr = malloc (sizeof (t_list));
	if (!ptr)
		return (0);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	else
	{
		ptr = *lst;
		while (ptr->next)
		{
			ptr = ptr->next;
		}
		ptr->next = new;
	}
}