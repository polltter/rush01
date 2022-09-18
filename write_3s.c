/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_3s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosvaldo <cosvaldo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:39:24 by cosvaldo          #+#    #+#             */
/*   Updated: 2022/09/18 20:39:24 by cosvaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	write_3s_top(char **output, char **input, int n);

int	write_3s_top(char **output, char **input, int n)
{
	int	in_column;

	in_column = -1;
	while (++in_column < n)
	{
		if (input[0][in_column] == '3' && input[1][in_column] == '2' \
		&& output[2][in_column] == '0')
			output[2][in_column] = '4';
		else if (input[0][in_column] == '2' && input[1][in_column] == '3' \
		&& output[2][in_column] == '0')
			output[1][in_column] = '4';
		else if (input[0][in_column] == '3' && input[1][in_column] == '2' \
		&& output[2][in_column] != '4')
			return (0);
		if (input[2][in_column] == '3' && input[3][in_column] == '2' \
		&& output[in_column][2] == '0')
			output[in_column][2] = '4';
		else if (input[2][in_column] == '2' && input[3][in_column] == '3' \
		&& output[2][in_column] == '0')
			output[1][in_column] = '4';
		else if (input[0][in_column] == '3' && input[1][in_column] == '2' \
		&& output[2][in_column] != '4')
			return (0);
	}
	return (1);
}
