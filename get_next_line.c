/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:40:31 by yridgway          #+#    #+#             */
/*   Updated: 2022/06/01 18:27:17 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*buf;
	static char		*save;
	char			*line;
	int				i;

	if (!save)
		save = (char *)malloc(sizeof (char));
	buf = malloc(BUFFER_SIZE * sizeof (char));
	i = BUFFER_SIZE;
	while (i == BUFFER_SIZE && !ft_hasnull(save))
	{
		i = read(fd, buf, BUFFER_SIZE);
		save = ft_strjoin(save, buf);
	}
	line = ft_makeline(save);
	save = ft_cutcopy(line, save);
	write(1, line, ft_strlen(line));
	return (line);
}
