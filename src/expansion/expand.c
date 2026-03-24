/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 20:55:06 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/23 23:56:08 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"
#include "execution.h"

int	is_allowed_char(char c)
{
	return (ft_isalnum(c) || c == '_' || c == '?');
}

char	*get_key(char *word)
{
	char	*key;
	int		i;

	i = 0;
	while (word[i])
	{
		if (!is_allowed_char(word[i]))
			break ;
		if (word[i] == '?' && ++i)
			break ;
		i++;
	}
	key = ft_substr(word, 0, i);
	return (key);
}

int	expand_variable(t_shell *ctx, char **new_str, char *str)
{
	char	*key;
	char	*value;
	int     key_len;

	key_len = 0;
	key = get_key(str + 1);
	if (ft_strcmp(key, "?") == 0)
		value = ft_itoa(ctx->exit_status);
	else
		value = var_get_value(ctx->vars, key);
	if (value)
		*new_str = ft_strjoin_free(*new_str, value, TRUE, FALSE);
	key_len = ft_strlen(key) + 1;
	free(key);
	return (key_len);
}

char    *to_str(char c)
{
	char    *new;
	
	new = ft_calloc(1 + 1, sizeof(char));
	new[0] = c;
	return (new);
}

t_list	*expand_string(t_shell *ctx, t_list *words, int non_expandable)
{
	t_word	*word;
	char	*new_s;
	char	*s;
	int		i;

	word = (t_word *)words;
	while (word)
	{
		s = (char *) word->link.content;
		if (s)
		{
			new_s = ft_strdup("");
			i = 0;
			while (s[i])
				if (s[i] == '$' && is_allowed_char(s[i + 1])
					&& word->quote_state != non_expandable)
					i+= expand_variable(ctx, &new_s, s + i);
				else
					new_s = ft_strjoin_free(new_s, to_str(s[i++]), TRUE, TRUE);
			free(word->link.content);
			word->link.content = new_s;
		}
		word = (t_word *) word->link.next;
	}
	return (words);
}

t_list  *expand(t_shell *ctx, t_list *args)
{
	t_list *arg;

	arg = args;
	while (arg)
	{
		((t_head *)arg->content)->first = (t_node *) expand_string(ctx,
			(t_list *)((t_head *)arg->content)->first, QUOTE_SINGLE); // this is going to leak. needs to free old list before assigning new one.
		arg = arg->next;
	}
	return (args);
}
