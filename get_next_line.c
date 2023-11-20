/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krfranco <krfranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:02:37 by krfranco          #+#    #+#             */
/*   Updated: 2023/11/21 00:07:09 by krfranco         ###   ########.fr       */
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
	char		*euh;
	static char	*keep;

	tmp = txt_to_tmp(tmp, fd);
	if !(tmp)
		return (NULL);
	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == '\n')
		{
			euh = ft_substr(euh, tmp, i);
			keep = ft_substr(keep, tmp[i], BUFFER_SIZE - i);
			break ;
		}
		i++;
	}
	return (euh);
}

int main()
{
	int fd;
	char *str;

	fd = open("t1.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	close(fd);
	return (0);
}
