/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 20:55:06 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/27 02:47:17 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"
#include "execution.h"

t_list	*expand(t_shell *ctx, t_list *args)
{
	t_list	*arg;

	arg = args;
	while (arg)
	{
		((t_head *)arg->content)->first = (t_node *) expand_string(ctx,
				(t_list *)((t_head *)arg->content)->first, QUOTE_SINGLE); 
		arg = arg->next;
	}
	return (args);
}
