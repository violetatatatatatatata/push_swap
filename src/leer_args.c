/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leer_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 01:25:34 by avelandr          #+#    #+#             */
/*   Updated: 2025/05/14 18:32:39 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/psw.h"

/*
 Reserva memoria para el array y parsea argv con atoi
*/
int *list_nums(char **argv, int count)
{
    int *nums;
    int i;

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

void    liberar_array(char **array)
{
    int i;

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

void    free_stacks(t_stacks *s)
{
    t_list  *tmp;
    t_list  *next;

    tmp = s->a;
    while (tmp)
    {
        next = tmp->next;
        free(tmp->content);
        free(tmp);
        tmp = next;
    }
    tmp = s->b;
    while (tmp)
    {
        next = tmp->next;
        free(tmp->content);
        free(tmp);
        tmp = next;
    }
    s->a = NULL;
    s->b = NULL;
}
