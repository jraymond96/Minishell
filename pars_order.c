/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 18:49:44 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/14 15:20:45 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_endstr(char *str)
{
	while (*str)
	{
		if (*str != ' ' && *str != ';')
			return (1);
		str++;
	}
	return (0);
}

void	pars_order(char *shell_line, t_list *paths, char **envp)
{
	int		x;
	int		len;
	int		ret;
	t_list	*good_path;

	x = 0;
	len = ft_strlen(shell_line);
	ret = 0;
	while (shell_line[x] && shell_line[x] != ';')
		x++;
	good_path = if_valid_order(paths, shell_line, &ret);
	if (good_path)
	{
		ft_printf("good_path ->");
		write(1, good_path->content, len_path(good_path->content));
		ft_putchar('\n');
	}
	else
		ft_printf("ret -> %d\n", ret);
	if (x != len && check_endstr(&shell_line[++x]) == 1)
		pars_order(&shell_line[x], paths, envp);
}
