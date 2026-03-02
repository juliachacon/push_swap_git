/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchacon- <jchacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:40:28 by jchacon-          #+#    #+#             */
/*   Updated: 2026/03/02 15:19:23 by jchacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		parse_args(int argc, char **argv, t_stack *a);
int			is_sorted(t_stack *a);
void		free_stack(t_stack *s);

static void	init_stack(t_stack *s)
{
	s->top = NULL;
	s->size = 0;
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	init_stack(&a);
	init_stack(&b);
	parse_args(argc, argv, &a);
	if (!is_sorted(&a))
		push_swap(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
