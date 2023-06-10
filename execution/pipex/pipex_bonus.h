/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selrhair <selrhair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:42:04 by selrhair          #+#    #+#             */
/*   Updated: 2023/03/21 18:20:47 by selrhair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<unistd.h>
# include"libft/libft.h"
# include"G_N_L/get_next_line.h"

typedef struct s_vars
{
	int		ac;
	char	**av;
	char	**env;
	int		p_h;
	int		**p;
	int		i;
	pid_t	*f;
	int		input_fd;
	int		output_fd;
	int		p_i;
	int		here_doc;
}	t_vars;

typedef struct s_data
{
	char	*path;
	int		i;
	char	**paths;
	int		status;
	int		error;
}	t_data;

typedef struct s_here_doc
{
	char	*store;
	int		p_h[2];
	char	*line;
	char	*limiter;
}	t_here_doc;

int		**ft_pipe(int ac);
void	ft_free_pipe(int ac, int **p);
int		ft_check(char **av, int j, int k);
int		get_path(t_data *vars, char **av, char **env, int j);
void	ft_fork(t_vars *vars, char **env);
void	ft_close(t_vars *vars, int s);
int		ft_heredoc(char **av);
void	ft_main_help(t_vars *vars);
void	ft_work(t_vars *vars, char **env);

#endif