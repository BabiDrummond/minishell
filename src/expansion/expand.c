/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbara.drummond <barbara.drummond@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 20:55:06 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/21 18:36:46 by barbara.dru      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

char	*get_key(char *word)
{
	char	*key;
	int		i;

	i = 0;
	while (word[i])
	{
		if (!ft_isalnum(word[i]) && word[i] != '_')
			break ;
		i++;
	}
	key = ft_substr(word, 0, i);
	return (key);
}

int	expand_variable(char **new_str, char *str, int i, t_list *vars)
{
	char	*key;

	key = get_key(str + i + 1);
	new_str = ft_strjoin_free(new_str, var_get(vars, key), TRUE, FALSE);
	i += ft_strlen(key) + 1;
	free(key);
	return (i);
}

t_word	*expand_string(t_word *words, t_list *vars)
{
	t_word	*word;
	char	*new_str;
	char	*str;
	int		i;

	word = words;
	while (word)
	{
		str = (char *) word->link.content;
		new_str = ft_strdup("");
		i = 0;
		while (str[i])
		{
			if (str[i] == '$' && word->quote_state != QUOTE_SINGLE)
				i+= expand_variable();
			else
				new_str = ft_strjoin_free(new_str, str[i++], TRUE, FALSE);
		}
		free(word->link.content);
		word->link.content = new_str;
		word = word->link.next;
	}
	return (EXIT_SUCCESS);
}

int expand()
{
	
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