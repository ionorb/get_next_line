/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:40:31 by yridgway          #+#    #+#             */
/*   Updated: 2022/06/01 15:56:02 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*buf;
	static char		*save;
	char			*line;
	char			*returnline;
	int				i;
	int				j;

	if (!save)
		save = malloc(sizeof (char));
	line = ft_strdup(save);
	save[0] = '\0';
	buf = malloc(BUFFER_SIZE * sizeof (char));
	i = BUFFER_SIZE;
	while (i == BUFFER_SIZE && !ft_hasnull(line))
	{
		i = read(fd, buf, BUFFER_SIZE);
		line = ft_strjoin(line, buf);
	}
	i = ft_strlen(line);
	while (line[i] != '\n')
		i--;
	j = i + 1;
	while (line[i++])
		save = ft_jointhings(save, line[i]);
	line[j] = '\0';
	returnline = ft_strdup(line);
	free(line);
	write(1, returnline, ft_strlen(returnline));
	//write(1, line, ft_strlen(line));
	return (line);
}
