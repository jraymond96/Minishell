/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pars_entry.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 20:15:46 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/29 18:06:56 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wrong_pars(char *str, int x)
{
	if (x == 1)
		ft_dprintf(2, "zsh: parse error near `%c%c'\n", str[-1], *str);
	else
		ft_dprintf(2, "zsh: commande not found `%c'\n", *str);
}

int		valid_separator(char c)
{
	if (ft_isalnum(c) == 1 || c == '.' || c == '_' || c == '-' || c == '/' ||
			c == '~' || c == '=' || c == '"' || c == 39)
		return (1);
	else
		return (0);
}

char	*semicolon(char *str)
{
	int	x;

	x = 1;
	while (str[x] == ' ')
		x++;
	if (!str[x])
		return (&str[x]);
	if (*str == ';')
	{
		if (valid_separator(str[x]) == 1 || (str[x] == ';' && x != 1))
			return (&str[x]);
	}
	else
	{
		if (valid_separator(str[x]) == 1 || str[x] == ';')
			return (&str[x]);
	}
	*str == ';' ? wrong_pars(&str[x], x) : wrong_pars(&str[x], 0);
	return (NULL);
}

char	*next(char *str)
{
	while (*str && valid_separator(*str) == 1)
		str++;
	if (*str == ';' || *str == ' ' || !*str)
		return (str);
	else
		wrong_pars(str, 0);
	return (NULL);
}

int		check_entry(char *str)
{
	while (*str == ' ')
		str++;
	while (*str)
	{
		if (*str == ';' || *str == ' ')
		{
			if (!(str = semicolon(str)))
				return (-1);
		}
		else
		{
			if (!(str = next(str)))
				return (-1);
		}
	}
	return (0);
}
