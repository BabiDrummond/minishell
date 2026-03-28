/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:57:44 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/28 01:07:36 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_head	*tokenize(char *prompt, char **operators)
{
	void	**result;
	t_head	*tokens;

	tokens = lst_new_head();
	while (*prompt)
	{
		result = get_next_token(prompt, operators);
		if (!result)
			return (NULL);
		if (result[1] != NULL)
			lst_add_last(tokens, result[1]);
		prompt = (char *)result[0];
	}
	return (tokens);
}
