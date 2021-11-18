/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:46:30 by vdescamp          #+#    #+#             */
/*   Updated: 2021/11/18 23:32:59 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*ft_format sert a remplacer tous les \n par des \0
afin de delimiter chaque ligne.*/
char	*ft_format(const char *src, int len)
{
	char	*dst;
	char	*ptr;
	int		i;

	i = 0;
	dst = (char *)malloc(sizeof(char) * (len + 1));
	strcpy(dst, src);
	while (strchr(dst, '\n'))
	{
		ptr = strchr(dst, '\n');
		*ptr = '\0';
	}
	printf("%s", dst);
	free(dst);
}

char	*get_next_line(int fd)
{
	int			ret;
	char		buf[BUF_SIZE + 1];
	char		*line;
	char		*dst;

	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	ft_format(buf, ret);
	return (0);
}

int	main(void)
{
	int		fd;

	fd = open("fichier.txt", O_RDONLY);
	/*if (fd == -1)
	{
		ft_putstr("ERROR");
		return (1);
	}*/
	get_next_line(fd);
	close(fd);
	return (0);
}
