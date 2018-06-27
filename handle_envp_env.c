/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_envp_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 20:45:24 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/27 20:47:44 by jraymond         ###   ########.fr       */
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

int		if_env(char	**envp, char *param)
{
	int	len;

	len = ft_strclen(param, '=') + 1;
	ft_printf("envp -> %s || len : %d\n", &(*envp)[len], len);
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
	while ((*envp)[++x] && ft_memcmp((*envp)[x], param, len));
	if (!((*envp)[x]))
	{
		if (if_no_env(envp, param) == -1)
			return (-1);
	}
	else
		if_env(&(*envp)[x], param);
	return (0);
}
