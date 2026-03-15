/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 23:54:57 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/14 22:04:55 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static size_t	get_word_parts_length(t_list *word)
{
	size_t	total;
	t_word	*part;

	total = 0;
	part = (t_word *) word;
	while (part)
	{
		total += ft_strlen((char *) part->link.content);
		part = (t_word *) part->link.next;
	}
	return (total);
}

static char	*join_word_parts(t_list *word)
{
	char	*result;
	t_word	*part;
	size_t	total_len;
	size_t	len;
	size_t	i;

	total_len = get_word_parts_length(word);
	result = ft_calloc(1, total_len);
	if (!result)
		return (NULL);
	i = 0;
	part = (t_word *) word;
	while (part)
	{
		len = ft_strlen((char *)part->link.content);
		ft_memcpy(result + i, part->link.content, len);
		i += len;
		part = (t_word *) part->link.next;
	}
	result[i] = '\0';
	return (result);
}

char	**build_argv(t_list *args)
{
	char	**argv;
	int		count;
	int		i;

	count = lst_size(args);
	argv = ft_calloc((count + 1), sizeof(char *));
	if (!argv)
		return (NULL);
	i = 0;
	while (args)
	{
		argv[i] = join_word_parts((t_list *)((t_head *)args->content)->first);
		i++;
		args = args->next;
	}
	argv[i] = NULL;
	return (argv);
}
