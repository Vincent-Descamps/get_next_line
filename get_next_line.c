/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:46:30 by vdescamp          #+#    #+#             */
/*   Updated: 2021/11/22 15:58:35 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putchar(char c);
size_t	ft_strlen(const char *s);
void	ft_putstr(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

char	*get_next_line(int fd)
{
	int		ret;
	char	buf[BUF_SIZE + 1];
	char	*saved_fd;
	int		i;
	char	*line;

	i = 0;
	ret = read(fd, buf, BUF_SIZE);
	ret = '\0';
	saved_fd = buf;
	line = ft_strjoin(line, buf);
	printf("%s", line);
	return (0);
}

int	main(void)
{
	int	fd;

	fd = open("fichier.txt", O_RDONLY);
	get_next_line(fd);
	close(fd);
	return (0);
}

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

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;

	i = 0;
	srclen = 0;
	while (src[srclen] != '\0')
		srclen++;
	if (dstsize == 0)
		return (srclen);
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = 0;
	if (dstsize < dstlen + 1)
		return (dstsize + srclen);
	if (dstsize > dstlen + 1)
	{
		while (src[i] != '\0' && dstlen + 1 + i < dstsize)
		{
			dst[dstlen + i] = src[i];
			i++;
		}
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}
