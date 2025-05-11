/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual42 <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 11:02:35 by epascual42        #+#    #+#             */
/*   Updated: 2025/05/11 13:29:21 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/psw.h"

/*
    - index_stack(stacks->a);                   // primero convertimos los valores a índices
    - radix_sort(&stacks->a, &stacks->b);       // luego aplicamos radix sort 
*/
void	radix_sort(t_list **a, t_list **b)
{
	int		max_bits;
	int		size;
	int		i, j;

	size = ft_lstsize(*a);
	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	for (i = 0; i < max_bits; i++)
	{
		for (j = 0; j < size; j++)
		{
			int num = *((int *)(*a)->content);
			if (((num >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
		}
		while (*b)
			pa(a, b);
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
void    index_stack(t_list *a)
{
    int		*arr;
    int		size;
    t_list	*aux;
	int		*num;
	int		indice;

    size = ft_lstsize(a);   // funcion del bonus
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

int	get_index(int *arr, int size, int val)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == val)
			return (i);
		i++;
	}
	return (-1);
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
