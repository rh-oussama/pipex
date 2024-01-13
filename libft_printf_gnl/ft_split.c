/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhaddao <orhaddao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:29:01 by orhaddao          #+#    #+#             */
/*   Updated: 2024/01/11 16:28:59 by orhaddao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	**free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static int	word_count(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static char	*ft_fill(char *w, char const *s, int i, int wl)
{
	int	j;

	j = 0;
	while (wl > 0)
	{
		w[j] = s[i - wl];
		j++;
		wl--;
	}
	w[j] = '\0';
	return (w);
}

static char	**ft_split_words(char const *s, char c, char **arr, int word_count)
{
	int	i;
	int	w;
	int	wl;

	i = 0;
	w = 0;
	wl = 0;
	while (w < word_count)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			wl++;
		}
		arr[w] = (char *) malloc(sizeof(char) *(wl + 1));
		if (!arr[w])
			return (free_split(arr));
		ft_fill(arr[w], s, i, wl);
		wl = 0;
		w++;
	}
	arr[w] = 0;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		wc;

	if (!s)
		return (0);
	wc = word_count(s, c);
	arr = (char **) malloc(sizeof(char *) * (wc + 1));
	if (!arr)
		return (0);
	arr = ft_split_words(s, c, arr, wc);
	return (arr);
}

// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     const char *s = "#############dfgdfgfdgg##########";
//     char d = '#';
//     char **result = ft_split(s, d);
//     if (result) 
// 	 {
//         int i = 0;
//         while (result[i]) 
// 		  {
//             printf("String %d: %s\n", i, result[i]);
//             i++;
//         }
//     }
//     return 0;
// }