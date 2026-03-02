/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchacon- <jchacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:40:31 by jchacon-          #+#    #+#             */
/*   Updated: 2026/03/02 15:41:27 by jchacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

/* -------- structs -------- */
typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

/* -------- parse / utils -------- */
void				parse_args(int argc, char **argv, t_stack *a);
void				error_exit(void);

/* Validación */
int					is_valid_int_token(const char *s);
int					is_in_int_range(const char *s);

/* stack built / search */
int					has_value(t_stack *a, int value);
void				stack_add_back(t_stack *a, int value);
int					is_sorted(t_stack *a);
void				free_stack(t_stack *s);

/* free */
void				free_tokens(char **tokens);

/* -------- compress / radix -------- */
void				compress_values(t_stack *a);
void				radix_sort(t_stack *a, t_stack *b);

/* -------- moves -------- */
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);

/* -------- small sorts -------- */
void				sort_3(t_stack *a);
void				sort_5(t_stack *a, t_stack *b);

/* -------- main algorithm -------- */
void				push_swap(t_stack *a, t_stack *b);

#endif