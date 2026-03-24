/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 20:55:06 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/23 20:21:59 by bmoreira         ###   ########.fr       */
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
		if (word[i++] == '?')
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

// t_list	*add_quote_guard(t_list *words)
// {
// 	t_word	*word;
// 	char	*new_s;
// 	char	*s;
// 	int		len;

// 	word = (t_word *) words;
// 	while (word)
// 	{
// 		s = (char *) word->link.content;
// 		if (word->quote_state == QUOTE_DOUBLE 
// 			|| word->quote_state == QUOTE_SINGLE)
// 		{
// 			len = ft_strlen(s);
// 			new_s = ft_calloc(len + 3, sizeof(char));
// 			new_s[0] = QUOTE_GUARD;
// 			new_s[len + 1] = QUOTE_GUARD;
// 			ft_memcpy(new_s + 1, s, len);
// 			free(word->link.content);
// 			word->link.content = new_s;
// 		}
// 		word = (t_word *) word->link.next;
// 	}
// 	return (words);
// }

// int	count_chr(char *str, char c)
// {
// 	int	count;
// 	int	i;
	
// 	i = 0;
// 	count = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == c)
// 			count++;
// 		i++;
// 	}
// 	return (count);
// }

// char	*ft_strtrim(char *str, char c)
// {
// 	char	*new_str;
// 	int		new_len;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	//printf("strlen: %ld, count_chr: %d\n", ft_strlen(str), count_chr(str, c));
// 	new_len = ft_strlen(str) - count_chr(str, c);
// 	//printf("newlen %d\n", new_len);
// 	new_str = ft_calloc(new_len + 1, sizeof(char));
// 	while (str[i])
// 	{
// 		if (str[i] == c)
// 			i++;
// 		else
// 			new_str[j++] = str[i++];
// 	}
// 	//eprintf("newstr %s\n", new_str);
// 	return (new_str);
// }

// char	**remove_quote_guard(char **argv)
// {
// 	char	*new_s;
// 	int		i;
	
// 	i = 0;
// 	while (argv[i])
// 	{
// 		argv[i]	= ft_strtrim(argv[i], QUOTE_GUARD);
// 		i++;
// 	}
// 	return (argv);
// }

t_list  *expand(t_shell *ctx, t_list *args)
{
	t_list *arg;

	arg = args;
	while (arg)
	{
		((t_head *)arg->content)->first = (t_node *) expand_string(ctx,
			(t_list *)((t_head *)arg->content)->first, QUOTE_SINGLE); // this is going to leak. needs to free old list before assigning new one.
		// ((t_head *)arg->content)->first = (t_node *) 
		// 	add_quote_guard((t_list *)((t_head *)arg->content)->first);
		arg = arg->next;
	}
	return (args);
}

// Expansão:
// 1. Recebe argv em lista
// 2. Percorre cada item da lista de argv
// 3. Expandir string (list t_word)
	// 3.1 Percorrer lista de t_word
	// 3.2 Verificar se precisa expandir (tem $) e quote_state != single
	// 3.3 Após $, percorre string até encontrar caractere não válido em key
	// 3.4 Guarda valor de $ até não válido, procura em env, e expande
// 
// 3. Aspas simples = Não expande e não splita
// 4. Aspas duplas = Expande e não splita
// 5. Sem aspas = Expande e splita


// CASO: export VAR="Hello World" && echo 1 "$VAR $USER"'$VAR'$VAR oi
// ARGV:
// t_word *: [{ value: 'echo', quote_state: NONE }]}
// t_word *: [{ value: '1', quote_state: NONE }]}
// t_word *: [{ value: '$VAR $USER', quote_state: DOUBLE }
			// { value: '$VAR', quote_state: SINGLE }
			// { value: '$VAR', quote_state: NONE }
			// { value: '$VAR', quote_state: DOUBLE }
			// { value: '$USER', quote_state: SINGLE }
			// { value: '$VAR', quote_state: NONE }
// t_word *: [{ value: 'oi', quote_state: NONE }]}
// Após expansão do ARGV:
// t_word *: [{ value: 'echo', quote_state: NONE }]}
// t_word *: [{ value: '1', quote_state: NONE }]}
// t_word *: [{ { value: 'Hello World', quote_state: NONE }]} <= SPLITA AQUI
			// value: 'Hello World bmoreira', quote_state: DOUBLE }, 
			// { value: '$VAR', quote_state: SINGLE }, 
			// { value: 'Hello World', quote_state: NONE }]} <= SPLITA AQUI
			// { value: 'Hello World', quote_state: DOUBLE }
			// { value: 'Hello World', quote_state: NONE }]} <= SPLITA AQUI
			// { value: '$USER', quote_state: SINGLE }
			// { value: 'Hello World', quote_state: NONE } <= SPLITA AQUI
			// { value: 'Hello World Hello Hello', quote_state: NONE } <= SPLITA AQUI
			// { value: '$USER', quote_state: SINGLE }
			// { value: 'Hello', quote_state: NONE }]} <= SPLITA AQUI


			// t_word *: [{ { value: 'Hello, WorldHello World bmoreira$VARHello, WorldHello WorldHello, World$USERHello, WorldHello, World, Hello, Hello$USERHello
// while (words)
	// if (quote_state != NONE && !has_content)
	//  i++;
	//  has_content = true;
	// else => quote_state == NONE
	// if (has_content)
	//  i+ = (count_words(value) - 1)
	//  has_content = false;
	// else
	//  i+ = count_words(value)
	// word = word->next;
// char **argv;
// malloc = (i+1) + 1
// while (words)
	// if (quote_state != NONE)
		// argv[i] = join(argv[i], value);
	// if (quote_state == NONE)
		// splitado = split(value)
		// argv[i] = join(argv[i], splitado[0]);
		// while (splitado)
			// i++;
			// argv[i] = splitado[i]
	// 
// t_word *: [{ value: 'oi', quote_state: NONE }]}

// export VAR="Hello World" && echo 1 "$VAR $USER"'$VAR'$VAR"$VAR"'$USER'$VAR oi
// ARGV: [echo, 1, "Hello World bmoreira"'$VAR'Hello World"Hello World"'$USER'Hello World'$USER', oi]
// 

// #include <stdio.h>

// int main(int argc, char **argv)
// {
//     if (argc < 2)
//         return 1;

//     int i = -1;
//     while (argv[++i])
//         printf("ARGV[%d]: %s\n", i, argv[i]);
// }
// teste_argv.c
// cc teste_argv.c -o print_argv
// bash
// export a="1 2" && ./print_argv "$a"'$a'"$a"$a

// Testes
// export a="ech" && export b="o hello" && $a$b
// hello
// [echo hello]
// [echo][hello]
// export a="ech" && export b="o hello" && "$a$b"
// ["echo hello"]

// com argv[][]
// 1. Recebe argv
// 2. Percorre argv
// 3. Troca aspas por placeholder
// 4. Percorre argv novamente
// 5. Expande cada string
// 6. Percorre argv novamente
// 7. Junta argv numa única string
// 8. Split em espaços não protegidos por placeholder
// 9. Remove placeholders