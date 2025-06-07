/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:15:32 by epascual          #+#    #+#             */
/*   Updated: 2025/05/28 20:21:33 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/psw.h"

//Y los ultimos seran los primeros
void	reverse_rotate(t_list **x)
{
	t_list	*tmp;
	t_list	*uno;
	t_list	*ulti;

	if (ft_lstsize(*x) < 2)
		return ;
	uno = ft_lstlast(*x);
	ulti = ft_lstalast(*x);
	tmp = *x;
	*x = uno;
	(*x)->next = tmp;
	ulti->next = NULL;
}

void	rra(t_list **x)
{
	reverse_rotate(x);
	ft_printf("rra\n");
}

void	rrb(t_list **x)
{
	reverse_rotate(x);
	ft_printf("rrb\n");
}

void	rrr(t_list **x, t_list **y)
{
	reverse_rotate(x);
	reverse_rotate(y);
	ft_printf("rrr\n");
}
