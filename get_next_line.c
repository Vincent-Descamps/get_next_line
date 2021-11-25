/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:46:30 by vdescamp          #+#    #+#             */
/*   Updated: 2021/11/25 13:49:47 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_check_line(char *line)
{
	int		i;
	char	*str;

	i = 0;
	while (line[i] != '\n')
		i++;
	str = malloc(sizeof (char) * i);
	if (!str)
		return (0);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		str[i] = line[i];
		i++;
	}
	printf(BOLDYELLOW"line length :"RESET" %d\n", i);
	return (str);
}

char	*ft_saved_fd(int fd, char *saved_fd)
{
	int		ret;
	char	*buf;
	char	*line;

	ret = 1;
	buf = malloc(sizeof(char) * (BUF_SIZE + 1));
	if (!buf)
		return (NULL);
	while (ret > 0 && !ft_strchr(saved_fd, '\n'))
	{
		/*if (buf != NULL)
			buf = ft_strdup("");*/
		ret = read(fd, buf, BUF_SIZE);
		buf[ret] = '\0';
		saved_fd = ft_strjoin(saved_fd, buf);
	}
	printf(BOLDYELLOW"saved output with buffer : "RESET"//%s//\n", saved_fd);
	printf(BOLDYELLOW"Left in Buffer : "RESET"@@ %s @@\n", buf);
	line = ft_check_line(saved_fd);
	printf(BOLDCYAN"--------------->line output : "RESET"##%s##\n", line);
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*saved_fd;

	saved_fd = "\0";
	saved_fd = ft_saved_fd(fd, saved_fd);
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

int	main(void)
{
	int	fd;
	int	fd1;

	fd = open("fichier.txt", O_RDONLY);
	fd1 = open("autre", O_RDONLY);
	printf("\n");
	printf(BOLDCYAN"BUFFER SIZE :"RESET" %i\n", BUF_SIZE);
	printf("\n");
	printf(BOLDRED"## call 1 : ##"RESET"\n");
	get_next_line(fd);
	printf("\n");
	printf(BOLDRED"## call 2 : ##"RESET"\n");
	get_next_line(fd);
	printf("\n");
	printf(BOLDRED"## call 3 : ##"RESET"\n");
	get_next_line(fd);
	printf("\n");
	/*get_next_line(fd);
	get_next_line(fd);*/
	printf(BOLDBLUE"****************\n");
	printf("*    test 2    *\n");
	printf("****************\n"RESET);
	printf("\n");
	printf(BOLDRED"## call 1 : ##"RESET"\n");
	get_next_line(fd1);
	printf("\n");
	printf(BOLDRED"## call 2 : ##"RESET"\n");
	get_next_line(fd1);
	printf("\n");
	printf(BOLDRED"## call 3 : ##"RESET"\n");
	get_next_line(fd1);
	close(fd);
	close(fd1);
	return (0);
}
