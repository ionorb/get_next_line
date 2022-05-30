/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:03:17 by yridgway          #+#    #+#             */
/*   Updated: 2022/05/30 19:10:05 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	main(int ac, char **av)
{
	int	fd;
	int	i;

	if (ac > 2)
		return (0);
	i = 0;
	fd = open(av[1], O_RDONLY, O_CREAT);
	while (i < atoi(av[2]))
	{
		printf("[i]:\t%s\n", i, get_next_line(fd));
		i++;
	}
    close(fd);
	return (0);
}
