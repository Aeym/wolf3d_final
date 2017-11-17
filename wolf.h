/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealrick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 03:04:25 by ealrick           #+#    #+#             */
/*   Updated: 2017/10/31 03:04:27 by ealrick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# define WIDTH 1600
# define HEIGHT 900
# define MW 20
# define MH 20
# define NBIMG 7
# define NBTEXT 9
# include <stdlib.h>
# include <math.h>
# include "libft/libft.h"
# include <SDL2/SDL.h>

typedef struct		s_start
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Surface		*logosurf;
	SDL_Texture		*logo;
	SDL_Texture		*tbmp[NBIMG];
	SDL_Surface		*sbmp[NBIMG];
	SDL_Texture		*ttext[NBTEXT];
	SDL_Surface		*stext[NBTEXT];
	SDL_Event		event;
	SDL_Rect		dest;
	const Uint8		*keystates;
	int				start;
	int				menu;
	int				skip;
	int				game;
	int				i;
	int				w;
	int				h;
	int				close;
}					t_start;

typedef struct		s_wolf
{
	int				mapx;
	int				mapy;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				buffer[MH][MW];
	int				worldmap[MH][MW];
	int				x;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			camx;
	double			plx;
	double			ply;
	double			rposx;
	double			rposy;
	double			rdirx;
	double			rdiry;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwd;
	int				tp;
	int				dtp;
}					t_wolf;

typedef struct		s_draw
{
	int				r;
	int				g;
	int				b;
	int				lineh;
	int				start;
	int				end;
}					t_draw;

typedef struct		s_key
{
	double			frimetime;
	double			mvspeed;
	double			rotspeed;
	double			tmpdirx;
	double			tmplx;
}					t_key;

void				start(t_start *s);
void				handle_game(t_start *s, t_wolf *e);
void				menu_keys(t_start *s);
void				wolf(t_start *s);
void				calc(t_wolf *e, t_start *s);
void				draw(t_wolf *e, t_start *s);
void				tp_case1(t_start *s, t_wolf *e);
void				calc_pos(t_start *s);
void				color1(t_wolf *e, t_draw *d);
void				color2(t_wolf *e, t_draw *d);
void				color3(t_wolf *e, t_draw *d);
void				color4(t_wolf *e, t_draw *d);
void				color5(t_wolf *e, t_draw *d);
void				color6(t_wolf *e, t_draw *d);
void				color7(t_wolf *e, t_draw *d);
void				color8(t_wolf *e, t_draw *d);

#endif
