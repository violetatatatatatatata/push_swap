/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:17:52 by avelandr          #+#    #+#             */
/*   Updated: 2025/05/12 20:39:33 by epascual42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/psw.h"
/*
   Devuelve 0 si encuentra duplicados, 1 si todo es válido
 */
int	is_valid(int *nums, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		i = 0;
		while (j < size)
		{
			j = i + 1;
			if (nums[i] == nums[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	free_stacks(t_stacks *s)
{
	t_list	*tmp;
	t_list	*next;

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

t_list	**lstnum(t_list *lst, int num)
{
	t_list	**ret;

	ret = NULL;
	while (lst)
	{
		if (*(int *)lst->content == num)
			ret = &lst;
		lst = lst->next;
	}
	return (ret);
}

void	ft_printlist(t_list *a)
{
	int	tmp;

	if (a == NULL)
		return ;
	while (a)
	{
		tmp = (*(long *)(a->content));
		ft_printf("stack num is: %i\n", tmp);
		a = a->next;
	}
}
