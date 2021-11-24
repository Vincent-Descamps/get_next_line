/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:46:30 by vdescamp          #+#    #+#             */
/*   Updated: 2021/11/24 21:28:23 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_saved_fd(int fd, char *saved_fd)
{
	int		ret;
	char	*buf;

	ret = 1;
	buf = malloc(sizeof(char) * (BUF_SIZE + 1));
	if (!buf)
		return (NULL);
	while (ret > 0 && !ft_strchr(saved_fd, '\n'))
	{
		ret = read(fd, buf, BUF_SIZE);
		buf[ret] = '\0';
		saved_fd = ft_strjoin(saved_fd, buf);
	}
	free(buf);
	return (saved_fd);
}

char	*get_next_line(int fd)
{
	static char		*saved_fd;

	saved_fd = "";
	saved_fd = ft_saved_fd(fd, saved_fd);
	printf("%s", saved_fd);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int				len_s1;
	int				len_s2;
	char			*tab;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	tab = (char *)malloc(len_s1 + len_s2 + 1);
	if (!tab)
		return (0);
	ft_strlcpy(tab, s1, len_s1 + 1);
	ft_strlcat(tab, s2, len_s1 + len_s2 + 1);
	return (tab);
}
/*
int	main(void)
{
	int	fd;

	fd = open("fichier.txt", O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	close(fd);
	return (0);
}
*/
