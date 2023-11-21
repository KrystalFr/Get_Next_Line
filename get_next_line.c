/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krfranco <krfranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:02:37 by krfranco          #+#    #+#             */
/*   Updated: 2023/11/21 17:36:24 by krfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*cleanup(char *line, char *keep)
{
	int	i;
	int	j;
	int	end;

	j = 0;
	i = 0;
	while (line[i] != '\n')
		i++;
	end = i + 1;
	while (line[i++])
	{
		keep[j] = line[i];
		j++;
	}
	line[end] = '\0';
	keep[j] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	keep[BUFFER_SIZE + 1];

	line = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (keep[0] != 0)
	{
		line = ft_strdup(keep);
		ft_bzero(keep, BUFFER_SIZE + 1);
	}
	while (read(fd, keep, BUFFER_SIZE))
	{
		line = ft_strjoin(line, keep);
		if (ft_strchr(line, '\n'))
		{
			cleanup(line, keep);
			break ;
		}
	}
	return (line);
}

int main(int ac, char **av)
{
	int fd;
	int i = atoi(av[2]);

	if (ac != 3)
		return (0);
	fd = open(av[1], O_RDONLY);

	while (i)
	{	
		printf("%s", get_next_line(fd));
		i--;
	}
	close(fd);
	return (0);
}
