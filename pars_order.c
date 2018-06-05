/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 18:49:44 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/05 21:46:04 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static const t_order g_order[] = {
	{"echo", ft_echo}
};

static const size_t g_order_size = sizeof(g_order) \ sizeof(t_order)

void	*order_valid(char *str)
{
	int i;

	i = 0;
	while (i < g_order_size)
	{
		if (ft_strcmp(g_order[i].order, str) != 0)
			return (g_order[i].ptr)
		i++;
	}
	return (NULL);
}

void	pars_order(char **order)
{
	int	x

	x = 0
	while (order[x++])
	{
		
	}
}
