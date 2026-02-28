/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julia <julia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:40:03 by jchacon-          #+#    #+#             */
/*   Updated: 2026/02/27 17:39:16 by julia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void push(t_stack *dest, t_stack *src)
{
    t_node *node;

    if (!src || src->size == 0)
        return;

    node = src->top;           // coges el 1º de src
    src->top = node->next;     // src pierde ese nodo
    src->size--;

    node->next = dest->top;    // lo enganchas delante en dest
    dest->top = node;
    dest->size++;
}

void pa(t_stack *a, t_stack *b)
{
    if (!b || b->size == 0) return;
    push(a, b);
    write(1, "pa\n", 3);
}

void pb(t_stack *a, t_stack *b)
{
    if (!a || a->size == 0) return;
    push(b, a);
    write(1, "pb\n", 3);
}
