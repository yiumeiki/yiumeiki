/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:18:54 by myiu              #+#    #+#             */
/*   Updated: 2024/07/08 15:23:44 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while ((i * i) < nb)
		i++;
	if (nb / i == i)
		return (i);
	else
		return (0);
}
/*
int main(){
	int nb = 36;
	int result = ft_sqrt(nb);
	printf("%d\n", result);
}*/
