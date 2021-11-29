/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:46:30 by vdescamp          #+#    #+#             */
/*   Updated: 2021/11/29 20:02:26 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*line;
	static char		*saved_fd;

}

int	main(void)
{
	int	fd;

	fd = open("autre", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}
/*
int	main(void)
{
	int	fd;
	int	fd1;

	fd = open("fichier.txt", O_RDONLY);
	fd1 = open("autre", O_RDONLY);
	printf("\n");
	printf(BOLDCYAN"BUFFER SIZE :"RESET" %i\n", BUFFER_SIZE);
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
*/
