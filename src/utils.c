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
*/
int get_index(int *arr, int size, int val)
{
    int i;

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

int get_pos(t_list *lst, int val)
{
    int i;

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