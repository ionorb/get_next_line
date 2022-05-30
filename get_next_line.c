/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:59:49 by yridgway          #+#    #+#             */
/*   Updated: 2022/05/30 18:34:12 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char*   buf[BUFFER_SIZE + 1];

    while (!ft_hasnull(line))
    read(fd, buf, BUFFER_SIZE);
