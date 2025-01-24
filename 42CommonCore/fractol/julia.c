/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:33:58 by myiu              #+#    #+#             */
/*   Updated: 2024/12/16 13:32:53 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	handle_fraction(char *str, double *divisor)
{
	double	fraction;

	fraction = 0.0;
	while (*str >= '0' && *str <= '9')
	{
		fraction += (*str - '0') / *divisor;
		*divisor *= 10.0;
		str++;
	}
	return (fraction);
}

double	handle_sign(char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-')
	{
		sign = -1;
		(*str)++;
	}
	return (sign);
}

int	update_julia(t_data *data)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(data->mlx, data->win, &x, &y);
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		data->real = data->x_min + (x * (data->x_max - data->x_min) / WIDTH);
		data->imaginary = data->y_min + (y * (data->y_max - data->y_min)
				/ HEIGHT);
		mlx_clear_window(data->mlx, data->win);
		draw_julia(data);
	}
	return (0);
}

/*
	Calculate how many iterations a point in 
	the Julia set takes to escape the condition x² + y² > 4
*/
static int	calculate_iterations(double x, double y, t_data *data)
{
	int		iter;
	double	x_temp;

	iter = 0;
	while (x * x + y * y <= 4 && iter < MAX_ITER)
	{
		x_temp = x * x - y * y + data->real;
		y = 2 * x * y + data->imaginary;
		x = x_temp;
		iter++;
	}
	return (iter);
}

/*
	Iterates over all pixels in the window
	Maps each pixel to a point in the complex plane
	and call other functions
*/
void	draw_julia(t_data *data)
{
	int		px;
	int		py;
	int		iter;
	double	x;
	double	y;

	py = -1;
	while (++py < HEIGHT)
	{
		px = -1;
		while (++px < WIDTH)
		{
			x = data->x_min + px * (data->x_max - data->x_min) / WIDTH;
			y = data->y_min + py * (data->y_max - data->y_min) / HEIGHT;
			iter = calculate_iterations(x, y, data);
			mlx_pixel_put(data->mlx, data->win, px, py,
				calculate_colour(iter, data));
		}
	}
}
