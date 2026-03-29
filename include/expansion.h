/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 20:55:14 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/28 23:42:08 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

# include "../libft/include/libft.h"
# include "lexer.h"
# include "heredoc.h"
# include "variables.h"

# define QUOTE_GUARD '\x01'

typedef struct s_shell	t_shell;

/* Expansion */
char	**expand_redirect(t_shell *ctx, t_redir *redir);
t_list	*expand_string(t_shell *ctx, t_list *words, int is_heredoc);
t_list	*expand(t_shell *ctx, t_list *args);

/* Utils */
char	**build_argv(t_list	*args);
char	**split_unquoted(t_word *words);

#endif