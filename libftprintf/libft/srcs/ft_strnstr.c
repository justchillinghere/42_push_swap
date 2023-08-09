/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:08:43 by luchitel          #+#    #+#             */
/*   Updated: 2023/03/09 22:26:15 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *) haystack);
	while (*haystack && (len >= needle_len))
	{
		if ((haystack[0] == needle[0])
			&& (ft_strncmp(haystack, needle, needle_len) == 0))
			return ((char *) haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
