/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 11:03:01 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/21 16:02:32 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_sizeof_array(char *str)
{
	int	l;
	int	i;
	int	check;

	l = 0;
	i = 0;
	check = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		{
			l++;
			if (!check)
				check++;
		}
		else if (check)
		{
			l++;
			check--;
		}
		i++;
	}
	return (l);
}

char	**ft_split_whitespaces(char *str)
{
	int	l;
	char **result;
	int	i_r;
	int	i_s;
	int	i_sub;

	result = malloc(sizeof(char*));
	*result = malloc(ft_sizeof_array(str));
	i_s = 0;
	l = 0;
	i_r = 0;
	while (str[i_s] != '\0')
	{
		if (str[i_s] != ' ' && str[i_s] != '\t' && str[i_s] != '\n')
			l++;
		else if (l > 0)
		{	
			i_sub = 0;
			i_s = i_s - l;
			while (i_sub < l)
			{
				(*result)[i_r][i_sub] = str[i_s];
				i_sub++;
				i_s++;
			}
			(*result)[i_r][i_sub] = '\0';
			i_r++;
			l = 0;
		}
		i_s++;
	}
	return (result);
}

int		main(int argc, char *argv[])
{
	char **result;
	int i;

	result = NULL;
	if (argc == 2)
	{
		result = ft_split_whitespaces(argv[1]);
		i = -1;
		while (++i < 4)
			printf("%s", (*result)[i]);
	}
	return (0);
}
