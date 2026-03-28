/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 20:55:14 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/27 21:36:21 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

# include "lexer.h"
# include "heredoc.h"
# include "../libft/include/libft.h"

# define QUOTE_GUARD '\x01'

typedef struct s_shell	t_shell;

char	**build_argv(t_list	*args);
t_list	*expand(t_shell *ctx, t_list *args);
t_list	*expand_string(t_shell *ctx, t_list *words, int is_heredoc);
char	**split_unquoted(t_word *words);

#endif