/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchacon- <jchacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 21:16:25 by julia             #+#    #+#             */
/*   Updated: 2025/05/15 22:45:47 by jchacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	buffer;
	size_t	i;
	void	*ptr;

	buffer = nmemb * size;
	ptr = malloc(buffer);
	i = 0;
	if (ptr == NULL)
	{
		return (NULL);
	}
	while (i < buffer)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

/* int	main(void)
{
	size_t	nmemb;
	size_t	size;
	size_t	i;
	int		correcto;
	int		*array;

	i = 0;
	correcto = 1; // hago un boleano
	nmemb = 3;
	size = 4;
	array = ft_calloc(nmemb, size);
	// int *arrayc = calloc(nmemb, size); //3 elementos de tipo int (4 bytes)
	if (array == NULL)
	{
		printf("Error al reservar memoria\n");
		return (1);
	}
	while (i < nmemb)
	// aqui es nmemb porque vamos a verificar ints en el array (no bytes)
	{
		if (array[i] != 0)
		{
			correcto = 0;
			break ;
		}
		i++;
	}
	if (correcto)
		printf("ft_calloc funciona correctamente: todo inicializado a 0\n");
	else
		printf("Error: los valores no están todos a 0\n");
	free(array); // quien llama a la funcion es quien libera la mem
	return (0);
} */