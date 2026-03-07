/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_token_parts.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 23:17:05 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/07 02:02:03 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

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

char	*join_token_parts(t_token *token)
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
