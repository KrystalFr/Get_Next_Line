/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krfranco <krfranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:02:37 by krfranco          #+#    #+#             */
/*   Updated: 2023/11/20 02:39:14 by krfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_tmpsize(int fd)
{
	char	buf;
	size_t	count;

	while (read(fd, &buf, 1))
		count++;
	return (count);
}

char	*get_next_line(int fd)
{
	char	*tmp;

	
}
