/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_oklab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 10:21:11 by mporras-          #+#    #+#             */
/*   Updated: 2026/11/25 10:21:16 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file rgb_oklab.c
 * @brief Perceptual palette interpolation in Oklab.
 * @see https://bottosson.github.io/posts/oklab/
 */
#include "rgb.h"
#include <math.h>

/** @brief Decode packed sRGB and apply Björn Ottosson's Oklab transform. */
static t_oklab	ft_rgb_to_oklab(t_rgb color)
{
	t_lms	rgb;
	t_lms	lms;

	rgb[0] = ft_rgb_decode((color >> 16) & RGB_MASK);
	rgb[1] = ft_rgb_decode((color >> 8) & RGB_MASK);
	rgb[2] = ft_rgb_decode(color & RGB_MASK);
	lms[0] = cbrt(0.4122214708 * rgb[0] + 0.5363325363 * rgb[1]
			+ 0.0514459929 * rgb[2]);
	lms[1] = cbrt(0.2119034982 * rgb[0] + 0.6806995451 * rgb[1]
			+ 0.1073969566 * rgb[2]);
	lms[2] = cbrt(0.0883024619 * rgb[0] + 0.2817188376 * rgb[1]
			+ 0.6299787005 * rgb[2]);
	return ((t_oklab){
		0.2104542553 * lms[0] + 0.7936177850 * lms[1] - 0.0040720468 * lms[2],
		1.9779984951 * lms[0] - 2.4285922050 * lms[1] + 0.4505937099 * lms[2],
		0.0259040371 * lms[0] + 0.7827717662 * lms[1] - 0.8086757660 * lms[2]
	});
}

/** @brief Convert Oklab to packed sRGB, clipping and rounding at output. */
static t_rgb	ft_oklab_to_rgb(t_oklab color)
{
	double	l;
	double	m;
	double	s;
	t_rgb	channels[3];

	l = color.lightness + 0.3963377774 * color.a + 0.2158037573 * color.b;
	m = color.lightness - 0.1055613458 * color.a - 0.0638541728 * color.b;
	s = color.lightness - 0.0894841775 * color.a - 1.2914855480 * color.b;
	l = l * l * l;
	m = m * m * m;
	s = s * s * s;
	channels[R_I] = ft_rgb_encode(4.0767416621 * l - 3.3077115913 * m
			+ 0.2309699292 * s);
	channels[G_I] = ft_rgb_encode(-1.2684380046 * l + 2.6097574011 * m
			- 0.3413193965 * s);
	channels[B_I] = ft_rgb_encode(-0.0041960863 * l - 0.7034186147 * m
			+ 1.7076147010 * s);
	return (ft_rgb_get(channels));
}

/** @copydoc ft_rgb_lerp_oklab */
t_rgb	ft_rgb_lerp_oklab(t_rgb start, t_rgb end, double factor)
{
	t_oklab	from;
	t_oklab	to;

	if (!(factor > 0))
		return (start & 0xffffff);
	if (factor >= 1)
		return (end & 0xffffff);
	from = ft_rgb_to_oklab(start);
	to = ft_rgb_to_oklab(end);
	from.lightness += (to.lightness - from.lightness) * factor;
	from.a += (to.a - from.a) * factor;
	from.b += (to.b - from.b) * factor;
	return (ft_oklab_to_rgb(from));
}
