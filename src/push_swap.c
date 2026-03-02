/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchacon- <jchacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:33:34 by julia             #+#    #+#             */
/*   Updated: 2026/03/02 15:36:15 by jchacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ---------- entry point ---------- */
void	push_swap(t_stack *a, t_stack *b)
{
	if (!a || a->size < 2)
		return ;
	if (is_sorted(a))
		return ;
	compress_values(a);
	if (a->size == 2)
	{
		if (a->top->value > a->top->next->value)
			sa(a);
	}
	else if (a->size == 3)
		sort_3(a);
	else if (a->size <= 5)
		sort_5(a, b);
	else
		radix_sort(a, b);
}
