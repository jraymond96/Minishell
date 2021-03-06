/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 19:01:35 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/13 05:29:58 by jraymond         ###   ########.fr       */
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

void	del_lstpath(void *content, size_t size_content)
{
	ft_memdel((void **)&content);
	size_content = 0;
}

void	free_list(t_list **begin)
{
	ft_lstdel(begin, del_lstpath);
}
