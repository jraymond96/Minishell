/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 18:49:44 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/15 16:42:04 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_endstr(char *str)
{
	while (*str)
	{
		if (*str != ' ' && *str != ';')
			return (1);
		str++;
	}
	return (0);
}

void	pars_order(char *shell_line, t_list *paths, char ***envp)
{
	int		x;
	int		len;
	int		ret;
	t_list	*good_path;
	char	**split;
	int		z;

	x = 0;
	z = -1;
	len = ft_strlen(shell_line);
	ret = 0;
	while (shell_line[x] && shell_line[x] != ';')
		x++;
	good_path = if_valid_order(paths, shell_line, &ret);
	split = ft_memsplit(shell_line, x);
	if (good_path)
	{
		ret = -1;
		call_order(split, good_path, *envp);
	}
	else
		call_builtin(ret, envp, split);
	free_split(split);
	z = -1;
	while ((*envp)[++z])
		ft_printf("%{green}%s%{res}\n", (*envp)[z]);
	if (x != len && check_endstr(&shell_line[++x]) == 1)
		pars_order(&shell_line[x], paths, envp);
}
