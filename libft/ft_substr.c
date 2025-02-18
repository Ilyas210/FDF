/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imouhtad <imouhtad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:49:13 by imouhtad          #+#    #+#             */
/*   Updated: 2025/02/18 16:49:20 by imouhtad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	len_src;
	size_t	i;
	size_t	new_len;

	i = 0;
	new_len = len;
	len_src = 0;
	if (!s)
		return (NULL);
	len_src = ft_strlen(s);
	if ((size_t)start + len > len_src)
		new_len = len_src - (size_t)start;
	if ((size_t)start >= len_src)
		new_len = 0;
	str = (char *)malloc(new_len + 1);
	if (!str)
		return (NULL);
	while (new_len--)
	{
		str[i++] = s[start++];
	}
	str[i] = '\0';
	return (str);
}
