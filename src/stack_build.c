/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_build.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julia <julia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 17:20:02 by julia             #+#    #+#             */
/*   Updated: 2026/02/22 17:20:35 by julia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//1//
static int has_value(t_stack *a, int value)
{
    t_node *cur;

    cur = a->top;
    while (cur)
    {
        if (cur->value == value)
            return (1);
        cur = cur->next;
    }
    return (0);
}

//2//
static t_node *new_node(int value)
{
    t_node *n;

    n = (t_node *)malloc(sizeof(t_node));
    if (!n)
        return (NULL);
    n->value = value;
    n->next = NULL;
    return (n);
}

//3//
static void stack_add_back(t_stack *a, int value)
{
    t_node *n;
    t_node *cur;

    n = new_node(value);
    if (!n)
        error_exit();
    if (!a->top)
    {
        a->top = n;
        a->size = 1;
        return;
    }
    cur = a->top;
    while (cur->next)
        cur = cur->next;
    cur->next = n;
    a->size++;
}