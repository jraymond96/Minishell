/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:39:50 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/29 18:28:42 by jraymond         ###   ########.fr       */
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
	else if (ft_strcmp(str, "exit") == 0)
		return (6);
	else if (*str == '/' || ft_memcmp(str, "./", 2) == 0)
		return (7);
	return (0);
}
