/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchacon- <jchacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:34:56 by jchacon-          #+#    #+#             */
/*   Updated: 2026/03/02 15:39:17 by jchacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_bits_needed(int max)
{
	int	bits;

	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

/* ---------- radix ---------- */
void	radix_sort(t_stack *a, t_stack *b)
{
	int	n;
	int	max_bits;
	int	i;
	int	j;
	int	top_val;

	n = a->size;
	max_bits = max_bits_needed(n - 1);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < n)
		{
			top_val = a->top->value;
			if (((top_val >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		while (b->size > 0)
			pa(a, b);
		i++;
	}
}
