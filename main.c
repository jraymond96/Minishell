/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 15:16:50 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/27 14:55:12 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*str;
	t_list	*path;
	char	**envcpy;

	(void)argv;
	ft_printf("%7{red}$> %{res}");
	path = NULL;
	envcpy = cpy_envp(envp);
	while ((argc = get_next_line(2, &str)))
	{
		if (argc == -1)
		{
			ft_putstr("GNL failed\n");
			break;
		}
		if (ft_strcmp(str, "exit") == 0)
			break;
		if (check_entry(str) == 0)
			ft_printf("%#{green}%s%{res}\n", str);
		else
			ft_printf("%#{red}!!!! %s !!!!%{res}\n", str);
		path = handle_path(envcpy);
		pars_order(str, path, &envcpy);
		ft_memdel((void **)&str);
		free_list(&path);
		ft_printf("%7{red}$> %{res}");
	}
	ft_memdel((void **)&str);
	free_split(envcpy);
	free_list(&path);
	return (0);
}
