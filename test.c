/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 01:30:00 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/20 08:36:14 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include "minishell.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int	main(int argc, char **argv, char **envp)
{
	argc = -1;
	if (ft_cd(&argv[1], envp) == -1)
		exit (0);
	return (0);
}
