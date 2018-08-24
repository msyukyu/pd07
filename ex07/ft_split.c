/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 17:59:42 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/24 13:37:43 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strstr(char *str, char *to_find)
{
	char	*start_find;

	if (to_find[0] == '\0')
		return (str);
	while (*str != '\0')
	{
		start_find = to_find;
		while (*str != *start_find && *start_find != '\0')
			start_find++;
		if (*str == *start_find && start_find != '\0')
			return (str);
		str++;
	}
	return ((void*)0);
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

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int		ft_count_words(char *str, char *charset, int n, int check)
{
	int	i;
	int	j;

	i = 0;
	while (1)
	{
		j = 0;
		while (str[i] != charset[j] && charset[j] != '\0')
			j++;
		if (charset[j] != '\0')
		{
			if (check)
			{
				check = 0;
				n++;
			}
		}
		else if (str[i] == '\0' && check)
			n++;
		if (charset[j] == '\0')
			check = 1;
		if (str[i++] == '\0')
			break ;
	}
	return (n);
}

char	**ft_split(char *str, char *charset)
{
	char	*trash;
	int		length;
	char	**result;
	int		i;
	int		count;

	count = ft_count_words(str, charset, 0, 0) + 1;
	result = malloc(sizeof(char*) * (count));
	i = 0;
	while (i < count - 1)
	{
		trash = ft_strstr(str, charset);
		length = (trash == (void*)0) ? ft_strlen(str) : trash - str;
		if (length > 0)
		{
			result[i] = malloc(sizeof(char) * (length + 1));
			result[i] = ft_strncpy(result[i], str, length);
			result[i][length] = '\0';
			i++;
		}
		str += length + 1;
	}
	result[i] = (void*)0;
	return (result);
}
