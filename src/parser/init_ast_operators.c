/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ast_operators.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:36:06 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/19 17:39:15 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	**init_ast_operators(void)
{
	char	**ast_operators;

	ast_operators = ft_calloc(4, sizeof(char *));
	ast_operators[0] = ft_strdup("||");
	ast_operators[1] = ft_strdup("&&");
	ast_operators[2] = ft_strdup("|");
	ast_operators[3] = NULL;
	return (ast_operators);
}
