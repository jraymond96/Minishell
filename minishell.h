/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 15:30:55 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/07 20:35:58 by jraymond         ###   ########.fr       */
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
int				check_entry(char *str);
char			**pars_path(char **envp);
int				cmp_path(char *path1, char *path2);
int				len_path(char *str);
int				how_path(char *path);
int				path_permi(char **path);

#endif
