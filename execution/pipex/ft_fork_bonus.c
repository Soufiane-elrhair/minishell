/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::   */
/*   ft_fork_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selrhair <selrhair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:30:36 by selrhair          #+#    #+#             */
/*   Updated: 2023/03/20 11:39:53 by selrhair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex_bonus.h"

void	ft_abs_path(char **av, char **env, int i)
{
	char	**path;

	if (access(ft_split(av[i], ' ')[0], X_OK))
	{
		perror (av[i]);
		exit (127);
	}
	if (av[i][0] == ' ' || av[i][ft_strlen(av[i]) - 1] == ' ')
	{
		perror (av[i]);
		exit (127);
	}
	path = ft_split(av[i], ' ');
	execve(path[0], path, env);
	exit (126);
}

void	ft_normal_comand(char **av, char **env, int i)
{
	int		get_path_result;
	t_data	*vars;

	vars = malloc(sizeof(t_data));
	get_path_result = get_path(vars, av, env, i);
	if (get_path_result)
	{
		access(av[i], X_OK);
		perror(av[i]);
		exit (get_path_result);
	}
	if (av[i][0] == ' ' || av[i][ft_strlen(av[i]) - 1] == ' ')
	{
		perror (av[i]);
		exit (127);
	}
	execve(ft_strjoin2(ft_strjoin2(vars->path, "/"),
			ft_split(av[i], ' ')[0]), ft_split(av[i], ' '), env);
}

void	input_dup(t_vars *vars)
{
	if (vars->i != 3 && vars->here_doc == 1)
		close (vars->p_h);
	if (vars->i == 3 && vars->here_doc == 1)
		vars->input_fd = vars->p_h;
	else if (vars->i == 2 && vars->here_doc == 0)
	{
		vars->input_fd = open (vars->av[1], O_RDONLY);
		if (vars->input_fd == -1)
			exit (0);
	}
	else
		vars->input_fd = vars->p[vars->p_i - 1][0];
	dup2 (vars->input_fd, 0);
}

void	ft_fork_help(t_vars *vars)
{
	input_dup(vars);
	if (vars->i == vars->ac - 1 && vars->here_doc == 1)
		vars->output_fd = open (vars->av[vars->ac],
				O_CREAT | O_RDWR | O_APPEND, 0777);
	else if (vars->i == vars->ac - 2 && vars->here_doc == 0)
	{
		vars->output_fd = open (vars->av[vars->ac - 1],
				O_CREAT | O_RDWR | O_TRUNC, 0777);
		if (access (vars->av[vars->ac - 1], W_OK))
		{
			perror(vars->av[vars->ac - 1]);
			exit (1);
		}
	}
	else
		vars->output_fd = vars->p[vars->p_i][1];
	dup2 (vars->output_fd, 1);
}

void	ft_fork(t_vars *vars, char **env)
{
	int	s;

	vars->i = vars->i + 2;
	s = vars->i - 2;
	ft_close(vars, s);
	vars->p_i = vars->i - 2;
	if (vars->here_doc)
		vars->i++;
	ft_fork_help(vars);
	if (!access(ft_split (vars->av[vars->i], ' ')[0],
		X_OK) || ft_strchr(vars->av[vars->i], '/'))
	{
		ft_abs_path(vars->av, env, vars->i);
	}
	else
		ft_normal_comand(vars->av, env, vars->i);
}
