/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:14:48 by myiu              #+#    #+#             */
/*   Updated: 2024/12/16 13:26:40 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//atoi but return in double
double	ft_atod(char *str)
{
	double	result;
	double	fraction;
	double	divisor;
	int		sign;

	if (!str)
		return (0.0);
	sign = handle_sign(&str);
	result = 0.0;
	divisor = 10.0;
	while (*str && *str >= '0' && *str <= '9')
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		fraction = handle_fraction(str, &divisor);
	}
	else
		fraction = 0.0;
	return (sign * (result + fraction));
}

//return the length
size_t	ft_strlen(char *str)
{
	int	strlen;
	int	i;

	i = 0;
	strlen = 0;
	while (str[i] != '\0')
	{
		strlen++;
		i++;
	}
	return (strlen);
}

//compare the char to see the type of fractal
int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

/*
	Handle keyboard input
	esc/left/right/up/down/ 99 = c
	Left decreases x_min.
	Right increases x_max.
	Up decreases y_min.
	Down increases y_max
*/
int	handle_key(int keycode, t_data *data)
{
	if (keycode == 65307)
		win_close(data);
	else if (keycode == 65361)
		data->x_min -= 0.1 * (data->x_max - data->x_min);
	else if (keycode == 65363)
		data->x_max += 0.1 * (data->x_max - data->x_min);
	else if (keycode == 65362)
		data->y_min -= 0.1 * (data->y_max - data->y_min);
	else if (keycode == 65364)
		data->y_max += 0.1 * (data->y_max - data->y_min);
	else if (keycode == 99)
	{
		data->color_shift += 1234567;
		data->color_shift = data->color_shift % 0xFFFFFF;
		draw_fractal(data);
	}
	draw_fractal(data);
	return (0);
}

/*
	Handle mouse input for zooming, button 4 = scroll up, 5 = down
	mouse_x and mouse_y values ensure the zoom is centered on the mouse position
	(the fractal is zoomed around the mouse pointer)
	zoom_factor > 1 = shrink(1.1 = 90.9% current size(10% zoom-in))
				< 1 = expand(0.9 = 111.1% current size(10% zoom-out))
*/
int	handle_mouse(int button, int x, int y, t_data *data)
{
	double	mouse_x;
	double	mouse_y;
	double	zoom_factor;

	mouse_x = data->x_min + x * (data->x_max - data->x_min) / WIDTH;
	mouse_y = data->y_min + y * (data->y_max - data->y_min) / HEIGHT;
	if (button == 4)
		zoom_factor = 1.1;
	else if (button == 5)
		zoom_factor = 0.9;
	else
		zoom_factor = 1.0;
	data->x_min = mouse_x - (mouse_x - data->x_min) / zoom_factor;
	data->x_max = mouse_x + (data->x_max - mouse_x) / zoom_factor;
	data->y_min = mouse_y - (mouse_y - data->y_min) / zoom_factor;
	data->y_max = mouse_y + (data->y_max - mouse_y) / zoom_factor;
	draw_fractal(data);
	return (0);
}
