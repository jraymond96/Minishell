/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 16:44:35 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/27 20:59:48 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_flags(char *param, char ***envp)
{
	if (param[1] != 'i')
	{
		ft_printf("env: illegal option -- %c", param[1]);
		ft_putendl("usage: env [-i] [name=value ...] [utility [argument ...]]");
		return (-1);
	}
	else
	{
		free_split(*envp);
		*envp = NULL;
	}
	return (0);
}

int		call_order(char **param, char **envp)
{
	t_list	*paths;
	t_list	*good_path;
	int		ret;

	paths = handle_path(envp);
	godd_path = if_valid_order(path, *param, &ret);
	
}

int		iter_env(char **param, char ***envp)
{
	int		x;
	char	*ret;

	x = -1;
	while ((*envp)[++x])
		ft_putendl((*envp)[x]);
	ft_putstr("-------------------------------------------\n");
	x = -1;
	if (param[1][0] == '-')
	{
		if (check_flags(param[1], envp) == -1)
			return (-1);
		x++;
	}
	while (param[++x])
	{
		if ((ret = ft_strchr(param[x], '=')))
		{
			if ((handle_envp(param[x], envp, ret) == -1))
				return (-1);
		}
		else
	}
	x = -1;
	while ((*envp)[++x])
		ft_putendl((*envp)[x]);
	return (0);
}
