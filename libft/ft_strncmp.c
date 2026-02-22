/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchacon- <jchacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:30:57 by jchacon-          #+#    #+#             */
/*   Updated: 2025/05/14 21:55:33 by jchacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	int				res;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		res = s1[i] - s2[i];
		if (s1[i] != s2[i] && i < n)
		{
			return (res);
		}
		i++;
	}
	return (0);
}

/*int main (void)
{
    char    *s1;
    char    *s2;
    unsigned int    n;
    int j;
    int i;

    s1 = "aaaaaa";
    s2 = "azaaaz";
    n = 4;

    j = ft_strncmp(s1, s2, n);
    i = strncmp(s1, s2, n);

    printf("%d ft_strncmp", j);
    printf("%d strncmp", i);
    return(0);
}*/