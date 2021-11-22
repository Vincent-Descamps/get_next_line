/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:10:50 by vdescamp          #+#    #+#             */
/*   Updated: 2021/11/22 10:35:17 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int n)
{
	char		str;
	long int	nb;

	nb = n;
	if (n < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		str = nb % 10 + '0';
	}
	else
		str = nb + '0';
	write(1, &str, 1);
}

char	*get_next_line(int fd)
{
	int		ret;
	int		nb_lines;
	int		i;
	char	str[60];
	char	buf[BUF_SIZE + 1];

	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	i = 0;
	ft_putstr("Nombre de characteres : ");
	ft_putnbr(ret);
	ft_putchar('\n');
	ft_putstr("*****************\n");
	ft_putstr(buf);
	while (buf[i++] != EOF)
	{
		if (buf[i] == '\n')
		{
			nb_lines++;
		}
	}
	i = 0;
	while (buf[i] != '\n')
	{
		str[i] = buf[i];
		i++;
	}
	str[i] = '\0';
	printf("*****************\n");
	printf("nb de lignes : %d\n", nb_lines);
	printf("*****************\n");
	printf("%s", str);
	return (0);
}

int	main(void)
{
	int		fd;

	fd = open("fichier.txt", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("ERROR");
		return (1);
	}
	get_next_line(fd);
	close(fd);
	return (0);
}
