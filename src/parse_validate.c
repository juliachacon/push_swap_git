/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julia <julia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 17:17:53 by julia             #+#    #+#             */
/*   Updated: 2026/02/22 17:19:22 by julia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//1//
static int is_valid_int_token(const char *s)
{
    int i;

    if (!s || s[0] == '\0')
        return (0);
    i = 0;
    if (s[i] == '+' || s[i] == '-')
        i++;
    if (s[i] == '\0')          // avoid just "+" o "-" alone
        return (0);
    while (s[i])
    {
        if (!ft_isdigit((unsigned char)s[i]))
            return (0);
        i++;
    }
    return (1);
}

//2//
static int is_in_int_range(const char *s)
{    
    int start;
    int is_negative;
    int len;
    
    start = get_sign_start(s, &is_negative);
    len = (int)ft_strlen(s + start);
    if (len > 10)
        return (0);
    if (len < 10)
        return (1);
    return (cmp_int_limits(s, start, is_negative));
}

//3//
static int get_sign_start(const char *s, int *is_negative)
{
    int         start;
    start = 0;
    *is_negative = 0;
    if (s[0] == '-' || s[0] == '+')
    {
        if (s[0] == '-')
            *is_negative = 1;
        start = 1;
    }
    return (start);
}

//4//
static int cmp_int_limits(const char *s, int start, int is_negative)
{    
    const char  *max_int;
    const char  *min_int;
    
    max_int = "2147483647";
    min_int = "2147483648";
    
    if (is_negative)
    {
        if (ft_strncmp(s + start, min_int, 10) > 0)
            return (0);
    }
    else
    {
        if (ft_strncmp(s + start, max_int, 10) > 0)
            return (0);
    }
    return (1);
}
