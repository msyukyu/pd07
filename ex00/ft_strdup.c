/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 18:46:45 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/20 19:14:55 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = -1;
	while (++i < n && src[i] != '\0')
		dest[i] = src[i];
	while (i++ < n)
		dest[i - 1] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	int		l;
	char	*dest;

	l = ft_strlen(src) + 1;
	dest = malloc(sizeof(char) * l);
	if (dest == NULL)
		return (dest);
	dest = ft_strncpy(dest, src, l);
	return (dest);
}
