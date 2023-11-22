/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krfranco <krfranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:24:21 by krfranco          #+#    #+#             */
/*   Updated: 2023/11/22 17:24:22 by krfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int ac, char **av)
{
	int		fd;
	char	*gnl;
	int		i;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	gnl = get_next_line(fd);
	i = 0;
	while (gnl)
	{
		printf("%d - %s", i, gnl);
		free(gnl);
		i++;
		gnl = get_next_line(fd);
	}
	close(fd);
	return (0);
}

// int	main(int ac, char **av)
// {
// 	int		fd;
// 	char	*gnl;
// 	int		i;

// 	if (ac != 3)
// 		return (0);
// 	fd = open(av[1], O_RDONLY);
// 	gnl = get_next_line(fd);
// 	i = atoi(av[2]);
// 	while (i)
// 	{
// 		printf("%s", gnl);
// 		free(gnl);
// 		i--;
// 		gnl = get_next_line(fd);
// 	}
// 	free(gnl);
// 	close(fd);
// 	return (0);
// }
