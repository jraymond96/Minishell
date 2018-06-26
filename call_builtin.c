/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 13:50:52 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/26 19:18:03 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	call_builtin(int ret, char ***env, char **split)
{
	(void)env;
	if (ret == 1)
		return;
	else if (ret == 2)
	{
		if (ft_setenv(split, env) == -1)
			exit (0);
	}
	else if (ret == 3)
		ft_unsetenv(split, *env);
	else if (ret == 4)
	{
		split[1] ? ft_cd(&split[1], *env) : ft_cd(NULL, *env);
	}
	else if (ret == 5)
		ft_echo(split);
}
