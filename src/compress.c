/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchacon- <jchacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:26:32 by jchacon-          #+#    #+#             */
/*   Updated: 2026/03/02 15:39:05 by jchacon-         ###   ########.fr       */
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

void	compress_values(t_stack *a)
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
