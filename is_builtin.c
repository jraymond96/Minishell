/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:39:50 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/15 15:36:43 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		is_builtin(char *str)
{
	if (ft_strcmp(str, "env") == 0)
		return (1);
	else if (ft_strcmp(str, "setenv") == 0)
		return (2);
	else if (ft_strcmp(str, "unsetenv") == 0)
		return (3);
	else if (ft_strcmp(str, "cd") == 0)
		return (4);
	else if (ft_strcmp(str, "echo") == 0)
		return (5);
	else
		return (0);
}