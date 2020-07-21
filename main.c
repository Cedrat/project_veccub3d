/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 21:06:12 by lnoaille          #+#    #+#             */
/*   Updated: 2020/07/22 00:15:51 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main()
{
		t_img *img;
		char    *relative_path = "./test.xpm";

		img = ft_init_s_img();
		img->mlx_ptr = mlx_init();
		// if (!(ft_parsing("./parsing_test.cub", img)))
		// 	return (0);
		ft_parsing("./parsing_test.cub", img);
		// printf("%f,%f/", img->pos_x, img->pos_y);
		// printf("%f", ft_distance_to_wall(img, 0.00));
		img->img = mlx_new_image(img->mlx_ptr, img->res_x, img->res_y);
		img->mlx_wd = mlx_new_window(img->mlx_ptr, img->res_x , img->res_y, "raspusprite");
		img->img_addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
		ft_view(img, img->res_x);
		mlx_put_image_to_window(img->mlx_ptr,img->mlx_wd, img->img, 0, 0);
		mlx_loop(img->mlx_ptr);
}