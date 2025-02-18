/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imouhtad <imouhtad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:58:10 by imouhtad          #+#    #+#             */
/*   Updated: 2024/11/15 00:28:08 by imouhtad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_number(char c)
{
	return (c <= '9' && c >= '0');
}

static int	handle_sp_case(const char *str, int start, int length)
{
	int	i;

	i = 0;
	while (*(str + start) == '0')
	{
		length--;
		start++;
	}
	if (length < 19)
		return (0);
	if (length > 19 || ft_memcmp(str + start, "9223372036854775807", 19) > 0)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	num;
	int	counter;
	int	signe;
	int	start;

	counter = 0;
	num = 0;
	signe = 1;
	while ((str[counter] <= 13 && str[counter] >= 9) || str[counter] == ' ')
		counter++;
	if (str[counter] == '-' || str[counter] == '+')
	{
		if (str[counter++] == '-')
			signe *= -1;
	}
	start = counter;
	while (is_number(str[counter]))
		num = num * 10 + (str[counter++] - '0');
	if (handle_sp_case(str, start, counter - start))
	{
		if (signe > 0)
			return (-1);
		return (0);
	}
	return (signe * num);
}
