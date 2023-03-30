/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:24:37 by trubat-d          #+#    #+#             */
/*   Updated: 2022/11/02 00:14:53 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 4)
		return (0 * write(1, "[ArgError]: 3 args needed: float julia real, \
		float julia imaginary, fractal Name (mandelbrot, \
		julia or quad_julia) \n", 24));
	data.mlxptr = mlx_init();
	if (!data.mlxptr)
		return (1);
	data.img.img_width = 600;
	data.img.img_height = 600;
	init_img(&data, av[1], av[2], av[3]);
	if (data.img.fractal_mode == 4)
		data.img.power = 3;
	data.winptr = mlx_new_window(data.mlxptr, data.img.img_width, \
	data.img.img_height, "8Bit Fractol");
	if (!data.winptr)
		return (0);
	mlx_hook(data.winptr, 17, 0, &destroy_window, &data);
	mlx_mouse_hook(data.winptr, &elders_scroll, &data.img);
	mlx_key_hook(data.winptr, &key_handler, &data.img);
	mlx_loop_hook(data.mlxptr, &render, &data);
	mlx_loop(data.mlxptr);
	return (0);
}

int	destroy_window(void *param)
{
	t_image	*img;

	img = (t_image *)param;
	exit(0);
	return (0);
}
