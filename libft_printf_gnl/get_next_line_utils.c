/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhaddao <orhaddao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:47:50 by orhaddao          #+#    #+#             */
/*   Updated: 2024/01/13 15:33:15 by orhaddao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (-1);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	str = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = 0;
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char) c)
		return ((char *) &s[i]);
	return (NULL);
}

void	*ft_calloc(size_t n, size_t size)
{
	size_t	i;
	void	*ptr;

	if (size && SIZE_MAX / size <= n)
		return (NULL);
	ptr = malloc(size * n);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < (n * size))
		((unsigned char *)ptr)[i++] = 0;
	return (ptr);
}
