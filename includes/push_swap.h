/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchacon- <jchacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:40:31 by jchacon-          #+#    #+#             */
/*   Updated: 2025/11/08 21:13:21 by jchacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>


typedef struct s_node
{
    int             value;      // número del nodo
    struct s_node   *next;      // puntero al siguiente nodo
}   t_node;

//aqui uso t_node
typedef struct s_stack
{
    t_node  *top;   // primer nodo (cima de la pila)
    int      size;  // cuántos elementos hay
}   t_stack;



//movimientos obligatorios
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

// algoritmo principal
void    push_swap(t_stack *a, t_stack *b);

#endif