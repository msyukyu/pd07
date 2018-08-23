/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 10:00:34 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/23 12:10:41 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_count_elems(char *str)
{
	int	n;
	int	i;
	int	check;

	n = 0;
	i = 0;
	check = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && !check)
			check++;
		else if (check)
		{
			n++;
			check--;
		}
		i++;
	}
	if (check)
		n++;
	return (n);
}

void	ft_init_var(int var[3], int zero)
{
	var[0] = (zero) ? 0 : -1;
	var[1] = 0;
	var[2] = 0;
}

char	*ft_replace_by_space(char *str, char *charset)
{
	int		v[3];
	char	*output;

	ft_init_var(v, 1);
	while (str[v[0]++] != '\0')
		v[1]++;
	output = malloc(sizeof(char) * (v[1] + 1));
	output[v[1]] = '\0';
	ft_init_var(v, 0);
	while (str[++v[0]] != '\0')
	{
		output[v[0]] = str[v[0]];
		if (v[1] == 0 && str[v[0]] == charset[v[1]])
		{
			v[2] = v[0];
			while (str[v[0] + 1] != '\0' && str[++v[0]] == charset[v[1] + 1])
				v[1]++;
			if (charset[v[1] + 1] == '\0')
				while (++v[2] < v[0] + 1)
					output[v[2] - 1] = ' ';
			v[1] = 0;
			v[0]--;
		}
	}
	return (output);
}

char	**ft_sub_split(size_t l, char **result, int var[3], char *copy)
{
	while (1)
	{
		if (copy[var[1]] != ' ' && copy[var[1]] != '\t' &&
				copy[var[1]] != '\n' && copy[var[1]] != '\0')
			l += sizeof(char);
		else if (l > 0)
		{
			result[var[0]] = malloc(l + 1);
			var[2] = 0;
			var[1] = var[1] - l;
			while (var[2] < (int)(l / sizeof(char)))
				result[var[0]][var[2]++] = copy[var[1]++];
			result[var[0]++][var[2]] = '\0';
			l = 0;
		}
		if (copy[var[1]++] == '\0')
			break ;
	}
	result[var[0]] = NULL;
	return (result);
}

char	**ft_split(char *str, char *charset)
{
	size_t	l;
	char	**result;
	int		var[3];
	char	*copy;

	copy = ft_replace_by_space(str, charset);
	result = malloc(sizeof(char*) * (ft_count_elems(copy) + 1));
	ft_init_var(var, 1);
	l = 0;
	return (ft_sub_split(l, result, var, copy));
}
