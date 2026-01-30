/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:41:04 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/01/30 12:44:02 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringft.h"

static int	count_words(char *s)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (ft_isspace(*s))
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static char	*word_dup(char *start, char *end)
{
	int		len;
	char	*word;

	len = end - start;
	word = ft_malloc(len + 1);
	ft_memcpy(word, start, len);
	word[len] = '\0';
	return (word);
}

char	**ft_split(char *s)
{
	char	**result;
	int		words;
	int		i;
	char	*start;

	words = count_words(s);
	i = 0;
	result = ft_malloc(sizeof(char *) * (words + 1));
	while (*s)
	{
		while (*s && ft_isspace(*s))
			s++;
		if (*s)
		{
			start = s;
			while (*s && !ft_isspace(*s))
				s++;
			result[i++] = word_dup(start, s);
		}
	}
	result[i] = NULL;
	return (result);
}
