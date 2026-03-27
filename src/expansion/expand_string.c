/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 00:51:06 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/27 02:47:08 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"
#include "execution.h"

t_list		*expand_string(t_shell *ctx, t_list *words, int non_expandable);
static char	*expand_content(t_shell *ctx, t_word *word, int non_expandable);
static int	expand_variable(t_shell *ctx, char **new_str, char *str);
static char	*get_key(char *word);

t_list	*expand_string(t_shell *ctx, t_list *words, int non_expandable)
{
	t_word	*word;
	char	*new_content;

	word = (t_word *)words;
	while (word)
	{
		if (word->link.content)
		{
			new_content = expand_content(ctx, word, non_expandable);
			if (new_content)
				word->link.content = new_content;
		}
		word = (t_word *) word->link.next;
	}
	return (words);
}

static char	*expand_content(t_shell *ctx, t_word *word, int non_expandable)
{
	char	*new_s;
	char	*s;
	int		i;

	i = 0;
	s = (char *) word->link.content;
	new_s = ft_strdup("");
	while (s[i])
	{
		if (s[i] == '$'
			&& (ft_isalnum(s[i + 1]) || s[i + 1] == '_' || s[i + 1] == '?')
			&& word->quote_state != non_expandable)
			i += expand_variable(ctx, &new_s, s + i);
		else
			new_s = append_char(new_s, s[i++]);
	}
	return (new_s);
}

static int	expand_variable(t_shell *ctx, char **new_str, char *str)
{
	char	*key;
	char	*value;
	int		key_len;

	key_len = 0;
	key = get_key(str + 1);
	if (ft_strcmp(key, "?") == 0)
		value = ft_itoa(ctx->exit_status);
	else
		value = var_get_value(ctx->vars, key);
	if (value)
		*new_str = ft_strjoin(*new_str, value);
	key_len = ft_strlen(key) + 1;
	return (key_len);
}

static char	*get_key(char *word)
{
	char	*key;
	int		i;

	i = 0;
	while (word[i])
	{
		if (!ft_isalnum(word[i]) && word[i] != '_' && word[i] != '?')
			break ;
		if (word[i] == '?' && ++i)
			break ;
		i++;
	}
	key = ft_substr(word, 0, i);
	return (key);
}
