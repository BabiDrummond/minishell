/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:21:44 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/08 00:45:06 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

static int	word_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	count_words(char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!s || !*s)
		return (count);
	if (s[i++] != c)
		count++;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	char	**arr;
	int		word;
	int		letter;

	word = 0;
	arr = ft_calloc((count_words((char *) s, c) + 1), sizeof(char *));
	if (!arr)
		return (NULL);
	while (*s && *s == c)
		s++;
	while (*s)
	{
		letter = 0;
		arr[word] = ft_calloc(word_len((char *)s, c) + 1, sizeof(char));
		if (!arr[word])
			return (ft_split_free(arr));
		while (*s && *s != c)
			arr[word][letter++] = *s++;
		while (*s && *s == c)
			s++;
		word++;
	}
	return (arr);
}

/*
int main(void)
{
	#include <stdio.h>
	//char *teste = "1-2--3---4----5-----42";
	char **ar = ft_split(0, '0');
	int i;
	
	i = -1;
	while(ar[++i])
		printf("%s\n", ar[i]);
}
*/