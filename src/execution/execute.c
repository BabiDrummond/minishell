/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 03:51:40 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/02/22 04:04:21 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"
#include <unistd.h>

int	execute(t_ast *tokens)
{
	char	*delimiter;
	int		pipefd[2];
	pid_t	pid;

	if (tokens == NULL)
		return (0);
	if (execute(tokens->left))
		return (1);
	if (execute(tokens->right))
		return (1);
    
    t_token *token = (t_token *)tokens->value;
	
    if (token && token->is_operator)
    {
        t_string *operator = token->link.content;
        char *symbol = operator->value;
        printf("Operator \"%s\" is not implemented!\n", symbol);
        return (0);
	}

    t_list *words = (t_list *)tokens->value;

    char **argv = malloc(sizeof(char *) * (words->count + 1));
    int i = 0;
    t_node *current = words->first;
    while (current != NULL)
    {
        argv[i++] = ((t_string *)current->content)->value;
        current = current->next;
    }
    argv[i] = NULL;
    
    pid_t pid = fork();
    if (pid == 0)
    {
        execvp(argv[0], argv);
        perror("execvp failed");
        exit(1);
    }
    else if (pid > 0)
    {
        int status;
        waitpid(pid, &status, 0);
        free(argv);
        return (WEXITSTATUS(status));
    }
    else
    {
        perror("fork failed");
        free(argv);
        return (1);
    }
}