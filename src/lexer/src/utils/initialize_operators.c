/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_operators.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:36:06 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/01/30 19:03:21 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_private.h"

char	**initialize_operators(void)
{
	char	**operators;

	operators = ft_malloc(8 * sizeof(char *));
	operators[0] = str_dup("||");
	operators[1] = str_dup("&&");
	operators[2] = str_dup("|");
	operators[3] = str_dup("<<");
	operators[4] = str_dup(">>");
	operators[5] = str_dup("<");
	operators[6] = str_dup(">");
	operators[7] = NULL;
	return (operators);
}
