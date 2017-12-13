/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealrick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 03:02:31 by ealrick           #+#    #+#             */
/*   Updated: 2017/10/31 03:02:34 by ealrick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void		color1(t_wolf *e, t_draw *d)
{
	if (e->side == 0)
	{
		d->r = 0;
		d->b = 0;
		d->g = 255;
	}
	else
	{
		d->r = 0;
		d->b = 0;
		d->g = 125;
	}
}

void		color2(t_wolf *e, t_draw *d)
{
	if (e->side == 1)
	{
		d->r = 0;
		d->b = 255;
		d->g = 0;
	}
	else
	{
		d->r = 0;
		d->b = 125;
		d->g = 0;
	}
}

void		color3(t_wolf *e, t_draw *d)
{
	if (e->side == 1)
	{
		d->r = 255;
		d->b = 0;
		d->g = 0;
	}
	else
	{
		d->r = 125;
		d->b = 0;
		d->g = 0;
	}
}

void		color4(t_wolf *e, t_draw *d)
{
	if (e->side == 1)
	{
		d->r = 255;
		d->b = 0;
		d->g = 100;
	}
	else
	{
		d->r = 125;
		d->b = 0;
		d->g = 50;
	}
}

void		color5(t_wolf *e, t_draw *d)
{
	if (e->side == 1)
	{
		d->r = 180;
		d->b = 180;
		d->g = 180;
	}
	else
	{
		d->r = 80;
		d->b = 80;
		d->g = 80;
	}
}
