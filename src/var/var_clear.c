/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 00:00:47 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/23 00:39:04 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	var_clear(void *var_content)
{
	t_var	*var;

	var = var_content;
	ft_free(&var->key);
	ft_free(&var->value);
	ft_free((char **)&var_content);
}
