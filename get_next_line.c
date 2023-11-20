/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krfranco <krfranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:02:37 by krfranco          #+#    #+#             */
/*   Updated: 2023/11/20 23:50:34 by krfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*txt_to_tmp(char *tmp, int fd)
{
	int		i;

	i = 0;
	while (1)
	{
		i = read(fd, tmp, BUFFER_SIZE);
		if (i <= 0)
			break ;
	}
	return (tmp);
}

char	*get_next_line(int fd)
{
	int			i;
	char		tmp[BUFFER_SIZE];
	static char	*keep;

	if !(tmp)
		return (NULL);
	while (tmp[i])
	{
		if (tmp[i] == '\n')
		i++;
	}
}

int main()
{
	int fd;
	char *str;

	fd = open("t1.txt", O_RDONLY);
	str = txt_to_tmp(fd);
	printf("%s", str);
	close(fd);
	return (0);
}
