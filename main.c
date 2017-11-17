/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealrick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 03:03:17 by ealrick           #+#    #+#             */
/*   Updated: 2017/10/31 03:03:22 by ealrick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int				main(void)
{
	t_start		s;

	s.start = 1;
	s.menu = 1;
	s.game = 1;
	s.close = 0;
	s.logo = NULL;
	s.logosurf = NULL;
	SDL_Init(SDL_INIT_VIDEO);
	start(&s);
	SDL_DestroyWindow(s.window);
	SDL_Quit();
	return (0);
}
