/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 11:19:58 by mvenanci          #+#    #+#             */
/*   Updated: 2022/09/18 11:05:16 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_num(char c)
{
	if (c <= '4' && c >= '1')
		return (1);
	return (0);
}

int	is_space(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int	valid_input(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (is_num(str[i]) && str[i + 1] == '\0' && i == 30)
			return (1);
		else if (is_num(str[i]) && !is_space(str[i + 1]))
			return (0);
		else if (!is_num(str[i]) && !is_num(str[i + 1]))
			return (0);
	}
	return (1);
}

char	*rm_space(char *str)
{
	char	*only_numbers;
	int		i;
	int		j;

	i = 0;
	while (str[i])
		i++;
	only_numbers = (char *)malloc(sizeof(char) * (i + 2));
	i = -1;
	j = -1;
	while (str[++i])
	{
		if (is_num(str[i]))
			only_numbers[++j] = str[i];
	}
	return (only_numbers);
}

char	**treat_input(char *str)
{
	char	**inputs;
	int		i;
	int		mult;

	mult = 0;
	i = -1;
	inputs = (char **)malloc(5 * sizeof(char *));
	while (++i < 4)
		inputs[i] = (char *)malloc(5 * sizeof(char));
	inputs[4] = 0;
	i = -1;
	while (str[++i])
	{
		inputs[mult / 4][mult % 4] = str[i];
		if ((mult + 1) / 4 != mult / 4)
			inputs[mult / 4][4] = 0;
		mult++;
	}
	return (inputs);
}
