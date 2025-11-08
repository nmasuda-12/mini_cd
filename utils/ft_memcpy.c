/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmasuda <nmasuda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 21:22:58 by nmasuda           #+#    #+#             */
/*   Updated: 2025/11/08 20:47:24 by nmasuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ucd;
	const unsigned char	*ucs;

	if (dest == 0 && src == 0)
		return (NULL);
	ucd = (unsigned char *)dest;
	ucs = (const unsigned char *)src;
	while (n)
		*ucd++ = (--n, *ucs++);
	return (dest);
}
