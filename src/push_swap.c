/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julia <julia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:33:34 by julia             #+#    #+#             */
/*   Updated: 2026/03/02 12:22:29 by julia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ---------- helpers for compress (value -> index) ---------- */

static int	*stack_to_array(t_stack *a)
{
	int		*arr;
	t_node	*cur;
	int		i;

	arr = (int *)malloc(sizeof(int) * a->size);
	if (!arr)
		error_exit();
	cur = a->top;
	i = 0;
	while (cur)
	{
		arr[i++] = cur->value;
		cur = cur->next;
	}
	return (arr);
}

static void	sort_int_array(int *arr, int n)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	find_index(int *sorted, int n, int value)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

static void	compress_values(t_stack *a)
{
	int		*arr;
	int		n;
	t_node	*cur;
	int		idx;

	n = a->size;
	arr = stack_to_array(a);
	sort_int_array(arr, n);
	cur = a->top;
	while (cur)
	{
		idx = find_index(arr, n, cur->value);
		if (idx < 0)
		{
			free(arr);
			error_exit();
		}
		cur->value = idx;
		cur = cur->next;
	}
	free(arr);
}

static int	max_bits_needed(int max)
{
	int	bits;

	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

/* ---------- radix ---------- */

static void	radix_sort(t_stack *a, t_stack *b)
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

/* ---------- entry point ---------- */

void	push_swap(t_stack *a, t_stack *b)
{
	if (!a || a->size < 2)
		return;
	if (is_sorted(a))
		return;
	
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

