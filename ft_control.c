/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:44:37 by lnoaille          #+#    #+#             */
/*   Updated: 2020/07/22 16:39:24 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	keycode(int keycode, t_img *img)
{
	if (keycode == 119)
	{
		img->pos_x += (img->dirX) * 0.15;
		img->pos_y += (img->dirY) * 0.15;
	}
	else if (keycode == 115)
	{
		img->pos_x += (img->dirX) * -0.15;
		img->pos_y += (img->dirY) * -0.15;
	}
	else if (keycode == 100)
	{
		img->pos_x += (img->dirY) * -0.15;
		img->pos_y += (img->dirX) * 0.15;
	}
	else if (keycode == 97)
	{
		img->pos_x += (img->dirY) * 0.15;
		img->pos_y += (img->dirX) * -0.15;
	}
	else
		return (keycode2(keycode, img));
	ft_view(img, img->res_x);
	mlx_put_image_to_window(img->mlx_ptr, img->mlx_wd, img->img, 0, 0);
}

int	keycode2(int keycode, t_img *img)
{
	double olddir_x;
	double oldplane_x;
	double angle;

	angle = 0.075;
	olddir_x = img->dirX;
	oldplane_x = img->planeX;
	if (keycode == 65361)
	{
		img->dirX = (img->dirX * cos(-angle) - img->dirY * sin(-angle));
		img->dirY = olddir_x * sin(-angle) + img->dirY * cos(-angle);
		img->planeX = img->planeX * cos(-angle) - img->planeY * sin(-angle);
		img->planeY = img->planeY * cos(-angle) + oldplane_x * sin(-angle);
	}
	if (keycode == 65363)
	{
		img->dirX = (img->dirX * cos(angle) - img->dirY * sin(angle));
		img->dirY = olddir_x * sin(angle) + img->dirY * cos(angle);
		img->planeX = img->planeX * cos(angle) - img->planeY * sin(angle);
		img->planeY = img->planeY * cos(angle) + oldplane_x * sin(angle);
	}
	ft_view(img, img->res_x);
	mlx_put_image_to_window(img->mlx_ptr, img->mlx_wd, img->img, 0, 0);
}
