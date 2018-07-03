/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 18:49:44 by jraymond          #+#    #+#             */
/*   Updated: 2018/07/03 04:47:13 by jraymond         ###   ########.fr       */
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

void	cut_space_usless(char **split)
{
	int	x;
	int	y;

	x = -1;
	while (split[++x])
	{
		y = -1;
		while (split[x][++y] && split[x][y] != ' ' && split[x][y] != ';')
			;
		split[x][y] = '\0';
	}
}

char	*pars_bis_init(char *shell_line, int *ret, int *x, int *len)
{
	*x = 0;
	*len = ft_strlen(shell_line);
	*ret = 0;
	while (shell_line[*x] && shell_line[*x] != ';')
		(*x)++;
	if (shell_line[*x] == ',')
		shell_line++;
	return (shell_line);
}

void	pars_order(char *shell_line, t_list *paths, char ***envp)
{
	int		x;
	int		len;
	int		ret;
	t_list	*good_path;
	char	**split;

	shell_line = pars_bis_init(shell_line, &ret, &x, &len);
	good_path = if_valid_order(paths, shell_line, &ret);
	if (x == 0 && shell_line[x] == ';')
		pars_order(&shell_line[++x], paths, envp);
	if (!(split = split_line(shell_line, x)))
		exit(0);
	cut_space_usless(split);
	if (good_path)
	{
		ret = -1;
		call_order(split, good_path, *envp);
	}
	else
		call_builtin(ret, envp, split);
	free_split(split);
	if (x != len && check_endstr(&shell_line[++x]) == 1)
		pars_order(&shell_line[x], paths, envp);
}
