/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 20:55:06 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/28 23:34:52 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

t_list	*expand(t_shell *ctx, t_list *args)
{
	t_list	*arg;

	arg = args;
	while (arg)
	{
		((t_head *)arg->content)->first = (t_node *) expand_string(ctx,
				(t_list *)((t_head *)arg->content)->first, FALSE);
		arg = arg->next;
	}
	return (args);
}
