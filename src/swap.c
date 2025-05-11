/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:13:10 by epascual          #+#    #+#             */
/*   Updated: 2025/05/10 11:04:33 by epascual42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/psw.h"

//El cambio es inevitable
void	swap(t_list **x)
{
	void	*tmp;

	if ((ft_lstsize(*x) < 2) || (*x == NULL) || ((*x)->next == NULL))
		return ;
	tmp = (*x)->content;
	(*x)->content = (*x)->next->content;
	(*x)->next->content = tmp;
}

/*Alternativa:
 * t_list* tmp; 
 * tmp = *x; 
 * *x = (*x)->next; 
 * (*x)->next = tmp*/
void	sa(t_list **x)
{
	swap(x);
	ft_printf("sa\n");
}

void	sb(t_list **x)
{
	swap(x);
	ft_printf("sb\n");
}

void	ss(t_list **x, t_list **y)
{
	swap(x);
	swap(y);
	ft_printf("ss\n");
}
