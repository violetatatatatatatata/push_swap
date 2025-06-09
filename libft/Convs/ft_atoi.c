/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 02:04:20 by epascual          #+#    #+#             */
/*   Updated: 2025/06/09 15:20:29 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

int	ft_atoi(const char *n)
{
	int	res;
	int	i;
	int	neg;

	neg = 1;
	res = 0;
	i = 0;
	while ((n[i] >= '\t' && n[i] <= '\r') || n[i] == ' ')
		i++;
	if (n[i] == '-')
		neg = -1;
	if (n[i] == '+' || n[i] == '-')
		i++;
	while (n[i] >= '0' && n[i] <= '9')
	{
		res = res * 10;
		res = res + n[i] - '0';
		i++;
	}
	return (neg * res);
}
