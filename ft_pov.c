/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pov.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 00:03:24 by lnoaille          #+#    #+#             */
/*   Updated: 2020/07/24 21:57:14 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_view(t_img *param, int res_x, t_draw_sp *dsp)
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
		param->perpdist = dtw;
		ft_create_wall(dtw, x, param);
		param->z_buffer[x] = dtw;
		x++;
	}
	ft_dist_to_p(param, dsp, param->pos_x, param->pos_y);
	draw_sprite(param, dsp);
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
	if (img->side == 'N')
		ft_wall_n(img, h, pixel, &y);
	else if (img->side == 'W')
		ft_wall_w(img, h, pixel, &y);
	else if (img->side == 'E')
		ft_wall_e(img, h, pixel, &y);
	else
		ft_wall_s(img, h, pixel, &y);
	while (y < img->res_y)
	{
		ft_mlx_pixel_put(img, pixel, y, img->skin->f);
		y++;
	}
}
