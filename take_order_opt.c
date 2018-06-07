/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_order_opt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 02:47:10 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/07 15:09:18 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		valid_order(char *order)
{
	int	x;

	x = 0;
	while (order[x] != ' ' && order[x] != ';')
		x++;
}

char	*next_order_opt(char *order, char **new)
{
	while (*order == ' ')
		order++;

}
