/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 23:19:10 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/06 23:30:27 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "lexer.h"
# include "parser.h"
# include "../libft/include/libft.h"

int     execute(t_ast *node, char **envp);
char	*find_cmd_path(t_list *vars, char *cmd);
char	*join_token_parts(t_token *token);

#endif