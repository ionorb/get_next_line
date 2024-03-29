/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:39:58 by yridgway          #+#    #+#             */
/*   Updated: 2022/06/07 15:28:04 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int ac, char **av)
{
	int	fd;
	int	i;
	char *line;
//	clock_t begin;
//	clock_t end = clock();

	if (ac != 3)
	{
		printf("%s", get_next_line(3));
		return (0);
	}
	i = 0;
	fd = open(av[1], O_RDONLY);
	while (i < atoi(av[2]))
	{
//		begin = clock();
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
//		end = clock();
//		printf("\nTIME:%f\n", (double)(end - begin) / CLOCKS_PER_SEC);
		i++;
	}
	close(fd);
	return (0);
}
