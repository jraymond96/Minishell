/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_fonc_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 04:26:25 by jraymond          #+#    #+#             */
/*   Updated: 2018/07/02 05:14:19 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		change_oldpwd(char **envp, char *path)
{
	int	x;

	x = -1;
	while (ft_memcmp(envp[++x], "OLDPWD", 6) != 0)
		;
	if (envp[x])
	{
		ft_memdel((void **)&envp[x]);
		if (!(envp[x] = (char *)ft_malloc(ft_strlen(path) + 8)))
			exit(0);
		ft_mem2join(envp[x], "OLDPWD=", path, ft_strlen(path));
	}
	return (0);
}

int		ret_fonc_cd(char **param)
{
	int	ret;
	
	if (!param)
		return (1);
	ret = len_envp(param);
	if (ret == 2)
		return (2);
	else if (ret > 2)
	{
		ft_putstr_fd("cd: too many arguments\n", 2);
		return (-1);
	}
	else if ((*param)[0] == '-')
	{
		if ((*param)[1])
		{
			ft_putstr_fd("usage: cd [-] or [folder]\n", 2);
			return (-1);
		}
		else
			return (3);
	}
	return (0);
}
