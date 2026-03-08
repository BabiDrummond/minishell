/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 23:54:57 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/07 23:59:36 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	count_tokens(t_token *token)
{
	int	total;

	total = 0;
	while (token)
	{
		total++;
		token = (t_token *)token->link.next;
	}
	return (total);
}

static size_t	get_token_parts_length(t_token *token)
{
	size_t	total;
	t_word	*part;

	total = 0;
	part = (t_word *)((t_head *)token->link.content)->first;
	while (part)
	{
		total += ft_strlen((char *)part->link.content);
		part = (t_word *)part->link.next;
	}
	return (total);
}

static char	*join_token_parts(t_token *token)
{
	char	*result;
	t_word	*part;
	size_t	total_len;
	size_t	len;
	size_t	i;

	total_len = get_token_parts_length(token);
	result = malloc(total_len + 1);
	if (!result)
		return (NULL);
	i = 0;
	part = (t_word *)((t_head *)token->link.content)->first;
	while (part)
	{
		len = ft_strlen((char *)part->link.content);
		ft_memcpy(result + i, part->link.content, len);
		i += len;
		part = (t_word *)part->link.next;
	}
	result[i] = '\0';
	return (result);
}

char	**build_argv(t_token *token)
{
	char	**argv;
	int		count;
	int		i;

	count = count_tokens(token);
	argv = malloc(sizeof(char *) * (count + 1));
	if (!argv)
		return (NULL);
	i = 0;
	while (token)
	{
		argv[i] = join_token_parts(token);
		i++;
		token = (t_token *)token->link.next;
	}
	argv[i] = NULL;
	return (argv);
}
