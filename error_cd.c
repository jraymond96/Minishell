/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 08:41:05 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/29 16:14:02 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_error1cd(char **param, char *pwd, char *path)
{
	if (!ft_strstr(pwd, *param))
		ft_dprintf(2, "cd: string not in pwd: %s\n", *param);
	else
		ft_dprintf(2, "cd: no such file or directory: %s\n", path);
	return (0);
}

int		ft_error2cd(int ret, char *param)
{
	if (ret == -2)
		ft_printf("cd: no such file or directory: %s\n", param);
	else
		ft_printf("cd: permission denied: %s\n", param);
	return (-1);
}

int		error_cd(char **param)
{
	int	x;

	x = 0;
	if (!param)
		return (0);
	else if (len_envp(param) > 2)
	{
		ft_putstr_fd("cd: too many arguments\n", 2);
		return (-1);
	}
	else if ((*param)[0] == '-')
	{
		ft_putstr_fd("usage: cd [folder]\n", 2);
		return (-1);
	}
	return (0);
}
