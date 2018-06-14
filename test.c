/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 01:30:00 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/14 13:39:34 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include "minishell.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int		call_unsetenv(char **argv)
{
	//return (setenv(argv[1], argv[2], 1));
	return (unsetenv(argv[1]));
}

int	main(int argc, char **argv, char **envp)
{
	argc = -1;
	/*while (envp[++argc])
		ft_putendl(envp[argc]);*/
	ft_echo(argv);
	return (0);
	ft_putstr("------------------------------------------\n");
	argc = -1;
	while (envp[++argc])
		ft_putendl(envp[argc]);
	return (0);
	if (call_unsetenv(argv) == -1)
	{
		ft_putendl(strerror(errno));
		return (0);
	}
	while (envp[++argc])
		ft_putendl(envp[argc]);
	return (0);
}
