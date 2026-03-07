/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<<< HEAD:include/heredoc.h
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 15:14:43 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/06 19:48:47 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include <stdio.h>
# include <readline/readline.h>
# include <signal.h>
# include <sys/wait.h>
# include <unistd.h>
# include "lexer.h"
# include "../libft/include/libft.h"
========
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 22:42:15 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/22 23:57:57 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H

# include <stdlib.h>
# include "types.h"

void	lst_add_back(t_list **lst, t_list *new);
void	lst_clear_node(t_list *lst, void (*del)(void *));
void	lst_clear(t_list **lst, void (*del)(void *));
void	lst_del_node(t_list **head, t_list *node, void (*del)(void *));
int		lst_size(t_list *lst);
t_list	*lst_last(t_list *lst);
t_list	*lst_new(void *content);
>>>>>>>> builtins:libft/include/lst.h

int	collect_heredocs(t_ast *tokens);
int	should_collect_heredoc(t_token *token);

#endif
