/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 14:10:36 by jraymond          #+#    #+#             */
/*   Updated: 2018/07/04 17:16:27 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_cd(char **param, char **envp)
{
	int	ret;

	ret = ret_fonc_cd(param);
	if (ret == 0)
		cd_normalpath(*param, envp);
	else if (ret == 1)
		cd_no_arg(envp);
	else if (ret == 2)
		cd_two_args(param, envp);
	else if (ret == 3)
		cd_oldpath(envp);
	return (0);
}
