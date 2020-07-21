/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distance_to_wall.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:30:59 by lnoaille          #+#    #+#             */
/*   Updated: 2020/07/22 01:33:02 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	ft_distance_to_wall(t_img *param, double screenx)
{
	int hit;
	int step_x;
	int step_y;
	int side;

	param->map_x = (int)param->pos_x;
	param->map_y = (int)param->pos_y;
	hit = 0;
	step_x = sidedist_direction(&param->sidedist_x,
		param->raydir_x, param->pos_x, param->map_x);
	step_y = sidedist_direction(&param->sidedist_y,
		param->raydir_y, param->pos_y, param->map_y);
	side = until_next_wall(param, step_x, step_y);
	if (side == 0)
		return ((param->map_x - param->pos_x +
			(1 - step_x) / 2) / param->raydir_x);
	else
		return ((param->map_y - param->pos_y +
			(1 - step_y) / 2) / param->raydir_y);
}

int		sidedist_direction(double *sidedist, double raydir, double pos, int map)
{
	if (raydir < 0)
	{
		*sidedist = (pos - map) * ft_abs(1 / raydir);
		return (-1);
	}
	else
	{
		*sidedist = (1 + map - pos) * ft_abs(1 / raydir);
		return (1);
	}
}

int		until_next_wall(t_img *param, int step_x, int step_y)
{
	int hit;
	int side;

	hit = 0;
	while (hit == 0)
	{
		if (param->sidedist_x < param->sidedist_y)
		{
			param->sidedist_x += ft_abs(1 / param->raydir_x);
			param->map_x += step_x;
			side = 0;
		}
		else
		{
			param->sidedist_y += ft_abs(1 / param->raydir_y);
			param->map_y += step_y;
			side = 1;
		}
		if (param->map[param->map_y][param->map_x] == '1')
			hit = 1;
	}
	return (side);
}
