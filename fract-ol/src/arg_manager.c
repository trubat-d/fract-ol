/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:33:15 by trubat-d          #+#    #+#             */
/*   Updated: 2022/10/31 03:28:27 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

int	check_arg(char *param)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	if (param[0] == '\0')
		return (-3);
	while (param[i])
	{
		if (param[i] == '.')
			cnt++;
		else if ((param[i] > '9' || param[i] < '0') && param[i] != '-')
			return (-1);
		i++;
	}
	if (cnt != 1)
	{
		return (-2);
	}
	return (i);
}

void	free_tab(char **tab)
{
	free(tab[0]);
	free(tab[1]);
	free(tab);
}

int	get_frac(char *param)
{
	int	i;

	i = 0;
	while (param[i] == "mandelbrot"[i])
		if (i++ == 10)
			return (1);
	i = 0;
	while (param[i] == "julia"[i])
		if (i++ == 5)
			return (3);
	i = 0;
	while (param[i] == "quad_julia"[i])
		if (i++ == 10)
			return (4);
	return (1 + (0 * write(1, "Wrong fractal, started with Mandelbrot\n", 39)));
}

double	compute_arg(char *param)
{
	double	res;
	char	**tab;
	int		error;

	error = check_arg(param);
	res = 0;
	if (error < 0)
	{	
		if (error == -1 || error == -3)
			write(1, "ParamError: Not a Number\n", 25);
		if (error == -2)
			write(1, "ParamError: Not a float !\n", 26);
		exit(1);
	}
	tab = ft_split(param, '.');
	if (ft_strlen(tab[1]) == 0 || ft_strlen(tab[0]) == 0)
		exit(0 * write(1, "ParamError: Not a complete float\n", 34));
	res += ft_atoi(tab[1]) / pow(10, ft_strlen(tab[1]));
	res += ft_atoi(tab[0]);
	if (tab[0][0] == '-' && ft_atoi(tab[0]) == 0)
		res = -res;
	free_tab(tab);
	return (res);
}
