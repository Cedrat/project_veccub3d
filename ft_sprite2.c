/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 20:20:34 by lnoaille          #+#    #+#             */
/*   Updated: 2020/07/25 04:17:06 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_sprite(t_img *img, t_draw_sp *dsp)
{
	int i;

	i = 0;
	while (i < dsp->nb_sprite)
	{
		double sprite_x = dsp->sp_x[i] - img->pos_x;
		double sprite_y = dsp->sp_y[i] - img->pos_y;
		double inv_det = 1.0 / (img->planeX * img->dirY - img->dirX * img->planeY); // 1.0 / (planeX * dirY - dirX * planeY);
		double transform_x = inv_det * (img->dirY * sprite_x - img->dirX * sprite_y); // invDet * (dirY * spriteX - dirX * spriteY);
		double transform_y = inv_det * (-img->planeY * sprite_x + img->planeX * sprite_y); //  invDet * (-planeY * spriteX + planeX * spriteY);
		int sprite_screenx = (int)((img->res_x / 2) * (1 + transform_x/transform_y)); //int((w / 2) * (1 + transformX / transformY));

		int sprite_height = ft_abs((int)(img->res_y / transform_y));
		int draw_start_y = -sprite_height / 2 + img->res_y / 2;
		if (draw_start_y < 0)
			draw_start_y = 0;
		int draw_end_y = sprite_height / 2 + img->res_y / 2;
		if (draw_end_y >= img->res_y)
			draw_end_y = img->res_y;

		int sprite_width = ft_abs((int)(img->res_y / transform_y));
		int draw_start_x = -sprite_width / 2 + sprite_screenx;
		if (draw_start_x < 0)
			draw_start_x = 0;
		int draw_end_x = sprite_width / 2 + sprite_screenx;
		if (draw_end_x >= img->res_x)
			draw_end_x = img->res_x;
		int stripe = draw_start_x;

		t_wall *sp = img->skin->Sp;
		while (stripe < draw_end_x)
		{
			int texX = (int)((stripe - (-sprite_width / 2 + sprite_screenx)) * sp->width / sprite_width);
			if (transform_y > 0 && stripe > 0 && stripe < img->res_x && transform_y < img->z_buffer[stripe] && texX >= 0)
			{
				int y = draw_start_y;
				while (y < draw_end_y && y < img->res_y)
				{
					int d = y - img->res_y/2 + sprite_height/2;
					int texY = ((d * sp->height) / sprite_height);
					if (sp->color_tab[texX][texY] != 0)
						ft_mlx_pixel_put(img, stripe, y, sp->color_tab[texX][texY]);
					y++;
				}
			}
		stripe++;
		}
	i++;
	}
}
