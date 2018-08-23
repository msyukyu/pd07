/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 17:59:42 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/23 20:56:35 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strstr(char *str, char *to_find)
{
	int		i;

	if (to_find[0] == '\0')
		return (str);
	while (*str != '\0')
	{
		while (*str != *to_find && *str != '\0')
			str++;
		if (*str == *to_find)
		{
			i = 0;
			while (str[i] != '\0' || (str[i] == '\0' && to_find[i] == '\0'))
			{
				if (to_find[i] == '\0')
					return (str);
				if (to_find[i] == str[i])
					i++;
				else
					break ;
			}
			str++;
		}
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

int		ft_count_words(char *str, char *charset)
{
	int	n;
	int	i;
	int	j;
	int	check;

	n = 0;
	i = 0;
	check = 0;
	while (1)
	{
		j = 0;
		while (str[i + j] == charset[j] && charset[j] != '\0')
			j++;
		if (charset[j] == '\0' || (str[i] == '\0' && j == 0))
		{
			if (check && i > 0 && !(charset[j] == '\0' && str[i + j] == '\0'))
			{
				check = 0;
				n++;
			}
			if (str[i] != '\0')
				i = i + j - 1;
		}
		else
			check = 1;
		if (str[i] == '\0')
			break ;
		i++;
	}
	return (n);
}

char	**ft_split(char *str, char *charset)
{
	char	*dest;
	char	*trash;
	int		length;
	char	**result;
	int		i;
	int		count;

	count = ft_count_words(str, charset) + 1;
	result = malloc(sizeof(char*) * (count));
	i = 0;
	while (i < count)
	{
		dest = malloc(sizeof(char) * (1 + ft_strlen(str)));
		dest = ft_strncpy(dest, str, 1 + ft_strlen(str));
		trash = ft_strstr(dest, charset);
		length = trash - dest;
		if (length > 0)
		{
			(*result)[i] = malloc(length + 1);
			(*result)[i] = strncpy((*result)[i], dest, length);
			(*result)[i][length] = '\0';
			dest += length;
		}
		i++;
		dest++;
	}
	(*result)[i] = NULL;
	return (*result);
}
#include <stdio.h>
int		main(int argc, char *argv[])
{
	char **result;
	int i;

	if (argc == 3)
	{
		result = ft_split(argv[1], argv[2]);
		i = 0;
		while ((*result)[i] != NULL)
		{
			printf("%d", (*result)[i]);
			i++;
		}
	}
	return (0);
}
