/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchacon- <jchacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 19:29:31 by jchacon-          #+#    #+#             */
/*   Updated: 2025/05/14 19:07:09 by jchacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

/*int main(void)
{
    int c;
    c = 'A';
    if (isalpha(c))
    {
        printf("'%c' es una letra.\n", c);
    }
    else {
        printf("'%c' no es una letra.\n", c);
    }
    if (ft_isalpha(c))
    {
        printf("'%c' es una letra.\n", c);
    }
    else {
        printf("'%c' no es una letra.\n", c);
    }
    return(0);
}*/