/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:42:25 by myiu              #+#    #+#             */
/*   Updated: 2024/12/16 12:56:42 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	calculate the pixel color based on the number of iterations
*/
int	calculate_colour(int iter, t_data *data)
{
	if (iter == MAX_ITER)
		return (0);
	return ((iter * 10000000 / MAX_ITER) + data->color_shift);
}

/*
	Calculate how many iterations a point in 
	the Julia set takes to escape the condition x² + y² > 4
*/
static int	calculate_iterations(double x0, double y0)
{
	double	x;
	double	y;
	double	x_temp;
	int		iter;

	x = 0;
	y = 0;
	iter = 0;
	while (x * x + y * y <= 4 && iter < MAX_ITER)
	{
		x_temp = x * x - y * y + x0;
		y = 2 * x * y + y0;
		x = x_temp;
		iter++;
	}
	return (iter);
}

/*
	Iterates over all pixels, maps them to the complex plane
	and computes their color 
*/
void	draw_mandelbrot(t_data *data)
{
	int		px;
	int		py;
	double	x0;
	double	y0;
	int		color;

	py = -1;
	while (++py < HEIGHT)
	{
		px = -1;
		while (++px < WIDTH)
		{
			x0 = data->x_min + px * (data->x_max - data->x_min) / WIDTH;
			y0 = data->y_min + py * (data->y_max - data->y_min) / HEIGHT;
			color = calculate_colour(calculate_iterations(x0, y0), data);
			mlx_pixel_put(data->mlx, data->win, px, py, color);
		}
	}
}

/*
double x0 = x_min + px * (x_max - x_min) / WIDTH;
double y0 = y_min + py * (y_max - y_min) / HEIGHT;

zoom:
x_min = cx - (x_max - x_min) / zoom_factor / 2;
x_max = cx + (x_max - x_min) / zoom_factor / 2;
y_min = cy - (y_max - y_min) / zoom_factor / 2;
y_max = cy + (y_max - y_min) / zoom_factor / 2;

moving
Shift the x_min, x_max range for horizontal movement.
Shift the y_min, y_max range for vertical movement:
x_min += shift_amount;
x_max += shift_amount;
y_min += shift_amount;
y_max += shift_amount;
*/
