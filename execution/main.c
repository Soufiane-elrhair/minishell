/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selrhair <selrhair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:19:06 by selrhair          #+#    #+#             */
/*   Updated: 2023/06/05 13:11:51 by selrhair         ###   ########.fr       */
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

void	ft_export(char **env, t_list *list, t_list *export)
{

	// printf("%d\n", i++);

	if (ft_lstsize(list) > 1)
	{
		list = list->next;
		while (list)
		{
			ft_lstadd_back(&export, ft_lstnew(list->content));
			list = list->next;
		}
		return ;
	}
	while (export)
	{
		printf("declare -x %s\n", export->content);
		export = export->next;
	}
}

void	ft_builtins(t_list *list, char **env, t_list *export)
{
	char cwd[256];

	if (ft_strncmp(list->content, "x"))
		exit (0);
	else if (ft_strncmp(list->content, "pwd")) 
		printf("%s\n", getcwd(cwd, sizeof(cwd)));
	else if (ft_strncmp(list->content, "cd "))
		chdir(list->next->content);
	else if (ft_strncmp(list->content, "echo"))
		ft_echo(list);
	else if(ft_strncmp(list->content, "env"))
		ft_env(env, export);
	else if(ft_strncmp(list->content, "export"))
		ft_export(env, list, export);
}

int main(int ac, char **av, char **env)
{
	char	*input;
	char	**line;
	t_list	*list;
	t_list	*export;
	int		i;

	i = 0;
	export = ft_lstnew(env[0]);
	while (env[++i])
		ft_lstadd_back(&export, ft_lstnew(env[i]));
	if (ac == 1)
	{
		while (1)
		{
			input = readline("minishell -> ");
			add_history(input);
			line = ft_split(input, ' ');
			list = ft_fill_list(line);
			if (ft_strncmp(list->content, "x") || ft_strncmp(list->content, "pwd") || ft_strncmp(list->content, "cd")
				|| ft_strncmp(list->content, "echo") || ft_strncmp(list->content, "env") || ft_strncmp(list->content, "export"))
				ft_builtins(list, env, export);
		}
	}
	return (0);
}