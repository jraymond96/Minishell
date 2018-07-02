/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 08:41:05 by jraymond          #+#    #+#             */
/*   Updated: 2018/07/02 04:15:32 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_error1cd(char *param, char *path)
{
	(void)param;
	ft_dprintf(2, "cd: no such file or directory: %s\n", path);
	return (0);
}

int		ft_error2cd(int ret, char *param)
{
	if (ret == -2)
		ft_dprintf(2, "cd: no such file or directory: %s\n", param);
	else
		ft_dprintf(2, "cd: permission denied: %s\n", param);
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
	return (0);
}
