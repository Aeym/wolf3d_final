/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealrick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 03:03:48 by ealrick           #+#    #+#             */
/*   Updated: 2017/10/31 03:03:50 by ealrick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		calc3(t_wolf *e, t_start *s)
{
	while (e->hit == 0)
	{
		if (e->sidedistx < e->sidedisty)
		{
			e->sidedistx += e->deltadistx;
			e->mapx += e->stepx;
			e->side = 0;
		}
		else
		{
			e->sidedisty += e->deltadisty;
			e->mapy += e->stepy;
			e->side = 1;
		}
		if (e->worldmap[e->mapx][e->mapy] > 0)
			e->hit = 1;
	}
	if (e->side == 0)
		e->perpwd = (e->mapx - e->rposx + (1 - e->stepx) / 2) / e->rdirx;
	else
		e->perpwd = (e->mapy - e->rposy + (1 - e->stepy) / 2) / e->rdiry;
}

static void		calc2(t_wolf *e, t_start *s)
{
	e->hit = 0;
	if (e->rdirx < 0)
	{
		e->stepx = -1;
		e->sidedistx = (e->rposx - e->mapx) * e->deltadistx;
	}
	else
	{
		e->stepx = 1;
		e->sidedistx = (e->mapx + 1.0 - e->rposx) * e->deltadistx;
	}
	if (e->rdiry < 0)
	{
		e->stepy = -1;
		e->sidedisty = (e->rposy - e->mapy) * e->deltadisty;
	}
	else
	{
		e->stepy = 1;
		e->sidedisty = (e->mapy + 1.0 - e->rposy) * e->deltadisty;
	}
	calc3(e, s);
}

static void		calc1(t_wolf *e, t_start *s)
{
	e->rposx = e->posx;
	e->rposy = e->posy;
	e->rdirx = e->dirx + e->plx * e->camx;
	e->rdiry = e->diry + e->ply * e->camx;
	e->mapx = e->rposx;
	e->mapy = e->rposy;
	e->deltadistx = sqrt(1 + (e->rdiry * e->rdiry) / (e->rdirx * e->rdirx));
	e->deltadisty = sqrt(1 + (e->rdirx * e->rdirx) / (e->rdiry * e->rdiry));
	calc2(e, s);
}

void			calc(t_wolf *e, t_start *s)
{
	int			x;

	while (s->game)
	{
		SDL_SetRenderDrawColor(s->renderer, 20, 20, 20, 0);
		SDL_RenderClear(s->renderer);
		SDL_SetRenderDrawColor(s->renderer, 150, 150, 150, 0);
		calc_pos(s);
		SDL_RenderFillRect(s->renderer, &s->dest);
		e->x = 0;
		while (e->x < s->w)
		{
			e->camx = 2 * e->x / (double)s->w - 1;
			calc1(e, s);
			draw(e, s);
			e->x++;
		}
		SDL_RenderPresent(s->renderer);
		SDL_PollEvent(&s->event);
		handle_game(s, e);
		SDL_Delay(1);
	}
}
