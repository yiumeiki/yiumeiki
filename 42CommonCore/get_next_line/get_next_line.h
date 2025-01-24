/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:13:03 by myiu              #+#    #+#             */
/*   Updated: 2024/12/06 14:27:54 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

size_t	ft_strlen(char *str, char c);
char	*get_next_line(int fd);
int		check_line_break(char *buff);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr_line(char *s, unsigned int start, size_t end);
char	*ft_substr_rest(char *s, unsigned int start, size_t end);
int		read_byte(char *buff, char **rest, int bytes_read, int fd);

#endif
