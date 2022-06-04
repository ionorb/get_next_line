/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:40:31 by yridgway          #+#    #+#             */
/*   Updated: 2022/06/03 17:08:19 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*buf;
	static char		*save;
	char			*line;
	int				i;

//	if (!save)
//		save = (char *)malloc(sizeof (char));
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof (char));
	if (!buf)
		return (NULL);
	i = BUFFER_SIZE;
	while (i == BUFFER_SIZE && !ft_hasnl(save))
	{
		i = read(fd, buf, BUFFER_SIZE);
		buf[i] = '\0';
//		printf("<buf:%s>", buf);
//		printf("<buf[%d]:%c>", i, buf[i]);
		save = ft_strjoin(save, buf);
//		printf("<save:%s>", save);
//		printf("{{buf:%s}}", buf);
	}
	write(1, "\nban\n", 5);
	line = ft_makeline(save);
	save = ft_cutcopy(line, save);
	return (line);
}
