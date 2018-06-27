/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 16:44:35 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/27 17:04:02 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		flags(char *param, int x, int flags)
{
	if (x == 0)

}

int		check_entry(char **param)
{
	int	info;
	int	x;

	info = 0;
	x = -1;
	if (!*param)
		return (-1);
	while (param[++x])
	{
		if (param[x][0] == '-')
			flags;
		else if (ft_strchr(param[x], '='))
			modif_envp;
		else
			order_exist;
	}
}

int		inter_env(char **param, char ***envp)
{
	
}
