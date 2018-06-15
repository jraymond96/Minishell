/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 13:50:52 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/15 15:02:12 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	call_builtin(int ret, char ***env, char **split)
{
	(void)env;
	if (ret == 1)
		return;
	else if (ret == 2)
		return;
	else if (ret == 3)
		ft_unsetenv(split, *env);
	else if (ret == 4)
		return;
	else if (ret == 5)
		ft_echo(split);
}
