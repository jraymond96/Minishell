/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_envp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 09:58:14 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/15 14:49:47 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		len_envp(char **envp)
{
	int len;

	len = 0;
	while (envp[len])
		len++;
	return (len);
}

char	**cpy_envp(char **envp)
{
	char	**new;
	int		len;

	len = len_envp(envp);
	if (!(new = ft_malloc(sizeof(char *) * (len + 1))))
		exit(0);
	new[len] = NULL;
	len = -1;
	while (envp[++len])
		new[len] = ft_strdup(envp[len]);
	return (new);
}
