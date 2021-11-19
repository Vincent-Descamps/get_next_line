/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:46:30 by vdescamp          #+#    #+#             */
/*   Updated: 2021/11/19 12:59:56 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		ret;
	char	buf[BUF_SIZE + 1];
	int		i;
	char	*line;

	ret = read(fd, buf, BUF_SIZE);
	ret = '\0';
	i = 0;
	while (buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	printf("%s", line);
	return (0);
}

int	main(void)
{
	int	fd;

	fd = open("fichier.txt", O_RDONLY);
	//while (!EOF)
	get_next_line(fd);
	close(fd);
	return (0);
}
