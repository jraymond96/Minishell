/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 19:01:35 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/08 17:56:20 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_memdel((void **)&str[i++]);
	ft_memdel((void **)&str);
}

void	free_list(t_list *begin)
{
	t_list	*elem;
	t_list	*tmp;

	elem = begin;
	while (elem)
	{
		tmp = elem->next;
		free(elem);
		elem = tmp;
	}
}
