/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:59:49 by yridgway          #+#    #+#             */
/*   Updated: 2022/06/01 13:07:18 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char*           buf;
    static char*    save;
    char*           line;
    char*           returnline;
    int             i;
    int             j;

    printf("save:%s\n", save);
    if (!save)
        save = malloc(30 * sizeof (char));
    line = ft_strdup(save);
    buf = malloc(BUFFER_SIZE * sizeof (char));
    while (buf && !ft_hasnull(line))
    {
        read(fd, buf, BUFFER_SIZE);
        line = ft_strjoin(line, buf);
    }
    i = ft_strlen(line);
    while (line[i] != '\n')
        i--;
    j = i + 1;
    i++;
    while (line[i])
    {
        save[i - j] = line[i];    
        printf("save[%d]:%c\n", i - j, line[i]);
        i++;
    }
    printf("{{%d}}{{%d}}\n", j, i - j);
    line[j] = '\0';
    save[i - j] = '\0';
    returnline = ft_strdup(line);
    free(line);
    write(1, returnline, ft_strlen(returnline));
    return (returnline);
}
