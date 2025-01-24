/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:54:11 by myiu              #+#    #+#             */
/*   Updated: 2024/12/13 18:08:11 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	Calculate how many iterations a point in
	the Burning Ship set takes to escape the condition x² + y² > 4
*/
static int	calculate_iterations(double x0, double y0)
{
	int		iter;
	double	x;
	double	y;
	double	x_temp;

	x = 0;
	y = 0;
	iter = 0;
	while (x * x + y * y <= 4 && iter < MAX_ITER)
	{
		x_temp = x * x - y * y + x0;
		if (2 * x * y < 0)
			y = -(2 * x * y) + y0;
		else
			y = (2 * x * y) + y0;
		if (x_temp < 0)
			x = -x_temp;
		else
			x = x_temp;
		iter++;
	}
	return (iter);
}

/*
	Draw the Burning Ship fractal
*/
void	draw_burning_ship(t_data *data)
{
	int		px;
	int		py;
	int		iter;
	double	x0;
	double	y0;

	py = -1;
	while (++py < HEIGHT)
	{
		px = -1;
		while (++px < WIDTH)
		{
			x0 = data->x_min + px * (data->x_max - data->x_min) / WIDTH;
			y0 = data->y_min + py * (data->y_max - data->y_min) / HEIGHT;
			iter = calculate_iterations(x0, y0);
			mlx_pixel_put(data->mlx, data->win, px, py,
				calculate_colour(iter, data));
		}
	}
}
