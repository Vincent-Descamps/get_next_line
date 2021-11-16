/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:46:30 by vdescamp          #+#    #+#             */
/*   Updated: 2021/11/16 16:07:41 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putstr(char *str)
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

int	main(void)
{
	int		fd;
	int		ret;
	int		i;
	char	buf[BUF_SIZE + 1];

	fd = open("fichier.txt", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("ERROR");
		return (1);
	}
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	ft_putstr("Buffer size : ");
	ft_putnbr(ret);
	ft_putchar('\n');
	ft_putstr("*****************\n");
	ft_putstr(buf);
	return (0);
}

/*
char	*get_next_line(int fd)
{
}
void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
*/
