/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:46:30 by vdescamp          #+#    #+#             */
/*   Updated: 2021/12/08 11:37:10 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next_str(char *saved_str)
{
	char	*next_str;
	int		i;
	int		j;

	i = 0;
	while (saved_str[i] && saved_str[i] != '\n')
		i++;
	if (!saved_str[i])
	{
		free(saved_str);
		return (NULL);
	}
	next_str = (char *)malloc(sizeof(char) * (ft_strlen(saved_str) - i + 1));
	if (!next_str)
		return (NULL);
	j = 0;
	i++;
	while (saved_str[i])
		next_str[j++] = saved_str[i++];
	next_str[j] = '\0';
	free(saved_str);
	return (next_str);
}

char	*ft_format(char *saved_str)
{
	char	*line;
	int		i;

	i = 0;
	if (*saved_str == '\0')
		return (NULL);
	while (saved_str[i] && saved_str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof (char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (saved_str[i] && saved_str[i] != '\n')
	{
		line[i] = saved_str[i];
		i++;
	}
	if (saved_str[i] == '\n')
	{
		line[i] = saved_str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_store(int fd, char *str)
{
	int		ret;
	char	*buff;

	ret = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (ret > 0 && !ft_strchr(str, '\n'))
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[ret] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*saved_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saved_str = ft_store(fd, saved_str);
	if (!saved_str)
		return (NULL);
	line = ft_format(saved_str);
	saved_str = ft_next_str(saved_str);
	return (line);
}
/*
int	main(void)
{
	int	fd;
	int	fd1;

	fd = open("fichier.txt", O_RDONLY);
	printf("\n");
	printf(BOLDCYAN"BUFFER SIZE :"RESET" %i\n", BUFFER_SIZE);
	printf("\n");
	printf(BOLDRED"## call 1 : ##"RESET"\n");
	printf("%s\n", get_next_line(fd));
	printf("\n");
	printf(BOLDRED"## call 2 : ##"RESET"\n");
	printf("%s\n", get_next_line(fd));
	printf("\n");
	printf(BOLDRED"## call 3 : ##"RESET"\n");
	printf("%s\n", get_next_line(fd));
	printf("\n");
	printf(BOLDRED"## call 4 : ##"RESET"\n");
	printf("%s\n", get_next_line(fd));
	printf("\n");
	close(fd);
	fd1 = open("autre", O_RDONLY);
	printf(BOLDBLUE"****************\n");
	printf("*    test 2    *\n");
	printf("****************\n"RESET);
	printf("\n");
	printf(BOLDRED"## call 1 : ##"RESET"\n");
	printf("%s\n", get_next_line(fd1));
	printf("\n");
	printf(BOLDRED"## call 2 : ##"RESET"\n");
	printf("%s\n", get_next_line(fd1));
	printf("\n");
	printf(BOLDRED"## call 3 : ##"RESET"\n");
	printf("%s\n", get_next_line(fd1));
	close(fd1);
	return (0);
}

int	main(void)
{
	int	fd;

	fd = open("fichier.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}
*/
