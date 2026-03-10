/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:42:32 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/09 23:20:09 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

long long	exit_atoll(char *ascii)
{
	long long	num;
	int			negative;

	num = 0;
	negative = 1;
	while (ft_isspace(*ascii))
		ascii++;
	if (*ascii == '-' || *ascii == '+')
		if (*ascii++ == '-')
			negative *= -1;
	while (*ascii)
	{
		if (!ft_isdigit(*ascii))
			return (INVALID_EXIT);
		if (num > LLONG_MAX / 10
			|| (negative == 1 && num == LLONG_MAX / 10 && *ascii > '7')
			|| (negative == -1 && num == LLONG_MAX / 10 && *ascii > '8'))
			return (INVALID_EXIT);
		num = (num * 10) + *ascii++ - '0';
	}
	return (num * negative);
}

int	builtin_exit(t_shell *shell, char **argv)
{
	long long	exit_code;

	printf("exit\n");
	if (!argv[1])
		exit(shell->exit_status);
	exit_code = exit_atoll(argv[1]);
	if (exit_code == INVALID_EXIT
		&& printf("exit: %s: numeric argument required\n", argv[1]))
		exit(INVALID_EXIT);
	if (ft_split_size(argv) > 2 && printf("exit: too many arguments\n"))
		return (FAILURE);
	if (exit_code < 0 || exit_code > 255)
		exit_code = exit_code % 256;
	exit(exit_code);
	return (SUCCESS);
}

// exit vazio => exit com status do último comando executado
// exit com letras => msg: numeric argument required, exit 255
// exit com valor > 9223372036854775807 ou valor < -9223372036854775808 => 
// msg: numeric argument required, exit 255
// exit > 1 arg => msg: too many arguments, não dá exit, retorna 1
// exit fora do range 0-255 => exit com valor % 256
// exit com valor no range 0-255 => 
// exit com valor passado transformado em numero (atol)