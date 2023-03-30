/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 01:25:19 by trubat-d          #+#    #+#             */
/*   Updated: 2022/10/31 01:26:44 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

t_cmplx	translate(int x, int y, t_image *img)
{
	t_cmplx	res;

	res.rl = (img->cmpwin.cmplx_w - img->cmpwin.cmplx_w_min) \
	* (((2 * x) / img->img_width) - 1) + img->width_offset;
	res.im = (img->cmpwin.cmplx_h - img->cmpwin.cmplx_h_min) \
	* (((-2 * y) / img->img_height) + 1) + img->height_offset;
	return (res);
}

void	color_handler(int key, t_image *img)
{
	if (key == 13)
		img->color_mode = 'W';
	if (key == 11)
		img->color_mode = 'B';
	if (key == 2)
		img->color_mode = 'D';
	if (key == 5)
		img->color_mode = 'G';
	if (key == 45)
		img->color_mode = 'N';
	if (key == 13 || key == 11 || key == 2 || key == 5 || key == 45)
		img->iter_cnt = 20;
}
