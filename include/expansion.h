/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 20:55:14 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/21 23:33:49 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

# include "lexer.h"
# include "../libft/include/libft.h"

# define QUOTE_GUARD '\x01'

typedef struct s_shell t_shell;

t_list  *expand(t_shell *ctx, t_list *args);
t_list	*mark_protected_spaces(t_list *args);
char	**split_unquoted(char *s);

#endif