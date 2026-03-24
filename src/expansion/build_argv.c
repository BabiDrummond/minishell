/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 20:04:04 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/23 23:55:28 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

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

int	total_words(t_word *words)
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
				word_count+= count_words(words->link.content) - 1;
			else
				word_count+= count_words(words->link.content);
			has_content = !has_content;
		}
		words = (t_word *) words->link.next;
	}
	return (word_count);
}

char	**split_unquoted(t_word *words)
{
	char	**argv;
	char	**splitted;
	int		i;
	int		j;

	i = 0;
	argv = ft_calloc(total_words(words) + 1, sizeof(char *));
	while (words)
	{
		if (words->quote_state != QUOTE_NONE)
			argv[i] = ft_strjoin_free(argv[i], words->link.content, TRUE, FALSE);
		else
		{
			j = 0;
			splitted = ft_split(words->link.content, ' ');
			argv[i] = ft_strjoin_free(argv[i], splitted[j++], TRUE, FALSE);
			while (splitted[j])
				argv[++i] = ft_strdup(splitted[j++]);
			ft_split_free(splitted);
		}
		words = (t_word *) words->link.next;
	}
	return (argv);
}

char	**merge_splits(char **first, char **second)
{
	char	**result;
	int		size;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	size = ft_split_size(first) + ft_split_size(second);
	result = ft_calloc(size + 1, sizeof(char *));
	while (first && first[i])
		result[k++] = ft_strdup(first[i++]);
	while (second && second[j])
		result[k++] = ft_strdup(second[j++]);
	ft_split_free(first);
	ft_split_free(second);
	return (result);
}

char	**build_argv(t_list	*args)
{
	char	**argv;

	argv = NULL;
	if (!args)
		return (NULL);
	while (args)
	{
		argv = merge_splits(argv, 
			split_unquoted((t_word *)((t_head *)args->content)->first));
		args = args->next;
	}
	return (argv);
}
