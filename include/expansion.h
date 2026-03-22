/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 20:55:14 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/22 00:00:54 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

# include "lexer.h"
# include "../libft/include/libft.h"

# define QUOTE_GUARD '\x01'

typedef struct s_shell t_shell;

t_list  *expand(t_shell *ctx, t_list *args);
char	**split_unquoted(char *s);
char	**remove_quote_guard(char **argv);

#endif