/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_unquoted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 01:01:48 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/27 02:47:21 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"
#include "execution.h"

char		**split_unquoted(t_word *words);
static int	total_words(t_word *words);
static int	count_words(char *s);

char	**split_unquoted(t_word *words)
{
	char	**argv;
	char	**splitted;
	int		i;
	int		j;

	i = 0;
	argv = safe_calloc(total_words(words) + 1, sizeof(char *));
	while (words)
	{
		if (words->quote_state != QUOTE_NONE)
			argv[i] = ft_strjoin(argv[i], words->link.content);
		else
		{
			j = 0;
			splitted = ft_split(words->link.content, ' ');
			argv[i] = ft_strjoin(argv[i], splitted[j++]);
			while (splitted[j])
				argv[++i] = ft_strdup(splitted[j++]);
		}
		words = (t_word *) words->link.next;
	}
	return (argv);
}

static int	total_words(t_word *words)
{
	int		has_content;
	int		word_count;

	word_count = 0;
	has_content = FALSE;
	while (words)
	{
		if (words->quote_state != QUOTE_NONE && !has_content)
		{
			has_content = TRUE;
			word_count++;
		}
		else if (words->quote_state == QUOTE_NONE)
		{
			if (has_content)
				word_count += count_words(words->link.content) - 1;
			else
				word_count += count_words(words->link.content);
			has_content = !has_content;
		}
		words = (t_word *) words->link.next;
	}
	return (word_count);
}

static int	count_words(char *s)
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
		if (ft_isspace(s[i]) && s[i + 1] && !ft_isspace(s[i + 1]))
			count++;
		i++;
	}
	return (count);
}
