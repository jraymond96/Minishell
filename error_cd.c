/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 08:41:05 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/21 16:31:26 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_error1cd(char **param, char *pwd, char *path)
{
	if (!ft_strstr(pwd, *param))
		ft_printf("cd: string not in pwd: %s\n", *param);
	else
		ft_printf("cd: no such file or directory: %s\n", path);
	return (0);
}

int		error_cd(char **param)
{
	int	x;

	x = 0;
	if (!param)
		return (0);
	else if (len_envp(param) > 2)
	{
		ft_putstr("cd: too many arguments\n");
		return (-1);
	}
	else if ((*param)[0] == '-')
	{
		ft_putstr("usage: cd [folder]\n");
		return (-1);
	}
	return (0);
}
