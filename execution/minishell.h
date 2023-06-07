/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selrhair <selrhair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:54:44 by selrhair          #+#    #+#             */
/*   Updated: 2023/06/07 14:59:09 by selrhair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(char *content);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
int		ft_strncmp(char *s1, char *s2);
char	**ft_split(char const *s, char c);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_strchr(const char *s, int c);
t_list	*ft_fill_list(char **line);
void	ft_echo(t_list *list);
void	ft_env(char **env, t_list *export);

#endif