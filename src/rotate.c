/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:14:52 by epascual          #+#    #+#             */
/*   Updated: 2025/06/09 13:00:14 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/psw.h"

void	rotate(t_list **x)
{
	t_list	*uno;
	t_list	*ulti;

	if (x == NULL || *x == NULL || ft_lstsize(*x) < 2)
		return ;
	uno = *x;
	ulti = ft_lstlast(*x);
	if (ulti == NULL)
		return ;
	*x = uno->next;
	if (*x == NULL)
		return ;
	ulti->next = uno;
	uno->next = NULL;
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
