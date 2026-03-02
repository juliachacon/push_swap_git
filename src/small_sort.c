/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julia <julia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 11:32:16 by julia             #+#    #+#             */
/*   Updated: 2026/03/02 11:59:33 by julia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_of_three(t_stack *a)
{
	int x = a->top->value;
	int y = a->top->next->value;
	int z = a->top->next->next->value;

	if (x > y && x > z) return x;
	if (y > x && y > z) return y;
	return z;
}

void	sort_3(t_stack *a)
{
	int max;

	if (!a || a->size != 3)
		return;

	max = max_of_three(a);

	if (a->top->value == max)
		ra(a);
	else if (a->top->next->value == max)
		rra(a);

	if (a->top->value > a->top->next->value)
		sa(a);
}

static int	position_of_value(t_stack *a, int value)
{
	t_node	*cur;
	int		pos;

	cur = a->top;
	pos = 0;
	while (cur)
	{
		if (cur->value == value)
			return pos;
		pos++;
		cur = cur->next;
	}
	return -1;
}

static void	bring_value_to_top(t_stack *a, int value)
{
	int pos;

	pos = position_of_value(a, value);
	if (pos < 0)
		return;

	while (a->top->value != value)
	{
		if (pos <= a->size / 2)
			ra(a);
		else
			rra(a);
	}
}

void	sort_5(t_stack *a, t_stack *b)
{
	if (!a || a->size < 4 || a->size > 5)
		return;

	bring_value_to_top(a, 0);
	pb(a, b);
	bring_value_to_top(a, 1);
	pb(a, b);

	sort_3(a);

	pa(a, b);
	pa(a, b);

	if (a->top->value > a->top->next->value)
		sa(a);
}


