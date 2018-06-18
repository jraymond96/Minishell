/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 15:30:55 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/18 15:04:19 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	 s_order
{
	char		*order;
	void		*ptr;
}				t_order;

void			free_split(char **str);
void			free_list(t_list **begin);
int				check_entry(char *str);
t_list			*pars_path(char **envp);
void			pars_order(char *shell_line, t_list *paths, char ***envp);
t_list			*if_valid_order(t_list *paths, char *shell_line, int *ret);
int				cmp_path(char *path1, char *path2);
int				len_path(char *str);
int				how_path(char *path);
int				is_builtin(char *str);
int				len_order(char *str);
char			**cpy_envp(char **envp);
char			**cpy_envp1(char **envp);
int				call_order(char **line, t_list *path, char **envp);
void			call_builtin(int ret, char ***env, char **split);
t_list			*path_permi(t_list *path);
t_list			*handle_path(char **envp);

/*
** -----------------------BUILTINS-----------------------------
*/

int				ft_unsetenv(char **value, char **envp);
int				ft_setenv(char **arg, char ***envp);
int				error_setenv(char **arg);
int				ft_echo(char **arg);

#endif
