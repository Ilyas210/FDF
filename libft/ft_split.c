/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imouhtad <imouhtad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:30:56 by imouhtad          #+#    #+#             */
/*   Updated: 2025/02/18 16:49:08 by imouhtad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	contain(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	count_words(const char *str, char *c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		while (contain(c, str[i]) && str[i])
			i++;
		if (!contain(c, str[i]) && str[i])
			counter++;
		while (!contain(c, str[i]) && str[i])
			i++;
	}
	return (counter);
}

static int	check_str(char **strs, int index)
{
	int	k;

	if (!strs[index])
	{
		k = 0;
		while (k < index)
			free(strs[k++]);
		free(strs);
		return (0);
	}
	return (1);
}

static char	**sp_strs(char **strs, const char *s, char *c)
{
	size_t			i;
	size_t			j;
	size_t			count;

	i = 0;
	j = 0;
	while (s[i])
	{
		count = 0;
		while (contain(c, s[i]) && s[i])
			i++;
		while (!contain(c, s[i]) && s[i])
		{
			count++;
			(i)++;
		}
		if (count)
		{
			strs[j] = ft_substr(s, i - count, count);
			if (!check_str(strs, j++))
				return (NULL);
		}
	}
	strs[j] = NULL;
	return (strs);
}

char	**ft_split(char const *s, char *c)
{
	char	**strs;

	if (!s)
		return (NULL);
	strs = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!strs)
		return (NULL);
	strs = sp_strs(strs, s, c);
	return (strs);
}
