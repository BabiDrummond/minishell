/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token_result.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:20:06 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/01/30 18:35:03 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	**create_token_result(void *str, void *token_value)
{
	void	**result;

	result = (void **)ft_calloc(1, sizeof(void *) * 2);
	result[0] = str;
	result[1] = token_value;
	return (result);
}
