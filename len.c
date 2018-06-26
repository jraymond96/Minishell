/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 14:35:05 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/26 18:19:19 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		len_order(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ';')
		i++;
	return (i);
}

int		len_envp(char **envp)
{
	int len;

	len = 0;
	while (envp[len])
		len++;
	return (len);
}
