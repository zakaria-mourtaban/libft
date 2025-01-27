/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matches.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourtab <zakariamourtaban@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:34:42 by zmourtab          #+#    #+#             */
/*   Updated: 2025/01/27 14:40:44 by zmourtab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	matches(char *pattern, char *string)
{
	while (*pattern && *string)
	{
		if (*pattern == '*')
		{
			while (*string && *string != ' ' && *string != ',')
				*string++;
			*pattern++;
		}
		else if (*pattern == ' ' || *pattern == ',')
		{
			if (*string != *pattern)
				return (0);
			*pattern++;
			*string++;
		}
		else
		{
			if (*pattern != *string)
				return (0);
			*pattern++;
			*string++;
		}
	}
	return (*pattern == '\0' && *string == '\0');
}
