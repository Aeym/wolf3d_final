/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealrick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 03:04:12 by ealrick           #+#    #+#             */
/*   Updated: 2017/10/31 03:04:14 by ealrick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		calc_pos(t_start *s)
{
	s->dest.w = s->w;
	s->dest.h = s->h / 2;
	s->dest.x = 0;
	s->dest.y = s->h / 2;
}