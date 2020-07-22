/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pov.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 00:03:24 by lnoaille          #+#    #+#             */
/*   Updated: 2020/07/22 16:00:46 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_view(t_img *param, int res_x)
{
	size_t x;
	double dtw;
	double camerax;

	x = 0;
	while (x < res_x)
	{
		camerax = (2 * (double)x / (double)res_x) - 1;
		param->raydir_x = param->dirX + param->planeX * camerax;
		param->raydir_y = param->dirY + param->planeY * camerax;
		dtw = ft_distance_to_wall(param, camerax);
		ft_create_wall(dtw, x, param);
		x++;
	}
}

void	ft_create_wall(double dist_wall, int pixel, t_img *img)
{
	int h;
	int y;
	int i;

	i = 0;
	h = (int)(img->res_y / (dist_wall));
	y = 0;
	while (y < (img->res_y / 2 - h / 2) && y < img->res_y)
	{
		ft_mlx_pixel_put(img, pixel, y, img->skin->c);
		y++;
	}
	while (i < h && y < img->res_y)
	{
		ft_mlx_pixel_put(img, pixel, y, 0xAA77AA);
		y++;
		i++;
	}
	while (y < img->res_y)
	{
		ft_mlx_pixel_put(img, pixel, y, img->skin->f);
		y++;
	}
}
