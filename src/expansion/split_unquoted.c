/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_unquoted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbara.drummond <barbara.drummond@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:21:44 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/21 16:26:19 by barbara.dru      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

static int	in_quote(char c, int *quote)
{
	if (c == QUOTE_GUARD)
		*quote = !*quote;
	return (*quote);
}

static int	count_words(char *s, int *quote)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (!s || !s[i])
		return (count);
	if (!ft_isspace(s[i]))
		count++;
	while (s[i])
	{
		in_quote(s[i], quote);
		if (ft_isspace(s[i]) && s[i + 1] && !ft_isspace(s[i + 1])
			&& !*quote)
			count++;
		i++;
	}
	*quote = FALSE;
	return (count);
}

char	**split_unquoted(char *s)
{
	char	**split;
	int		quote;
	int		len;
	int		word;

	word = 0;
	quote = FALSE;
	split = ft_calloc((count_words(s, &quote) + 1), sizeof(char *));
	if (!split)
		return (NULL);
	while (*s && ft_isspace(*s))
		s++;
	while (*s)
	{
		len = 0;
		while (s[len] && (!ft_isspace(s[len]) || in_quote(s[len], &quote)))
			len++;
		split[word] = ft_substr(s, 0, len);
		if (!split[word++])
			return (ft_split_free(split));
		s += len;
		while (*s && ft_isspace(*s))
			s++;
	}
	return (split);
}
