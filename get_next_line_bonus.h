/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 01:28:55 by ohachami          #+#    #+#             */
/*   Updated: 2022/12/04 01:28:58 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include<fcntl.h>
# include<string.h>
# include<limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(const char *str);
int		ft_strchr(const char *str, int c);

#endif
