/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_envp_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 20:45:24 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/29 14:05:12 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		if_no_env(char ***envp, char *param)
{
	char	**new;
	int		x;

	new = cpy_envp1(*envp);
	if (!envp)
		free_split(*envp);
	*envp = new;
	x = -1;
	while ((*envp)[++x]);
	if (!((*envp)[x] = ft_strdup(param)))
		return (-1);
	return (0);
}

int		if_env(char	**envp, char *param)
{
	int	len;

	len = ft_strclen(param, '=') + 1;
	if (!param[len])
	{
		(*envp)[len] = '\0';
	}
	else
		ft_strcpy(&(*envp)[len], &param[len]);
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
	if (*envp)
		while ((*envp)[++x] && ft_memcmp((*envp)[x], param, len));
	if (!*envp || !((*envp)[x]))
	{
		if (if_no_env(envp, param) == -1)
			exit(0);
	}
	else
		if_env(&(*envp)[x], param);
	return (0);
}
