/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 10:25:49 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/21 11:01:25 by dabeloos         ###   ########.fr       */
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

char	*ft_strncat(char *dest, char *src, int nb)
{
	int		i;
	int		pinned;

	i = 0;
	while (dest[i] != '\0')
		i++;
	pinned = i;
	i = 0;
	while (src[i] != '\0' && i < nb)
	{
		dest[pinned + i] = src[i];
		i++;
	}
	dest[pinned + i] = '\0';
	return (dest);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		l;
	int		i;
	char	*concat;

	i = -1;
	l = 0;
	while (++i < argc)
		l += 1 + ft_strlen(argv[i]);
	concat = malloc(sizeof(char) * l);
	i = -1;
	while (++i < argc)
	{
		l = ft_strlen(argv[i]);
		concat = ft_strncat(concat, argv[i], l);
		if (i < argc - 1)
			concat = ft_strncat(concat, "\n", 1);
	}
	return (concat);
}
