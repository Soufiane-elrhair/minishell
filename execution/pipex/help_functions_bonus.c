/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selrhair <selrhair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:18:30 by selrhair          #+#    #+#             */
/*   Updated: 2023/03/21 21:27:35 by selrhair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex_bonus.h"

int	**ft_pipe(int ac)
{
	int	i;
	int	**p;

	i = 0;
	p = malloc(sizeof(int *) * (ac - 4));
	while (i < (ac - 4))
	{
		p[i] = malloc(sizeof(int) * 2);
		i++;
	}
	i = 0;
	while (i < (ac - 4))
	{
		if (pipe(p[i]) == -1)
		{
			perror ("pipe");
			exit (1);
		}
		i++;
	}
	return (p);
}

void	ft_free_pipe(int ac, int **p)
{
	int	i;

	i = 0;
	while (i < ac - 4)
	{
		free(p[i]);
		i++;
	}
	free (p);
}

int	ft_check(char **av, int j, int k)
{
	int	i;

	i = 0;
	if (ft_strlen(av[j]) < 1)
	{
		access(av[j], X_OK);
		if (k)
		{
			perror (av[j]);
		}
		return (126);
	}
	return (0);
}

int	get_path(t_data *vars, char **av, char **env, int j)
{
	vars->i = 0;
	vars->paths = NULL;
	vars->error = ft_check(av, j, 1);
	if (vars->error)
		exit (vars->error);
	while (env[vars->i++])
	{
		if (ft_strncmp(env[vars->i], "PATH"))
		{
			vars->paths = ft_split(env[vars->i], ':');
			break ;
		}
	}
	vars->i = 0;
	while (vars->paths && vars->paths[vars->i])
	{
		if (!access(ft_strjoin2(vars->paths[vars->i],
					ft_strjoin2("/", ft_split(av[j], ' ')[0])), X_OK))
		{
			vars->path = vars->paths[vars->i];
			return (0);
		}
		vars->i++;
	}
	return (127);
}
