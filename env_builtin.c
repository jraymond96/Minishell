/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 14:55:36 by jraymond          #+#    #+#             */
/*   Updated: 2018/07/03 03:35:05 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		nb_call_env(char **param)
{
	int	x;
	int	nb;

	x = -1;
	nb = 0;
	while (param[++x])
	{
		if (ft_memcmp(param[x], "env", 3) == 0)
			nb++;
	}
	return (nb);
}

char	**next_call(char **param)
{
	int	x;

	x = -1;
	while (param[++x] && ft_memcmp(param[x], "env", 3) != 0)
		;
	return (&param[x]);
}

int		ft_env(char **param, char **envp)
{
	int		nb_call;
	char	**new_envp;
	char	**next;
	char	*tmp;

	nb_call = nb_call_env(param);
	if (!envp || !*envp)
		return (0);
	new_envp = cpy_envp(envp);
	while (nb_call--)
	{
		next = next_call((param + 1));
		tmp = *next;
		*next = NULL;
		iter_env(param, &new_envp, nb_call);
		param = next;
		*param = tmp;
	}
	if (new_envp)
		free_split(new_envp);
	return (0);
}
