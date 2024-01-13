/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhaddao <orhaddao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:14:08 by orhaddao          #+#    #+#             */
/*   Updated: 2024/01/13 15:32:34 by orhaddao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <sys/wait.h>
# include <errno.h>
# include <signal.h>
# include <sys/stat.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include "get_next_line.h"

char	**ft_split(char const *s, char c);
int		ft_putstr(char *s);
int		ft_putnbr(int nb);
int		ft_putchar(char c);
int		ft_puthex(unsigned int nb, char c);
int		print_hex(unsigned long n, size_t digits);
int		ft_putnbr_unsigned(unsigned int nb);
int		putptr(void *ptr);
int		data_type(char c, va_list args);
int		ft_printf(const char *str, ...);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char	*s1, const char *s2, size_t n);
int		ft_strcmp(char *str1, char *str2);

#endif
