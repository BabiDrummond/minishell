/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 00:44:52 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/28 02:47:36 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include <readline/readline.h>
# include <signal.h>
# include "../libft/include/libft.h"
# include "lexer.h"
# include "parser.h"
# include "execution.h"
# include "shell.h"

int		collect_heredocs(t_shell *ctx, t_ast *ast);
int		redirect_heredoc(char **target);
char	**split_content_heredoc(t_word *words);

#endif
