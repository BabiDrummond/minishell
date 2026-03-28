/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_redirect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 21:56:52 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/27 21:57:39 by bmoreira         ###   ########.fr       */
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
	if (ft_split_size(target) > 1 && ft_strcmp(redir->type, "<<") != 0)
	{
		printf("%s: ambiguous redirect\n", old_target);
		return (NULL);
	}
	return (target);
}
