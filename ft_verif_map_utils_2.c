/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_map_utils_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 01:43:30 by lnoaille          #+#    #+#             */
/*   Updated: 2020/07/22 01:46:14 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_vect(t_img *param)
{
	param->dirX = 0;
	param->dirY = 0;
	param->planeX = 0;
	param->planeY = 0;
}

void	ft_pos_and_angle(size_t h, size_t w, t_img *param, char cardinal)
{
	param->pos_x = w + 0.5;
	param->pos_y = h + 0.5;
	if (cardinal == 'N')
	{
		param->dirY = -1;
		param->planeX = 0.66;
	}
	else if (cardinal == 'E')
	{
		param->dirX = 1;
		param->planeY = 0.66;
	}
	else if (cardinal == 'S')
	{
		param->dirY = 1;
		param->planeX = -0.66;
	}
	else if (cardinal == 'W')
	{
		param->dirX = -1;
		param->planeY = -0.66;
	}
}
