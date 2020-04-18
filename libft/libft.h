/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 19:47:29 by tlee              #+#    #+#             */
/*   Updated: 2020/03/09 03:57:19 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

void				*ft_memset(void *ptr, int value, size_t num);
int					ft_strcmp(const char *str1, const char *str2);
char				*ft_strcpy(char *dst, const char *src);
size_t				ft_strlen(const char *str);
int					ft_strncmp(const char *str1, const char *str2, size_t num);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strnew(size_t size);
char				*ft_strncpy(char *dst, const char *src, size_t num);
/*
** Additional Function
*/
int					ft_count_digit(unsigned long long int n);

#endif
