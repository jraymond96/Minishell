/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 16:44:35 by jraymond          #+#    #+#             */
/*   Updated: 2018/07/03 03:47:10 by jraymond         ###   ########.fr       */
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

int		env_call_order(char **param, char ***envp)
{
	t_list	*paths;
	t_list	*good_path;
	int		ret;

	paths = handle_path(*envp);
	good_path = if_valid_order(paths, *param, &ret);
	if (good_path)
	{
		ret = -1;
		call_order(param, good_path, *envp);
	}
	else
		call_builtin(ret, envp, param);
	return (0);
}

int		write_envp(char **envp)
{
	int	x;

	x = -1;
	if (!envp)
		return (0);
	else
	{
		while (envp[++x])
			ft_printf("%s\n", envp[x]);
	}
	return (0);
}

int		iter_env_bis(char **param, char ***envp, int *x)
{
	char	*ret;

	while (param[++(*x)])
	{
		if ((ret = ft_strchr(param[*x], '=')))
		{
			if ((handle_envp(param[*x], envp, ret) == -1))
				return (-1);
		}
		else
		{
			env_call_order(&param[*x], envp);
			*x = -1;
			break ;
		}
	}
	return (0);
}

int		iter_env(char **param, char ***envp, int nb)
{
	int		x;

	if (len_envp(param) == 1)
	{
		if (!nb)
			return (write_envp(*envp));
		return (0);
	}
	x = 0;
	if (param[1][0] == '-')
	{
		if (check_flags(param[1], envp) == -1)
			return (-1);
		x++;
	}
	if (iter_env_bis(param, envp, &x) == -1)
		return (-1);
	if (x != -1 && !nb)
		return (write_envp(*envp));
	return (0);
}
