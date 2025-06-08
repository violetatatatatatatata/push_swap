/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:17:52 by avelandr          #+#    #+#             */
/*   Updated: 2025/06/08 17:20:17 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/psw.h"

/*
	Esta función toma una pila desordenada (a), la divide temporalmente en
	dos grupos (unos con el bit i en 0 y otros con el bit i en 1) y luego
	los recombina de vuelta en la pila a de una manera que los acerca al
	orden final. Este proceso se repite para cada bit, desde el menos
	significativo al más significativo.
	- Itera size veces. Para cada elemento en la pila a:
	- Si el i-ésimo bit del número es 0, lo mueve a la pila b (pb).
	- Si el i-ésimo bit es 1, lo rota en la pila a (ra).
	Después de procesar todos los elementos, mueve los elementos de la
	pila b de vuelta a la pila a (pa).
*/
void	process_bit_pass(t_list **a, t_list **b, int i, int size)
{
	int	j;
	int	inb;

	j = 0;
	inb = 0;
	while (j < size)
	{
		if (*a == NULL)
			break ;
		if (((*(int *)(*a)->content >> i) & 1) == 0)
		{
			pb(a, b);
			inb++;
		}
		else
			ra(a);
		j++;
	}
	j = 0;
	while (j++ < inb)
		pa(a, b);
}

/*
	Encuentra el valor mínimo en una lista enlazada.
	- Inicializa una variable ret con el valor entero máximo.
	- Recorre la lista
	     Si encuentra un valor menor que ret, actualiza ret.
	Devuelve ret al finalizar.
*/
int	minlst(t_list *lst)
{
	int	ret;

	ret = 2147483647;
	while (lst)
	{
		if (*(int *)lst->content < ret)
			ret = (*(int *)lst->content);
		lst = lst->next;
	}
	return (ret);
}

/*
	Imprime los elementos de una lista enlazada.
	- Recorre la lista desde el principio hasta el final,
	  imprimiendo el contenido de cada nodo.
*/
void	ft_printlist(t_list *a)
{
	int	tmp;

	if (a == NULL)
		return ;
	while (a)
	{
		tmp = (*(long *)(a->content));
		ft_printf("%d\n", tmp);
		a = a->next;
	}
}

/*
	Busca un valor en un array ordenado y devuelve su índice.
	- Itera sobre el array arr de tamaño size.
	     Si encuentra val, devuelve su índice.
	     Si no lo encuentra, devuelve -1.
*/
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

/*
   Permite saber si un numero esta mas cerca del principio o
   del final. Sirve para evaluar si es mas eficiente usar ra o rra
 */

int	get_pos(t_list *lst, int val)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (*(int *)(lst->content) == val)
			return (i);
		lst = lst->next;
		i++;
	}
	return (-1);
}
