/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 20:41:18 by myiu              #+#    #+#             */
/*   Updated: 2024/07/04 21:58:41 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	should_capitalize_next_char;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (should_capitalize_next_char)
				str[i] -= 32;
			should_capitalize_next_char = 0;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if (!should_capitalize_next_char)
				str[i] += 32;
			should_capitalize_next_char = 0;
		}
		else if (!(str[i] >= '0' && str[i] <= '9'))
			should_capitalize_next_char = 1;
		else
			should_capitalize_next_char = 0;
		i++;
	}
	return (str);
}

int main(){
    char str[100];
    printf("enter a string: ");
    fgets(str, sizeof(str), stdin);
    ft_strcapitalize(str);
    printf("%s\n", str);
    return (0);
}
