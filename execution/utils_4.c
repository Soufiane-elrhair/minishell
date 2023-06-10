/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selrhair <selrhair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:57:17 by selrhair          #+#    #+#             */
/*   Updated: 2023/06/08 16:53:25 by selrhair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

t_list *ft_fill_list(char **line)
{
	int i;
	t_list *list;

	list = ft_lstnew(line[0]);
	i = 0;
	while (line[++i])
		ft_lstadd_back(&list, ft_lstnew(line[i]));
	return (list);
}

void	ft_echo(t_list *list)
{
	int	i;

	if (ft_lstsize(list) < 2)
	{
		printf("\n");
		return ;
	}
	else if (ft_lstsize(list) > 2 && ft_strncmp(list->next->content, "-n"))
	{
		list = list->next->next;
		while (list)
		{
			printf("%s", list->content);
			list = list->next;
		}
	}
	else if (ft_lstsize(list) > 2)
	{
			printf(">>> %s\n", list->next->content);
		list = list->next;
		while (list)
		{
			printf("%s", list->content);
			list = list->next;
		}
		printf("\n");
	}
	else if (ft_lstsize(list) == 2)
	{
		printf("%s\n", list->next->content);
	}
}

void	ft_env(char **env, t_list *export)
{
	int	i;
	t_list *tmp;

	tmp = export;
	i = -1;
	while (tmp)
	{
		if (ft_strchr(tmp->content, '='))
			printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
}
