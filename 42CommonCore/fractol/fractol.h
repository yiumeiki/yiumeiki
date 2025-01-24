/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:14:39 by myiu              #+#    #+#             */
/*   Updated: 2024/12/16 12:25:35 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

// Window dimensions
# define WIDTH 800
# define HEIGHT 600

// Maximum iterations for fractals
# define MAX_ITER 1000

/*
	Structure to hold fractal data
	x = range of the fractal’s horizontal axis
	y = range of the fractal’s vertical axis
*/
typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			color_shift;
	int			fractal_type;
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	double		real;
	double		imaginary;
}		t_data;

// Function prototypes
int		win_close(t_data *data);
int		ft_strncmp(char *s1, char *s2, size_t n);
int		update_julia(t_data *data);
int		handle_key(int keycode, t_data *data);
int		handle_mouse(int button, int x, int y, t_data *data);
int		calculate_colour(int iter, t_data *data);
void	draw_fractal(t_data *data);
void	draw_mandelbrot(t_data *data);
void	draw_julia(t_data *data);
void	error_exit(char *message);
void	draw_burning_ship(t_data *data);
size_t	ft_strlen(char *str);
double	ft_atod(char *str);
double	handle_sign(char **str);
double	handle_fraction(char *str, double *divisor);

#endif