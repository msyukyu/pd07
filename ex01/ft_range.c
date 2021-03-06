/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 19:17:00 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/21 09:01:24 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*array;
	long	i;

	if (min >= max)
		return (NULL);
	array = malloc(sizeof(int) * ((long)max - (long)min));
	if (array == NULL)
		return (array);
	i = 0;
	while (i < (long)max - (long)min)
	{
		array[i] = (int)(i + (long)min);
		i++;
	}
	return (array);
}
