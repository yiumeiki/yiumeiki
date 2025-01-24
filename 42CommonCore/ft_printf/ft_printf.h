/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:38:45 by myiu              #+#    #+#             */
/*   Updated: 2024/11/28 16:40:34 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>

void	ft_putchar_len(char character, int *length);
void	for_string(char *args, int *length);
void	for_int(int number, int *length);
void	for_hex(unsigned int x, int *length, char c);
void	for_unsigned_int(unsigned int u, int *length);
void	for_pointer(size_t pointer, int *length);
int		ft_printf(const char *string, ...);

#endif