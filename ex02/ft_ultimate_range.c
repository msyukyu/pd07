/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 08:55:26 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/21 10:19:40 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
		return (0);
	*range = malloc(sizeof(int) * ((long)max - (long)min));
	if (range == NULL)
		return (0);
	i = 0;
	while ((long)i < (long)max - (long)min)
	{
		(*range)[i] = (int)(i + (long)min);
		i++;
		if (i < 0)
			return (0);
	}
	return ((int)i);
}
