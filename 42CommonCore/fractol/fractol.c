/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:14:34 by myiu              #+#    #+#             */
/*   Updated: 2024/12/16 13:56:04 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//close and free and exit
int	win_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit (EXIT_SUCCESS);
}

// Display usage message and exit
void	error_exit(char *message)
{
	write(2, message, ft_strlen(message));
	write(2, "Supposed Input:\n", 16);
	write(2, "./fractol mandelbrot\n", 21);
	write(2, "./fractol julia <real> <imag>\n", 30);
	write(2, "./fractol burning_ship\n", 23);
	exit (EXIT_FAILURE);
}

// Draw the fractal based on the input type
void	draw_fractal(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	if (data->fractal_type == 0)
		draw_mandelbrot(data);
	else if (data->fractal_type == 1)
		draw_julia(data);
	else if (data->fractal_type == 2)
		draw_burning_ship(data);
}

//check the input and confirm the set type
void	check_input(int argc, char **argv, t_data *data)
{
	if (argc < 2)
		error_exit("Error: Missing parameters.\n");
	if (ft_strncmp(argv[1], "mandelbrot", 11) == 0)
	{
		data->fractal_type = 0;
		if (argc != 2)
			error_exit("Error: Too many parameters.\n\n");
	}
	else if (ft_strncmp(argv[1], "julia", 6) == 0)
	{
		if (argc != 4)
			error_exit("Error: Julia set needs real and imaginary part.\n");
		data->fractal_type = 1;
		data->real = (ft_atod(argv[2]));
		data->imaginary = (ft_atod(argv[3]));
	}
	else if (ft_strncmp(argv[1], "burning_ship", 13) == 0)
	{
		data->fractal_type = 2;
		if (argc != 2)
			error_exit("Error: Too many parameters.\n");
	}
	else
		error_exit("Error: Invalid fractal type.\n");
}

/*
    Initializes t_data and mlx
    set initial visible complex plane bounds
    checks input, renders the initial fractal, and sets up event hooks
*/
int	main(int argc, char **argv)
{
	t_data	data;

	check_input(argc, argv, &data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Fract-ol");
	data.x_min = -2.0;
	data.x_max = 2.0;
	data.y_min = -1.5;
	data.y_max = 1.5;
	data.color_shift = 0;
	draw_fractal(&data);
	mlx_key_hook(data.win, handle_key, &data);
	mlx_mouse_hook(data.win, handle_mouse, &data);
	mlx_hook(data.win, 17, 0, win_close, &data);
	if (data.fractal_type == 1)
		mlx_loop_hook(data.mlx, update_julia, &data);
	mlx_loop(data.mlx);
	return (0);
}
