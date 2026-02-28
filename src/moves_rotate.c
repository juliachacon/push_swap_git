/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julia <julia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:40:23 by jchacon-          #+#    #+#             */
/*   Updated: 2026/02/28 15:12:36 by julia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void rotate(t_stack *stack)
{
    t_node *first;
    t_node *last;

    if (!stack || stack->size < 2)
        return;

    first = stack->top;           
    stack->top = first->next;    

    last = stack->top;
    while (last->next)
        last = last->next;

    last->next = first;
    first->next = NULL;
}

void ra(t_stack *a)
{
    if (!a || a->size < 2)
        return;
    rotate(a);
    write(1, "ra\n", 3);
}

void rb(t_stack *b)
{
    if (!b || b->size < 2)
        return;
    rotate(b);
    write(1, "rb\n", 3);
}

void rr(t_stack *a, t_stack *b)
{
    int did = 0;

    if (a && a->size >= 2)
    {
        rotate(a);
        did = 1;
    }
    if (b && b->size >= 2)
    {
        rotate(b);
        did = 1;
    }
    if (did)
        write(1, "rr\n", 3);
}
