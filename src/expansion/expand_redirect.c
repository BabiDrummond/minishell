/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_redirect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 21:56:52 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/29 03:55:02 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

char	**expand_redirect(t_shell *ctx, t_redir *redir)
{
	char	**target;
	char	*old_target;

	old_target = ft_strdup((char *)redir->target->link.content);
	if (ft_strcmp(redir->type, "<<") == 0)
	{
		redir->target = (t_word *) expand_string(ctx,
				(t_list *) redir->target, TRUE);
		target = split_content_heredoc(redir->target);
	}
	else
	{
		redir->target = (t_word *) expand_string(ctx,
				(t_list *) redir->target, FALSE);
		target = split_unquoted(redir->target);
	}
	if ((ft_split_size(target) > 1 && ft_strcmp(redir->type, "<<") != 0)
		|| (target && !target[0]))
	{
		ft_putstr_fd(ft_replace("%s: ambiguous redirect\n",
				"%s", old_target), 2);
		return (NULL);
	}
	return (target);
}
