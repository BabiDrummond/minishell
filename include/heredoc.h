/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 00:44:52 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/29 02:13:29 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "execution.h"
# include "parser.h"
# include "utils.h"

int		collect_heredocs(t_shell *ctx, t_ast *ast);
int		redirect_heredoc(char **target);
char	**split_content_heredoc(t_word *words);

#endif
