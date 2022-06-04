/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:40:31 by yridgway          #+#    #+#             */
/*   Updated: 2022/06/04 12:28:24 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char			buf[BUFFER_SIZE + 1];
	static char		*save;
	char			*line;
	int				i;

//	if (!save)
//	{
//		save = (char *)malloc(sizeof (char));
//		save[0] = '\0';
//	}
//	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof (char));
//	if (!buf)
//		return (NULL);
//	if (!fd)
//		return (NULL);
	i = BUFFER_SIZE;
	while (i >= 0)
	{
		buf[i] = '\0';
		i--;
	}
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
	line = ft_makeline(save);
	save = ft_cutcopy(line, save);
//	if (ft_strlen(line) == 0)
//		return (NULL);
	return (line);
}
