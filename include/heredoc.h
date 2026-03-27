/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 00:44:52 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/27 20:27:52 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include <readline/readline.h>
# include <signal.h>
# include "../libft/include/libft.h"
# include "lexer.h"
# include "parser.h"

int		collect_heredocs(t_ast *tokens);
int		redirect_heredoc(char **target);
char	**split_content_heredoc(t_word *words);

#endif
