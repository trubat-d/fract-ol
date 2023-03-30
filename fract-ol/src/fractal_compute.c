/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_compute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:03:25 by trubat-d          #+#    #+#             */
/*   Updated: 2022/10/31 16:20:08 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

int	fractal_color_cmpt(t_image *img, int mode)
{
	if (mode == 1)
		return (iterate_mandel(0, (t_cmplx){0.0, 0.0}, \
		translate(img->pos.x, \
		img->pos.y, img), img));
	else if (mode == 2)
		return (iterate_mandel(0, \
		translate(img->pos.x, img->pos.y \
		, img), (t_cmplx){0.285, 0.01}, img));
	else if (mode == 3)
		return (iterate_mandel(0, \
		translate(img->pos.x, img->pos.y \
		, img), (t_cmplx){img->input_julia_rl, img->input_julia_im}, img));
	else if (mode == 4)
		return (iterate_mandel(0, \
		translate(img->pos.x, img->pos.y \
		, img), (t_cmplx){0.2, 0.755}, img));
	else if (mode == 5)
		return (iterate_mandel(0, \
		translate(img->pos.x, img->pos.y \
		, img), (t_cmplx){0.11, 0.7}, img));
	return (0);
}

int	encode_rgb(uint8_t lum, uint8_t red, uint8_t green, uint8_t blue)
{
	return (lum << 24 | red << 16 | green << 8 | blue);
}

int	get_color(int iter, t_image *img)
{
	int	max_it;

	max_it = img->max_iter;
	if (img->max_iter > 255)
		max_it = 255;
	if (iter >= max_it)
		return (encode_rgb(1, 255, 255, 255));
	if (iter == 0)
		return (encode_rgb (1, 0, 0, 0));
	if (img->color_mode == 'B' || \
	(iter <= max_it / 4 && img->color_mode == 'N'))
		return (encode_rgb(1, 0, 0, (255 / max_it) * pow(iter, 2)));
	else if (img->color_mode == 'D' || \
	(iter <= max_it / 2 && img->color_mode == 'N'))
		return (encode_rgb(1, (255 / max_it) * pow(iter, 2), 0, 0));
	else if (img->color_mode == 'G' || \
	(iter <= (max_it / 4) * 3 && img->color_mode == 'N'))
		return (encode_rgb(1, 0, (255 / max_it) * pow(iter, 2), 0));
	else if (img->color_mode == 'W' || (img->color_mode == 'N'))
		return (encode_rgb(1, (255 / max_it) * pow(iter, 2), \
		(255 / max_it) * pow(iter, 2), (255 / max_it) * pow(iter, 2)));
	return (0);
}

int	fractal_reset(t_image *img)
{
	img->width_offset = 0;
	img->height_offset = 0;
	img->iter_cnt = 20;
	img->scale_factor = 1;
	img->cmpwin.cmplx_h = img->cmpwin.in_cmplx_h;
	img->cmpwin.cmplx_w = img->cmpwin.in_cmplx_w;
	img->cmpwin.cmplx_h_min = img->cmpwin.in_cmplx_h_min;
	img->cmpwin.cmplx_w_min = img->cmpwin.in_cmplx_w_min;
	img->max_iter = 50;
	img->iters = 0;
	img->scale_factor = 1;
	return (0);
}

int	fractal_handler(int key, t_image *img)
{
	if (key == 18)
		img->fractal_mode = 1;
	if (key == 19)
		img->fractal_mode = 2;
	if (key == 20)
		img->fractal_mode = 3;
	if (key == 21)
		img->fractal_mode = 4;
	if (key == 23)
		img->fractal_mode = 5;
	if ((key >= 18 && key <= 21) || key == 23)
	{
		fractal_reset(img);
		if (key != 21)
			img->power = 2;
		else
			img->power = 3;
	}
	return (0);
}
