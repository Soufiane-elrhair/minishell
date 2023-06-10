/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selrhair <selrhair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:35:59 by selrhair          #+#    #+#             */
/*   Updated: 2023/03/05 14:46:07 by selrhair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex_bonus.h"

void	get_lines(char **av, t_here_doc *vars)
{
	vars->line = get_next_line(0);
	while (vars->line)
	{
		vars->limiter = ft_strjoin2(av[2], "\n");
		if (ft_strncmp(vars->line, vars->limiter))
		{
			free (vars->limiter);
			free (vars->line);
			break ;
		}
		free (vars->limiter);
		vars->store = ft_strjoin1(vars->store, vars->line);
		free (vars->line);
		vars->line = get_next_line(0);
	}
}

int	ft_heredoc(char **av)
{
	t_here_doc	*vars;
	int			p_h[2];

	vars = malloc (sizeof(t_here_doc));
	if (!vars)
		exit (1);
	vars->store = NULL;
	pipe(p_h);
	get_lines(av, vars);
	write (p_h[1], vars->store, ft_strlen(vars->store));
	free (vars->store);
	close (p_h[1]);
	free (vars);
	return (p_h[0]);
}
