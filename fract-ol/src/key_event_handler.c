/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:49:55 by trubat-d          #+#    #+#             */
/*   Updated: 2022/10/31 16:24:47 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

static void	pos_handler(int keycode, t_image *img)
{
	if (keycode == 124)
		img->width_offset += (img->cmpwin.cmplx_w - \
		img->cmpwin.cmplx_w_min) * (0.5 / sqrt(img->scale_factor));
	if (keycode == 123)
		img->width_offset -= (img->cmpwin.cmplx_w - \
		img->cmpwin.cmplx_w_min) * (0.5 / sqrt(img->scale_factor));
	if (keycode == 125)
		img->height_offset -= (img->cmpwin.cmplx_w - \
		img->cmpwin.cmplx_w_min) * (0.5 / sqrt(img->scale_factor));
	if (keycode == 126)
		img->height_offset += (img->cmpwin.cmplx_w - \
		img->cmpwin.cmplx_w_min) * (0.5 / sqrt(img->scale_factor));
	if (keycode == 15)
		fractal_reset(img);
	if ((keycode >= 123 && keycode <= 126))
		img->iter_cnt = 20;
}

int	zoom_in(int x, int y, void *param)
{
	t_image	*img;

	img = (t_image *)param;
	if (x <= img->img_width / 2)
		img->cmpwin.cmplx_w -= (img->cmpwin.cmplx_w \
		- img->cmpwin.cmplx_w_min) * (0.5 / sqrt(img->scale_factor));
	else
		img->cmpwin.cmplx_w_min += (img->cmpwin.cmplx_w \
		- img->cmpwin.cmplx_w_min) * (0.5 / sqrt(img->scale_factor));
	if (y <= img->img_height / 2)
		img->cmpwin.cmplx_h_min += (img->cmpwin.cmplx_h - \
		img->cmpwin.cmplx_h_min) * (0.5 / sqrt(img->scale_factor));
	else
		img->cmpwin.cmplx_h -= (img->cmpwin.cmplx_h - \
		img->cmpwin.cmplx_h_min) * (0.5 / sqrt(img->scale_factor));
	img->scale_factor += 0.5;
	img->max_iter += 2;
	img->iter_cnt = 20;
	return (0);
}

void	factor_check(t_image *img, int x, int y)
{
	if (x <= img->img_width / 2)
		img->cmpwin.cmplx_w += (img->cmpwin.cmplx_w - \
		img->cmpwin.cmplx_w_min) * (0.5 / sqrt(img->scale_factor));
	else
		img->cmpwin.cmplx_w_min -= (img->cmpwin.cmplx_w - \
		img->cmpwin.cmplx_w_min) * (0.5 / sqrt(img->scale_factor));
	if (y <= img->img_height / 2)
		img->cmpwin.cmplx_h_min -= (img->cmpwin.cmplx_h - \
		img->cmpwin.cmplx_h_min) * (0.5 / sqrt(img->scale_factor));
	else
		img->cmpwin.cmplx_h += (img->cmpwin.cmplx_h - \
		img->cmpwin.cmplx_h_min) * (0.5 / sqrt(img->scale_factor));
}

int	elders_scroll(int keycode, int x, int y, void *param)
{
	t_image	*img;

	img = (t_image *)param;
	if (keycode == 5)
		zoom_in(x, y, param);
	if (keycode == 4)
	{
		factor_check(img, x, y);
		if (img->scale_factor > 0.5)
			img->scale_factor -= 0.5;
		if (img->max_iter > 50)
			img->max_iter -= 2;
		else
			img->max_iter = 50;
		img->iter_cnt = 20;
	}
	return (0);
}

int	key_handler(int keycode, void *param)
{
	t_image	*img;

	img = (t_image *)param;
	pos_handler(keycode, img);
	fractal_handler(keycode, img);
	color_handler(keycode, img);
	if (keycode == 53)
		destroy_window(param);
	return (0);
}
