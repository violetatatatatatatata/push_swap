/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leer_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 01:25:34 by avelandr          #+#    #+#             */
/*   Updated: 2025/05/11 13:59:47 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/psw.h"

/*
	Devuelve una lista con todos los argumentos separados por espacios.
	Se usará para leer los números del stack en forma de strings.
*/
char	**leer_argumentos(char const *str)
{
	if (!str)
		return (NULL);
	return ft_split(str, ' ');
}

/*
	Cuenta cuántos argumentos hay, separando por espacios.
*/
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

/*
	Convierte la lista de strings en enteros usando ft_atoi,
	validando que se pasan al menos N argumentos y preasignando memoria.
*/
int	*list_nums(char const *str)
{
	char	**aux;
	int		*nums;
	int		i, count;

	if (!str)
		return (NULL);

	count = contar_args(str);
	if (count < 1)
		return (NULL);
	nums = malloc(sizeof(int) * count);
	if (!nums)
		return (NULL);
	aux = leer_argumentos(str);
	if (!aux)
	{
		free(nums);
		return (NULL);
	}
	i = 0;
	while (i < count)
	{
		nums[i] = ft_atoi(aux[i]);
		i++;
	}
	liberar_array(aux);
	return (nums);
}

void	liberar_array(char **array)
{
	int	i;

	if (!array)
		return;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

/*
Inicializa una estructura t_stacks. Reserva memoria para dos stacks
(stack_a y stack_b)

En C, (void) no convierte un valor a puntero, simplemente indica que algo no devuelve nada.
El contenido de un nodo (void *content) necesita un puntero válido, no un valor directo.
*/
t_stacks	init_stacks(int *nums, int size)
{
	t_stacks	s;
	t_list		*a;
	t_list		*new_node;
	int			*value;
	int			i;

	s.a = NULL;
	s.b = NULL;
	a = NULL;
	i = 0;
	while (i < size)
	{
		new_node = malloc(sizeof(t_list));
		if (!new_node)
			return (s); // podrías liberar lo anterior si quieres más robustez
		value = malloc(sizeof(int));
		if (!value)
		{
			free(new_node);
			return (s); // igual aquí puedes liberar lo anterior
		}
		*value = nums[i];
		new_node->content = value;
		new_node->next = NULL;
		ft_lstadd_back(&a, new_node);
		i++;
	}
	s.a = a;
	s.b = NULL;
	return (s);
}
