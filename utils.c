/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imouhtad <imouhtad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:36:31 by imouhtad          #+#    #+#             */
/*   Updated: 2025/02/18 16:56:03 by imouhtad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	get_color(t_point p1, t_point p2, float t)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	a;

	r = (1 - t) * ((p1.color >> 24) & 0xFF) + t * (((p2.color >> 24) & 0xFF));
	g = (1 - t) * ((p1.color >> 16) & 0xFF) + t * ((p2.color >> 16) & 0xFF);
	b = (1 - t) * ((p1.color >> 8) & 0xFF) + t * ((p2.color >> 8) & 0xFF);
	a = (1 - t) * ((p1.color) & 0xFF) + t * ((p2.color) & 0xFF);
	return (r << 24 | g << 16 | b << 8 | a);
}

static int	is_valid_char(char c, int base)
{
	if (base <= 10)
		return (c >= '0' && c < ('0' + base));
	else
	{
		return ((c >= '0' && c <= '9') || (c >= 'A' && c < ('A' + base - 10))
			|| (c >= 'a' && c < ('a' + base - 10)));
	}
}

static int	char_to_value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'A' && c <= 'Z')
		return (10 + (c - 'A'));
	else if (c >= 'a' && c <= 'z')
		return (10 + (c - 'a'));
	return (0);
}

int	get_sign(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

int	ft_atoi_base(const char *str, int base)
{
	int	result;
	int	sign;
	int	i;
	int	digit;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '+' || str[i] == '-')
		sign = get_sign(str[i++]);
	if (base == 16 && str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X'))
		i += 2;
	else
		return (-1);
	while (str[i] && is_valid_char(str[i], base))
	{
		digit = char_to_value(str[i++]);
		if (result > (INT_MAX - digit) / base)
			return (-1);
		result = result * base + digit;
	}
	return (result * sign);
}
