/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:22:55 by avelandr          #+#    #+#             */
/*   Updated: 2025/05/14 18:28:30 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/psw.h"

// comprueba si efectivamente la lista está ordenada
int	checkorder(t_list *ord)
{
	if (!ord)
		return (1);
	while (ord->next)
	{
		if (*(int *)(ord->content) > *(int *)(ord->next->content))
			return (0);
		ord = ord->next;
	}
	return (1);
}

int	norep(char **argv, int argc)
{
	int	i;
	int	j;

	i = 0;	// empieza del 0 o 1????
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (!ft_strcmp(argv[i], argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

// Controla el input de numeros negativos y si es válido
int	checknum(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (j < (int)ft_strlen(argv[i]))
		{
			if (j == 0 && (argv[i][j] == '-' || argv[i][j] == '+'))
				j++;
			if (argv[i][j] && !ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
