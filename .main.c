/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:39:58 by yridgway          #+#    #+#             */
/*   Updated: 2022/06/01 14:40:02 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int ac, char **av)
{
	int	fd;
	int	i;

	if (ac > 3)
		return (0);
	i = 0;
	fd = open(av[1], O_RDONLY);
	while (i < atoi(av[2]))
	{
		get_next_line(fd);
		i++;
	}
	close(fd);
	return (0);
}
