/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:19:15 by avelandr          #+#    #+#             */
/*   Updated: 2025/06/08 17:15:20 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/psw.h"

/*
	- Determina la cantidad máxima de bits (max_bits) necesarios para
	representar el valor más grande en la lista (basado en el tamaño total de
	la lista si los números están indexados de 0 a size - 1). Luego, itera
	desde el bit menos significativo hasta el más significativo, llamando a
	process_bit_pass para ordenar los elementos basándose en el valor de cada
	bit.
	Usa:	- ft_lstsize(): Para obtener el tamaño inicial de la lista a.
			- process_bit_pass(): Para realizar una pasada de ordenamiento para
			  un bit específico.
 */
void	radix_sort(t_list **a, t_list **b)
{
	int	i;
	int	size;
	int	max_bits;

	size = ft_lstsize(*a);
	max_bits = 0;
	if ((size - 1) == 0)
		max_bits = 1;
	else
	{
		while (((size - 1) >> max_bits) != 0)
			max_bits++;
	}
	i = 0;
	while (i < max_bits)
	{
		process_bit_pass(a, b, i, size);
		i++;
	}
}

/*
	Convierte la lista en un array, luego ordena ese array, y finalmente
	itera sobre la lista original para encontrar la posición (índice) de cada
	número en el array ordenado, reemplazando el valor original del nodo con
	su índice. Es una función de pre-procesamiento para radix_sort. Al
	indexar la pila, se asegura que los números sean secuenciales (0 a N-1),
	lo que simplifica y optimiza el Radix Sort.
	
	Usa:	- ft_lstsize(): Para obtener el tamaño de la lista.
			- list2array(): Para convertir la lista en un array de enteros.
			- sort_array(): Para ordenar el array de enteros.
			- get_index(): Para encontrar el índice de un número en el
			  array ordenado.
*/
void	index_stack(t_list *a)
{
	int		*arr;
	int		size;
	t_list	*aux;
	int		*num;
	int		indice;

	size = ft_lstsize(a);
	arr = list2array(a, size);
	if (!arr)
		return ;
	sort_array(arr, size);
	aux = a;
	while (aux)
	{
		num = (int *) aux->content;
		indice = get_index(arr, size, *num);
		*num = indice;
		aux = aux->next;
	}
	free(arr);
}

/*
	Convierte una lista enlazada t_list en un array dinámico de enteros
	(int *). Asigna memoria para el array y luego recorre la lista,
	copiando el contenido entero de cada nodo al array.
*/
int	*list2array(t_list *a, int size)
{
	int	*arr;
	int	i;

	arr = ft_calloc(size, sizeof(int));
	if (!arr)
		return (NULL);
	i = 0;
	while (a)
	{
		arr[i++] = *(int *)(a->content);
		a = a->next;
	}
	return (arr);
}

void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	aux;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				aux = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = aux;
			}
			j++;
		}
		i++;
	}
}
