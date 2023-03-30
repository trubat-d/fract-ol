/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:45:05 by trubat-d          #+#    #+#             */
/*   Updated: 2022/10/31 16:10:21 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

t_cmplx	complex_add(t_cmplx num1, t_cmplx num2)
{
	t_cmplx	res;

	res.im = num1.im + num2.im;
	res.rl = num1.rl + num2.rl;
	return (res);
}

double	dabs(double num)
{
	if (num < 0)
		return (-num);
	return (num);
}

t_cmplx	complex_mult(t_cmplx num1)
{
	t_cmplx	res;

	res.rl = num1.rl * num1.rl - num1.im * num1.im;
	res.im = 2 * num1.rl * num1.im;
	return (res);
}

double	complex_norm(t_cmplx cmplx)
{
	return (cmplx.rl * cmplx.rl + cmplx.im * cmplx.im);
}

int	iterate_mandel(int iter, t_cmplx z, t_cmplx c, t_image *img)
{
	t_cmplx	res;
	t_cmplx	mult;
	int		i;

	i = 0;
	mult = z;
	while (i++ < img->power - 1)
		mult = complex_mult(mult);
	res = complex_add(mult, c);
	if (iter + 1 <= img->max_iter && \
	iter + 1 <= img->iters && complex_norm(res) <= 4)
		return (iterate_mandel(iter + 1, res, c, img));
	return (iter);
}
