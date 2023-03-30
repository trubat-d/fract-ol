/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:45:47 by trubat-d          #+#    #+#             */
/*   Updated: 2022/10/31 03:24:58 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_cmplx
{
	double	rl;
	double	im;
}			t_cmplx;

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}		t_rect;

typedef struct s_pos
{
	int	x;
	int	y;
	int	color;
}		t_pos;

typedef struct s_cmplx_win
{
	double	in_cmplx_w;
	double	in_cmplx_h;
	double	in_cmplx_w_min;
	double	in_cmplx_h_min;
	double	cmplx_w;
	double	cmplx_h;
	double	cmplx_w_min;
	double	cmplx_h_min;
}			t_cmplx_win;

typedef struct s_image
{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	t_cmplx_win	cmpwin;
	int			iter_cnt;
	int			max_iter;
	double		img_width;
	double		img_height;
	double		width_offset;
	double		height_offset;
	double		scale_factor;
	char		color_mode;
	int			fractal_mode;
	void		*data_access;
	t_pos		pos;
	int			iters;
	int			power;
	double		input_julia_rl;
	double		input_julia_im;
	int			strt_fractal_id;
}			t_image;

typedef struct s_data
{
	void	*mlxptr;
	void	*winptr;
	t_image	img;
}			t_data;

int		iterate_mandel(int iter, t_cmplx z, t_cmplx c, t_image *img);
t_cmplx	translate(int x, int y, t_image *img);
int		key_handler(int keycode, void *param);
int		fractal_color_cmpt(t_image *img, int mode);
int		get_color(int iter, t_image *img);
int		elders_scroll(int keycode, int x, int y, void *param);
int		render(void *raw);
int		init_img(t_data *data, char *num1, char *num2, char *frac);
int		fractal_handler(int key, t_image *img);
void	color_handler(int key, t_image *img);
char	**ft_split(const char *s, char c);
int		fractal_reset(t_image *img);
int		destroy_window(void *param);
void	color_handler(int key, t_image *img);
int		ft_atoi(const char *nptr);
char	**ft_split(const char *s, char c);
int		ft_strlen(const char *str);
double	compute_arg(char *param);
int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		get_frac(char *param);

#endif