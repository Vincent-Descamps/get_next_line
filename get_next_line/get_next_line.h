/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:42:17 by vdescamp          #+#    #+#             */
/*   Updated: 2021/12/06 13:34:42 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*
# define BUFFER_SIZE 1
# define RESET		"\033[0m"
# define RED		"\033[31m"
# define YELLOW		"\033[33m"
# define WHITE		"\033[37m"
# define BOLDRED	"\033[1m\033[31m"
# define BOLDYELLOW	"\033[1m\033[33m"
# define BOLDBLUE	"\033[1m\033[34m"
# define BOLDMAGENTA	"\033[1m\033[35m"
# define BOLDCYAN	"\033[1m\033[36m"
# define BOLDWHITE	"\033[1m\033[37m"
*/

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_store(int fd, char *str);
char	*ft_format(char *saved_str);
char	*ft_next_str(char *saved_str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, const char *s2);
size_t	ft_strlen(const char *s);

#endif
