/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token_result.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:20:06 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/27 02:34:07 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	**create_token_result(void *str, void *token_value)
{
	void	**result;

	result = (void **)safe_calloc(1, sizeof(void *) * 2);
	result[0] = str;
	result[1] = token_value;
	return (result);
}
