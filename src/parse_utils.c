/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julia <julia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 17:21:27 by julia             #+#    #+#             */
/*   Updated: 2026/02/22 17:21:29 by julia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//1//
static void free_tokens(char **tokens)
{
    size_t i;

    if (!tokens)
        return;
    i = 0;
    while (tokens[i])
        free(tokens[i++]);
    free(tokens);
}

//2//
void error_exit(void)
{
    write(2, "Error\n", 6);
    exit(1);
}