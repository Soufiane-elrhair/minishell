/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selrhair <selrhair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:38:12 by selrhair          #+#    #+#             */
/*   Updated: 2023/03/22 15:57:01 by selrhair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex_bonus.h"

void	ft_close(t_vars *vars, int s)
{
	int	k;

	k = 0;
	while (k < vars->ac - 4)
	{
		if (s != k)
		{
			close (vars->p[k][1]);
		}
		if (s + 1 != k && s != k + 1)
		{
			close (vars->p[k][0]);
		}
		k++;
	}
}

void	ft_work_help(t_vars *vars)
{
	int	m;
	int	status;

	m = 0;
	while (m < vars->ac - 4)
	{
		close (vars->p[m][0]);
		close (vars->p[m][1]);
		m++;
	}
	m = 0;
	while (m < vars->ac - 3)
	{
		waitpid(vars->f[m], &status, WUNTRACED);
		if (WEXITSTATUS(status) && m == vars->ac - 4)
		{
			exit (WEXITSTATUS(status));
		}
		m++;
	}
	ft_free_pipe(vars->ac, vars->p);
}

void	ft_work(t_vars *vars, char **env)
{
	vars->f = malloc (sizeof(pid_t) * (vars->ac - 3));
	vars->i = 0;
	vars->p = ft_pipe(vars->ac);
	while (vars->i < (vars->ac - 3))
	{
		vars->f[vars->i] = fork();
		if (vars->f[vars->i] == 0)
		{
			ft_fork(vars, env);
		}
		vars->i++;
	}
	ft_work_help(vars);
}

void	ft_main_help(t_vars *vars)
{
	if (ft_strncmp(vars->av[1], "here_doc"))
	{
		if (vars->ac < 6)
			exit (1);
		vars->here_doc = 1;
		vars->p_h = ft_heredoc(vars->av);
		vars->ac--;
	}
	else
	{
		if (access(vars->av[1], F_OK))
		{
			perror (vars->av[1]);
			open (vars->av[vars->ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0777);
		}
	}
}
