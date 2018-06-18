/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_setenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 14:56:18 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/18 15:14:47 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		error_setenv(char **arg)
{
	int	x;

	x = 0;
	while (arg[x])
		x++;
	if (x < 3)
	{
		ft_putstr_fd("usage: setenv [name] [value] [overwrite]\n", 2);
		return (-1);
	}
	if (x > 4)
	{
		ft_putstr_fd("setenv : too many arguments\n", 2);
		return (-1);
	}
	if (x < 4)
	{
		if (ft_strlen(arg[2]) != 1 || ft_isdigit(arg[2][0]) == 0)
		{
			ft_putstr_fd("setenv : wrong overwrite\n", 2);
			return (-1);
		}
		return (x);
	}
	if (ft_strlen(arg[3]) != 1 || ft_isdigit(arg[3][0]) == 0)
	{
		ft_putstr_fd("setenv : wrong overwrite\n", 2);
		return (-1);
	}
	else
		return (0);
}
