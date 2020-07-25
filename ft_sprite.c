/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 22:29:03 by lnoaille          #+#    #+#             */
/*   Updated: 2020/07/24 16:02:03 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	ft_create_sprite(t_draw_sp *dsp, int pixel, t_img *img)
// {
// 	int h;
// 	int y;
// 	int i;
//
// 	ft_sp(img, h, pixel, &y);
// }
//
// int	ft_sp(t_img *img, int h, int x, int *y)
// {
// 	int		i;
// 	int	step;
// 	t_wall	*sp;
// 	int		pixx;
// 	int		**map;
// 	sp = img->skin->Sp;
//
// 	ft_calcul_for_sp(img->draw_sp, img);
// 	int sprite_screenx = (int)((img->res_x / 2) * (1 + img->draw_sp->transform_x/img->draw_sp->transform_y));
// 	int sprite_width = ft_abs((int)(img->res_y / img->draw_sp->transform_y));
// 	int sprite_height = ft_abs((int)(img->res_y  / img->draw_sp->transform_y));
// 	int draw_startX = -sprite_width / 2 + sprite_screenx;
// 	if (draw_startX < 0)
// 		draw_startX = 0;
// 	int draw_endX = sprite_width / 2 + sprite_screenx;
// 	int texX = ((x - (-sprite_width / 2 + sprite_screenx)) / sprite_width) ;
// 	int draw_startY = -sprite_height / 2 + img->res_y  / 2;
// 	if (draw_startY < 0)
// 		draw_startY = 0;
// 	int draw_endY = sprite_height / 2 + img->res_y  / 2;
// 	if (draw_endY >= img->res_y)
// 		draw_endY = img->res_y - 1;
//
// 	// int draw
// 	// ft_putnbr_fd(texX, 1);
// 	map = sp->color_tab;
// 	*y = draw_startY;
// 	// ft_putnbr_fd(texX, 1);
// 	// printf("%f|", img->draw_sp->transform_y);
// 	{
// 		while (*y < draw_endY && *y < img->res_y)
// 		{
// 			// ft_putnbr_fd(texX, 1);
// 			step = (int)((((*y * 256 - img->res_y * 128 + sprite_height * 128)) / sprite_height) / 256);
// 			if (map[texX][step] != 0)
// 				ft_mlx_pixel_put(img, x, *y, map[texX][step]);
// 			*y = *y + 1;
// 		}
// 	}
// }
//
// void ft_calcul_for_sp(t_draw_sp *dsp, t_img *img)
// {
// 	int i;
//
// 	i = img->nb_sprite - 1;
// 	dsp->sp_x[i] -= (img->pos_x - 0.5);
// 	dsp->sp_y[i] -= (img->pos_y - 0.5);
// 	dsp->inv_det = 1 / (img->planeX * img->dirY - img->dirX * img->planeY);
// 	dsp->transform_x = dsp->inv_det * (img->dirY * dsp->sp_x[i]
// 			- img->dirX * dsp->sp_y[i]);
// 	dsp->transform_y = dsp->inv_det * (-img->planeY * dsp->sp_x[i]
// 			+ img->planeX * dsp->sp_y[i]);
// 	dsp->sp_screenx = (int)((img->res_x / 2) * (1 + dsp->transform_x
// 			/ dsp->transform_y));
// 	dsp->sp_h = abs((int)(img->res_y / dsp->transform_y));
// }
