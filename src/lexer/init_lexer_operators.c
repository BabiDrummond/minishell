/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lexer_operators.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:36:06 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/17 20:08:56 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**init_lexer_operators(void)
{
	char	**lexer_operators;

	lexer_operators = ft_calloc(8, sizeof(char *));
	lexer_operators[0] = ft_strdup("||");
	lexer_operators[1] = ft_strdup("&&");
	lexer_operators[2] = ft_strdup("|");
	lexer_operators[3] = ft_strdup("<<");
	lexer_operators[4] = ft_strdup(">>");
	lexer_operators[5] = ft_strdup("<");
	lexer_operators[6] = ft_strdup(">");
	lexer_operators[7] = NULL;
	return (lexer_operators);
}
