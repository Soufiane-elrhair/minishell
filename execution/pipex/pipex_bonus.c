/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selrhair <selrhair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:40:14 by selrhair          #+#    #+#             */
/*   Updated: 2023/03/22 15:57:08 by selrhair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex_bonus.h"

int	main(int argc, char **argv, char **env)
{
	t_vars	*vars;

	if (argc < 5)
	{
		write (2, "Error\n", 6);
		return (1);
	}
	vars = malloc (sizeof(t_vars));
	vars->here_doc = 0;
	if (!vars)
		exit (1);
	vars->ac = argc;
	vars->av = argv;
	ft_main_help(vars);
	ft_work(vars, env);
}
