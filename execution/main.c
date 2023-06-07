/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selrhair <selrhair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:19:06 by selrhair          #+#    #+#             */
/*   Updated: 2023/06/07 16:04:37 by selrhair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

void	ft_export_help(char *content)
{
	char	*tmp;
	int		i;
	int		j;
	int		a;

	i = 0;
	j = 0;
	a = 0;
	if (ft_strchr(content, '='))
	{
		tmp = (char *) malloc(ft_strlen(content) + 2);
		while (content[i])
		{
			if (content[j] == '=' && a ==  0)
			{
				a = 1;
				tmp[i] = content[j];
				i++;
				j++;
				tmp[i] = '"';
				i++;
				continue;
			}
			tmp[i] = content[j];
			i++;
			j++;
		}
		tmp[i] = '"';
		tmp[++i] = '\0';
		printf("declare -x %s\n", tmp);
	}
	else
		printf("declare -x %s\n", content);
}

void	ft_export(char **env, t_list *list, t_list *export)
{
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
		ft_export_help(export->content);
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