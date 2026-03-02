/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchacon- <jchacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:22:11 by julia             #+#    #+#             */
/*   Updated: 2026/03/02 15:18:34 by jchacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	parse_error(char **tokens, int must_free)
{
	if (must_free == 1)
		free_tokens(tokens);
	error_exit();
}

static void	handle_token(t_stack *a, char **tokens, int must_free,
		const char *tok)
{
	int	v;

	if (!is_valid_int_token(tok))
		parse_error(tokens, must_free);
	if (!is_in_int_range(tok))
		parse_error(tokens, must_free);
	v = ft_atoi(tok);
	if (has_value(a, (int)v))
		parse_error(tokens, must_free);
	stack_add_back(a, (int)v);
}

static void	process_tokens(char **tokens, t_stack *a, int must_free)
{
	int	i;

	if (!tokens || !tokens[0])
		parse_error(tokens, must_free);
	i = 0;
	while (tokens[i])
	{
		handle_token(a, tokens, must_free, tokens[i]);
		i++;
	}
	if (must_free == 1)
		free_tokens(tokens);
}

void	parse_args(int argc, char **argv, t_stack *a)
{
	char	**tokens;

	if (argc == 2)
	{
		tokens = ft_split(argv[1], ' ');
		process_tokens(tokens, a, 1);
	}
	else
	{
		process_tokens(argv + 1, a, 0);
	}
}
