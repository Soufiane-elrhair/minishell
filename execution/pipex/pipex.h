/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selrhair <selrhair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:48:41 by selrhair          #+#    #+#             */
/*   Updated: 2023/06/08 09:36:45 by selrhair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<unistd.h>
# include"G_N_L/get_next_line.h"

typedef struct s_vars
{
	char	**paths;
	char	*path;
	int		path_result;
	int		*fd;
	pid_t	child;
	pid_t	child2;
	int		fl;
	int		fl2;
	int		status;
}	t_vars;

void	first_child_abs(char **av, char **env, t_vars *vars);
void	first_child(char **av, char **env, t_vars *vars);
void	second_child_abs(char **av, char **env, t_vars *vars);
void	second_child(char **av, char **env, t_vars *vars);
int		get_path(t_vars *vars, char **av, char **env, int j);
void	first_child_abs(char **av, char **env, t_vars *vars);
void	second_child_abs(char **av, char **env, t_vars *vars);
int		ft_strncmp(char *s1, char *s2);
char	**ft_split(char const *s, char c);
char	*ft_strjoin2(char const *s1, char const *s2);
int		ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *src);

#endif