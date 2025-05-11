/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:14:52 by epascual          #+#    #+#             */
/*   Updated: 2025/05/10 11:03:44 by epascual42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/psw.h"

//Los primeros seran los ultimos
void	rotate(t_list **x)
{
	t_list	*uno;
	t_list	*ulti;

	if (ft_lstsize(*x) < 2)
		return ;
	uno = *x;
	ulti = ft_lstlast(*x);
	*x = uno->next;
	ulti->next = uno;
}

void	ra(t_list **x)
{
	rotate(x);
	ft_printf("ra\n");
}

void	rb(t_list **x)
{
	rotate(x);
	ft_printf("rb\n");
}
