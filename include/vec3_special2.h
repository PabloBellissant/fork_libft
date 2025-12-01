/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_special2.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 08:08:56 by jaubry--          #+#    #+#             */
/*   Updated: 2025/08/21 21:10:27 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_SPECIAL2_H
# define VEC3_SPECIAL2_H

# include <math.h>
# include "vectors_types.h"
# include "vec3_special1.h"

/*
	Normalize with zero-check to avoid division by zero
	Returns original vector if length is zero for safety
*/
static inline t_vec3	vec3_normalize(const t_vec3 v)
{
	const float	len = vec3_length(v);

	if (len == 0.0f)
		return (v);
	return (vec3_div_scalar(v, len));
}

static inline t_vec3	get_tangent(t_vec3 n)
{
	t_vec3	up;

	if (fabsf(n.y) > 0.999f)
		up = vec3(1, 0, 0);
	else
		up = vec3(0, 1, 0);
	return (vec3_normalize(vec3_cross(up, n)));
}

static inline t_vec3 get_bitangent(t_vec3 n, t_vec3 tangent)
{
	return (vec3_cross(n, tangent));
}

static inline float	clamp_branchless(const float val, const float min,
						const float max)
{
	return (fminf(fmaxf(val, min), max));
}

static inline t_vec3	vec3_clamp(const t_vec3 v, const float mn,
						const float mx)
{
	return ((t_vec3){{
				clamp_branchless(v.x, mn, mx),
				clamp_branchless(v.y, mn, mx),
				clamp_branchless(v.z, mn, mx)
			}});
}

#endif
