/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 00:14:25 by lnoaille          #+#    #+#             */
/*   Updated: 2020/07/22 00:49:44 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	void	*dst;

	dst = data->img_addr + (y * data->line_length + x *
		(data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}