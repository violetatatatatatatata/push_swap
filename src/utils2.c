/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:21:17 by avelandr          #+#    #+#             */
/*   Updated: 2025/05/13 16:20:56 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/psw.h"

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

char	**leer_argumentos(char const *str)
{
	char	**args;

	if (!str)
		return (NULL);
	args = ft_split(str, ' ');
	return (args);
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
