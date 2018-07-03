/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_home.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 02:32:11 by jraymond          #+#    #+#             */
/*   Updated: 2018/07/03 05:09:45 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*found_home(char **envp)
{
	int	x;

	x = -1;
	if (!envp)
		return (NULL);
	while (envp[++x] && ft_memcmp(envp[x], "HOME", 4) != 0)
		;
	return (envp[x]);
}
