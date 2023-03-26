/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:46:27 by ohachami          #+#    #+#             */
/*   Updated: 2022/11/04 19:46:48 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	check_rest(char *rest)
{
	int	i;

	i = 0;
	while (rest[i])
	{
		if (rest[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*detect_new_line(char *line, char *buff, int fd, int *k)
{
	int		len;
	ssize_t	i;

	i = 1;
	while (i > 0)
	{
		len = 0;
		if (buff != NULL)
			line = ft_strjoin(line, buff);
		while (line[len])
		{
			if (line[len] == '\n')
				break ;
			len++;
		}
		*k = len + 2;
		if (line[len] == '\n')
			break ;
		i = read(fd, buff, BUFFER_SIZE);
		if (i > 0)
			buff[i] = '\0';
		if (i < 0)
			break ;
	}
	return (line);
}

char	*get_rest_and_line(char *line, char *rest, int k)
{
	int		i;
	char	*result;

	i = 0;
	result = ft_calloc(k + 1, 1);
	while (line[i] != '\n' && line[i])
	{
		result[i] = line[i];
		i++;
	}
	result[i] = line[i];
	if (line[i])
		i++;
	k = 0;
	while (line[i])
	{
		rest[k] = line[i];
		i++;
		k++;
	}
	rest[k] = '\0';
	free (line);
	line = NULL;
	return (result);
}

char	*gnl(char *rest, char *buff, int fd)
{
	int		count;
	char	*line;

	count = 0;
	line = NULL;
	if (*rest)
		line = ft_strjoin(line, rest);
	line = detect_new_line(line, buff, fd, &count);
	if (buff != NULL)
		free(buff);
	return (get_rest_and_line(line, rest, count));
}

char	*get_next_line(int fd)
{
	ssize_t		i;
	char		*buff;
	static char	rest[BUFFER_SIZE + 1];
	int			check;

	check = check_rest(rest);
	i = 1;
	if (!check)
	{
		buff = ft_calloc(BUFFER_SIZE + 1, 1);
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
			ft_bzero(rest, BUFFER_SIZE);
	}
	else
		buff = NULL;
	if ((i <= 0 || fd < 0) && !(*rest))
	{
		free(buff);
		return (NULL);
	}
	return (gnl(rest, buff, fd));
}
