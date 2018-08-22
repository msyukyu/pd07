/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 16:51:57 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/22 18:01:39 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_check_base(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] < ' ' || base[i] > '~')
			return (0);
		j = -1;
		while (++j < i)
			if (base[i] == base[j])
				return (0);
		i++;
	}
	return ((i < 2) ? 0 : i);
}

int		ft_check_sign(char *str, int *sign)
{
	int	var_i;

	var_i = 0;
	while (str[var_i] == ' ' || str[var_i] == '\t' || str[var_i] == '\n' ||
			str[var_i] == '\r' || str[var_i] == '\v' || str[var_i] == '\f')
		var_i++;
	if (str[var_i] == '+')
		var_i++;
	else if (str[var_i] == '-')
	{
		var_i++;
		*sign = -1;
	}
	return (var_i);
}

int		ft_atoi_base(char *str, char *base, int size)
{
	int		result;
	int		sign;
	int		var_i;
	int		base_value;
	int		i;

	result = 0;
	sign = 1;
	var_i = ft_check_sign(str, &sign);
	i = -1;
	base_value = -1;
	while (base[++i] != '\0' && base_value == -1)
		if (base[i - 1] == str[var_i])
			base_value = i;
	while (base_value != -1 && ++var_i > -1)
	{
		result = result * size + sign * (base_value);
		base_value = -1;
		i = -1;
		while (base[++i] != '\0' && base_value == -1)
			if (base[i - 1] == str[var_i])
				base_value = i;
	}
	return ((base_value == -1 && !(str[var_i] == '\0') && str[var_i] != '-' &&
				str[var_i] != '+') ? 0 : result);
}

void	ft_recursive_print_digit(int nbr, char *base, char **result, int index)
{
	int	sign;
	int	size;

	sign = 1;
	size = ft_check_base(base);
	if (nbr < 0)
		sign = -1;
	if (nbr < size && nbr > -size)
	{
		if (sign == -1)
			(*result)[0] = '-';
	}
	else
	{
		ft_recursive_print_digit(nbr / size, base, result, index - 1);
	}
	(*result)[index] = base[(nbr % size) * sign];
}

char	*ft_putnbr_base(char *nbr, char *base_from, char *base_to)
{
	int		size;
	char	**result;
	int		atoi;
	int		i;
	int		j;

	size = ft_check_base(base_from);
	if (size < 0)
		return ;
	atoi = ft_atoi_base(nbr, base_from, size);
	result = malloc(sizeof(char*));
	*result = malloc(sizeof(char) * 34);
	i = -1;
	while (++i < 34)
		result[i] = '\0';
	ft_recursive_print_digit(atoi, base_to, result, 32);
	i = 0;
	j = -1;
	while (++i < 34)
	{
		if ((*result)[i] == '\0' && j == -1)
			j = i;
		else if ((*result)[i] != '\0')
		{
			(*result)[j++] = (*result)[i];
			(*result)[i] = '\0';
		}
	}
	return (result);
}
