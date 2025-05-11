/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:14:22 by epascual          #+#    #+#             */
/*   Updated: 2025/05/11 14:53:21 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/psw.h"

//Un regalito
void	push(t_list **x, t_list **y)
{
	t_list	*tmp;

	if (!x || !*x)
		return ;
	if (ft_lstsize(*y) < 1)
		return ;
	tmp = *x;
	*x = (*x)->next;
	tmp->next = *y;
	*y = tmp;
}

void	pa(t_list **x, t_list **y)
{
	push(x, y);
	ft_printf("pa\n");
}

void	pb(t_list **y, t_list **x)
{
	push(x, y);
	ft_printf("pb\n");
}
