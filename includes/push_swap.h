/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julia <julia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:40:31 by jchacon-          #+#    #+#             */
/*   Updated: 2026/02/22 17:39:22 by julia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

/* -------- structs -------- */

typedef struct s_node
{
    int             value;      // número del nodo
    struct s_node   *next;      // puntero al siguiente nodo
}   t_node;

typedef struct s_stack
{
    t_node  *top;   // primer nodo (cima de la pila)
    int      size;  // cuántos elementos hay
}   t_stack;

/* -------- parse / utils -------- */
void    parse_args(int argc, char **argv, t_stack *a);
void    error_exit(void);

/* Validación */
int     is_valid_int_token(const char *s);
int     is_in_int_range(const char *s);

/* Construcción / búsqueda en stack */
int     has_value(t_stack *a, int value);
void    stack_add_back(t_stack *a, int value);

/* Liberación */
void    free_stack(t_stack *s);

/* Comprobación */
int     is_sorted(t_stack *a);

/* -------- movimientos obligatorios -------- */
void    sa(t_stack *a);
void    sb(t_stack *b);
void    ss(t_stack *a, t_stack *b);
void    pa(t_stack *a, t_stack *b);
void    pb(t_stack *b, t_stack *a);
void    ra(t_stack *a);
void    rb(t_stack *b);
void    rr(t_stack *a, t_stack *b);
void    rra(t_stack *a);
void    rrb(t_stack *b);
void    rrr(t_stack *a, t_stack *b);

/* -------- algoritmo principal -------- */
void    push_swap(t_stack *a, t_stack *b);

#endif