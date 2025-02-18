/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imouhtad <imouhtad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:17:09 by imouhtad          #+#    #+#             */
/*   Updated: 2025/02/18 16:49:38 by imouhtad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 11
# endif

size_t	ft_strlen(const char *s);
void	*ft_malloc(size_t size);
int		ft_atoi(const char *str);
char	*ft_strchr(const char *s, int c);
char	**ft_split(char const *s, char *c);
void	ft_bzero(void *s, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
