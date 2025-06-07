/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:17:52 by avelandr          #+#    #+#             */
/*   Updated: 2025/06/07 17:18:10 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/psw.h"

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
   Permite saber si un numero esta mas cerca del principio o del final. Sirve
   para evaluar si es mas eficiente usar ra o rra
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
