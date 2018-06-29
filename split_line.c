/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 17:57:57 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/29 19:01:47 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		nb_of_words(char *str, int size)
{
	int	words;

	words = 0;
	while (size && *str)
	{
		while (size && *str && (*str == ' ' || *str == '\t' || *str == '\n' ||
				   	*str == '"' || *str == 39))
		{
			size--;
			str++;
		}
		if (*str && *str != ' ' && *str != '\t' && *str != '\n' &&
				*str != '"' && *str != 39)
			words++;
		while (size && *str && *str != ' ' && *str != '\t' && *str != '\n' &&
				*str != '"' && *str != 39)
		{
			str++;
			size--;
		}
	}
	return (words);
}

int		handle_word(char *str, char **new, int size)
{
	int	len;

	while (size > 0 && (str[size] == ' ' || str[size] == '\t' ||
			   str[size] == '\n' || str[size] == '"' || str[size] == 39))
		size--;
	len = 0;
	while (size > 0 && str[size] != ' ' && str[size] != '\t' &&
			   str[size] != '\n' && str[size] != '"' && str[size] != 39)
	{
		size--;
		len++;
	}
	if (size == 0)
		len++;
	if (str[size] == ' ' || str[size] == '\t' || str[size] == '\t' ||
			str[size] == '"' || str[size] == 39)
		*new = ft_memdup(&str[size + 1], len);
	else
		*new = ft_memdup(&str[size], len);
	if (!(*new))
		exit(0);
	return (size);
}

char	**split_line(char *str, size_t size)
{
	int		words;
	char	**new;
	int		i;

	i = size;
	words = nb_of_words(str, --size);
	if (!(new = (char**)ft_malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	new[words] = NULL;
	while (--words >= 0)
		size = handle_word(str, &new[words], size);
	return (new);
}
