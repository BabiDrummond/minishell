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

#include "minishell.h"

char	**initialize_operators(void)
{
	char	**operators;

	operators = ft_calloc(8, sizeof(char *));
	operators[0] = ft_strdup("||");
	operators[1] = ft_strdup("&&");
	operators[2] = ft_strdup("|");
	operators[3] = ft_strdup("<<");
	operators[4] = ft_strdup(">>");
	operators[5] = ft_strdup("<");
	operators[6] = ft_strdup(">");
	operators[7] = NULL;
	return (operators);
}
