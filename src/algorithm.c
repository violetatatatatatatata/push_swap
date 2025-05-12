/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:19:15 by avelandr          #+#    #+#             */
/*   Updated: 2025/05/12 19:58:21 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/psw.h"

/*
   - index_stack(stacks->a):  primero convertimos los valores a índices
   - radix_sort(&stacks->a, &stacks->b): luego aplicamos radix sort 
 */
void	radix_sort(t_list **a, t_list **b)
{
	int	max_bits;
	int	size;
	int	i;

	size = ft_lstsize(*a);
	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		radix_pass(a, b, i, size);
		while (*b)
			pa(a, b);
		i++;
	}
}

/*
Realiza una pasada de radix bit a bit sobre el stack 'a'
En esta pasada, mira el bit i-ésimo de cada número y lo manda a
'b' si es 0, o lo rota si es 1
*/
void	radix_pass(t_list **a, t_list **b, int i, int size)
{
	int		j;
	t_list	*node;

	j = 0;
	while (j < size)
	{
		node = *a;
		if (((*(int *)node->content >> i) & 1) == 0)
			pb(a, b);
		else
			ra(a);
		j++;
	}
}

/*
   - Obtener el tamaño del stack con ft_lstsize(a).
   - Copiar los valores a un array (list_to_array).
   - Ordenar ese array.
   - Recorrer la lista a:
   - Para cada nodo, buscar su valor original en el array ordenado.
   - Reemplazar el valor del nodo por el índice encontrado (get_index).
   - Liberar el array.
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

// Parsea a integers todos los elementos de la lista

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

// Ordena el array de indices que usa radix
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
