/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_renderer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:15:52 by trubat-d          #+#    #+#             */
/*   Updated: 2022/10/31 03:24:41 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

void	img_pix_put(t_image *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void	put_rect(t_image *img, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < img->iter_cnt)
	{
		j = 0;
		while (j < img->iter_cnt)
		{
			if (x + i < (int)img->img_width && y + j < (int)img->img_height)
				img_pix_put(img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	render_bckg(t_image *img)
{
	int	x;
	int	y;
	int	color;
	int	current_iter;

	x = 0;
	current_iter = img->iter_cnt;
	while (x < img->img_width)
	{
		y = 0;
		while (y < img->img_height)
		{
			img->pos = (t_pos){x, y, 0x000000};
			color = fractal_color_cmpt(img, img->fractal_mode);
			color = get_color(color, img);
			put_rect(img, x, y, color);
			y += img->iter_cnt;
		}
		x += img->iter_cnt;
	}
}

int	render(void *raw)
{
	t_data	*data;

	data = (t_data *)raw;
	if (data->img.iter_cnt == 1)
		return (0);
	else if (data->img.iter_cnt > 1)
	{
		data->img.iter_cnt -= 1;
		data->img.iters += data->img.max_iter / data->img.iter_cnt;
	}
	render_bckg(&(data->img));
	mlx_put_image_to_window(data->mlxptr, data->winptr, \
	data->img.mlx_img, 0, 0);
	return (0);
}

int	init_img(t_data *data, char *num1, char *num2, char *frac)
{
	data->img.cmpwin.in_cmplx_h = 2;
	data->img.cmpwin.in_cmplx_w = 2;
	data->img.cmpwin.in_cmplx_h_min = -2;
	data->img.cmpwin.in_cmplx_w_min = -2;
	data->img.cmpwin.cmplx_h = 2;
	data->img.cmpwin.cmplx_w = 2;
	data->img.cmpwin.cmplx_h_min = -2;
	data->img.cmpwin.cmplx_w_min = -2;
	data->img.data_access = (void *)data;
	data->img.iter_cnt = 20;
	data->img.max_iter = 50;
	data->img.width_offset = 0;
	data->img.height_offset = 0;
	data->img.scale_factor = 1;
	data->img.fractal_mode = get_frac(frac);
	data->img.color_mode = 'B';
	data->img.power = 2;
	data->img.iters = 0;
	data->img.input_julia_rl = compute_arg(num1);
	data->img.input_julia_im = compute_arg(num2);
	data->img.mlx_img = \
	mlx_new_image(data->mlxptr, data->img.img_width, data->img.img_height);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, \
	&data->img.line_len, &data->img.endian);
	return (0);
}
