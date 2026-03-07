/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 00:44:52 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/07 00:52:00 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/wait.h>
# include <unistd.h>
# include "lexer.h"
# include "parser.h"
# include "../libft/include/libft.h"

int	collect_heredocs(t_ast *tokens);
int	should_collect_heredoc(t_token *token);

#endif
