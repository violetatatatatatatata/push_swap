/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leer_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 01:25:34 by avelandr          #+#    #+#             */
/*   Updated: 2025/05/21 13:16:57 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/psw.h"

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

void	liberar_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_stacks(t_stacks *s)
{
	t_list	*t;
	t_list	*lst;

	t = s->a;
	lst = s->a;
	while (lst)
	{
		t = (lst)->next;
		free(lst->content);
		free(lst);
		(lst) = t;
	}
	s->a = NULL;
	t = s->b;
	lst = s->b;
	while (lst)
	{
		t = (lst)->next;
		free(lst->content);
		free(lst);
		(lst) = t;
	}
	s->b = NULL;
}

/*
 Reserva memoria para el array y parsea argv con atoi
*/
int	*list_nums(char **argv, int count)
{
	int	*nums;
	int	i;

	if (!argv || count < 1)
		return (NULL);
	nums = malloc(sizeof(int) * count);
	if (!nums)
		return (NULL);
	i = 0;
	while (i < count)
	{
		nums[i] = ft_atoi(argv[i]);
		i++;
	}
	return (nums);
}
