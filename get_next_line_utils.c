/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:51:28 by ohachami          #+#    #+#             */
/*   Updated: 2022/11/04 19:52:19 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"get_next_line.h"

int	ft_strchr(const char *str, int c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (1);
		i++;
	}
	if ('\0' == c)
		i = 1;
	if (i == 1)
		return (1);
	else
		return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*uni;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = ft_calloc(1, 1);
		*s1 = '\0';
	}
	i = -1;
	j = -1;
	uni = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	if (!uni)
	{
		free(s1);
		return (NULL);
	}
	while (s1[++i])
		uni[i] = s1[i];
	while (s2[++j])
		uni[i + j] = s2[j];
	free(s1);
	return (uni);
}

int	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)s = 0;
		s++;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if (!p)
		return (NULL);
	ft_bzero(p, count * size);
	return (p);
}
