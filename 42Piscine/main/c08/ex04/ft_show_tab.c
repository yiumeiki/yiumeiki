/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:37:46 by myiu              #+#    #+#             */
/*   Updated: 2024/07/10 17:41:56 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void ft_putstr(char *str)
{
    while (*str)
    {
        write(1, str, 1);
        str++;
    }
}

void ft_putnbr(int n)
{
    char buffer[12];
    int i = 11;
    int is_negative = n < 0;

    buffer[i] = '\0';
    i--;
    if (n == 0)
    {
        buffer[i] = '0';
        i--;
    }
    else
    {
        if (is_negative)
            n = -n;
        while (n > 0)
        {
            buffer[i] = (n % 10) + '0';
            n /= 10;
            i--;
        }
        if (is_negative)
        {
            buffer[i] = '-';
            i--;
        }
    }
    write(1, &buffer[i + 1], 11 - i);
}

void ft_show_tab(struct s_stock_str *par)
{
    int i = 0;
    while (par[i].str != 0)
    {
        ft_putstr(par[i].str);
        write(1, "\n", 1);

        ft_putnbr(par[i].size);
        write(1, "\n", 1);

        ft_putstr(par[i].copy);
        write(1, "\n", 1);

        i++;
    }
}

int main(int argc, char **argv)
{
    t_stock_str *array = ft_strs_to_tab(argc - 1, argv + 1);

    if (!array)
    {
        ft_putstr("Memory allocation failed\n");
        return 1;
    }

    ft_show_tab(array);

    for (int i = 0; i < argc - 1; i++)
    {
        free(array[i].copy);
    }
    free(array);

    return 0;
}
