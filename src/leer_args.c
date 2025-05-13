/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leer_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 01:25:34 by avelandr          #+#    #+#             */
/*   Updated: 2025/05/13 17:48:20 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/psw.h"

/*
   Cuenta cuántos argumentos hay, separando por espacios.
 */
 // esta funcion puede no ser necesaria en bash
size_t	contar_args(char const *str)
{
	size_t	num_args;
	size_t	aux;

	num_args = 1;
	aux = 0;
	while (str[aux])
	{
		if (str[aux] == ' ')
			num_args++;
		aux++;
	}
	return (num_args);
}

// funcion auxiliar para list_nums, reserva memoria para el array y los pasa por atoi
int	*fill_nums(char **aux, int count)
{
	int	*nums;
	int	i;

	nums = malloc(sizeof(int) * count);
	if (!nums)
		return (NULL);
	i = 0;
	while (i < count)
	{
		nums[i] = ft_atoi(aux[i]);
		i++;
	}
	return (nums);
}

// Convierte el array de strings en un array de enteros (los pasa a lista)

int	*list_nums(char const *str/*, int *size*/)
{
	char	**aux;
	int		*nums;
	int		count;

	if (!str)
		return (NULL);
	count = contar_args(str);
	if (count < 1)
		return (NULL);
	aux = leer_argumentos(str);
	if (!aux)
		return (NULL);
	nums = fill_nums(aux, count);
	//*size = count;
	liberar_array(aux);
	return (nums);
}

/*
   Inicializa una estructura t_stacks. Reserva memoria para dos stacks
   (stack_a y stack_b)

   En C, (void) no convierte un valor a puntero, simplemente indica
   que algo no devuelve nada. El contenido de un nodo (void *content)
   necesita un puntero válido, no un valor directo.
 */

t_list	*new_stack_node(int n)
{
	t_list	*new_node;
	int		*value;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	value = malloc(sizeof(int));
	if (!value)
	{
		free(new_node);
		return (NULL);
	}
	*value = n;
	new_node->content = value;
	new_node->next = NULL;
	return (new_node);
}

t_stacks	init_stacks(int *nums, int size)
{
	t_stacks	s;
	t_list		*node;
	int			i;

	s.a = NULL;
	s.b = NULL;
	i = 0;
	while (i < size)
	{
		node = new_stack_node(nums[i]);
		if (!node)
			return (s);
		ft_lstadd_back(&s.a, node);
		i++;
	}
	return (s);
}
