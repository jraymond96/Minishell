/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 16:44:35 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/27 19:09:34 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		if_no_env(char ***envp, char *param)
{
	char	**new;
	int		x;

	new = cpy_envp1(*envp);
	free_split(*envp);
	*envp = new;
	x = -1;
	while ((*envp)[++x]);
	if (!((*envp)[x] = ft_strdup(param)))
		return (-1);
	return (0);
}

int		handle_envp(char *param, char ***envp, char *equal)
{
	int		x;
	int		len;

	if (param == equal)
		return (0);
	len = equal - param;
	x = -1;
	while ((*envp)[++x] && ft_memcmp((*envp)[x], param, len));
	if (!((*envp)[x]))
	{
		if (if_no_env(envp, param) == -1)
			return (-1);
	}
	return (0);
}

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

int		iter_env(char **param, char ***envp)
{
	int		x;
	char	*ret;

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
	}
	return (0);
}
