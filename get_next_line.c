/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:40:31 by yridgway          #+#    #+#             */
/*   Updated: 2022/06/07 13:10:40 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE + 1];
	static char		*save;
	char			*line;
	int				i;

	i = BUFFER_SIZE;
	while (i == BUFFER_SIZE && !ft_hasnl(save))
	{
		i = read(fd, buf, BUFFER_SIZE);
		buf[i] = '\0';
		save = ft_strjoin(save, buf);
	}
	if (save[0] == 0)
		return (NULL);
	line = ft_makeline(save);
	save = ft_cutcopy(line, save);
	return (line);
}
