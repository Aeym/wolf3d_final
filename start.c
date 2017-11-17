/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealrick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 03:03:28 by ealrick           #+#    #+#             */
/*   Updated: 2017/10/31 03:03:30 by ealrick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void			start_game(t_start *s)
{
	SDL_SetRenderDrawColor(s->renderer, 0, 0, 0, 0);
	SDL_RenderClear(s->renderer);
	SDL_RenderPresent(s->renderer);
	wolf(s);
	s->game = 0;
}

static void			start_menu(t_start *s)
{
	SDL_SetRenderDrawColor(s->renderer, 0, 0, 0, 0);
	SDL_RenderClear(s->renderer);
	SDL_WaitEvent(&s->event);
	start_game(s);
}

void				start(t_start *s)
{
	SDL_CreateWindowAndRenderer(1600, 900, SDL_WINDOW_OPENGL,
		&s->window, &s->renderer);
	SDL_GetWindowSize(s->window, &s->w, &s->h);
	start_menu(s);
}
