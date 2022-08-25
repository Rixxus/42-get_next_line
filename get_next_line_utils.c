/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <rmount@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:22:11 by rmount            #+#    #+#             */
/*   Updated: 2022/08/25 16:02:40 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *substring;
	size_t i;
	size_t j;

	j = 0;
	i = 0;
	substring = malloc(sizeof(char) * (len + 1));
	if (substring == 0) {
		return (NULL);
	}
	while (s[i]) 
	{
		if (i >= start && j < len)
		{
			substring[j] = s[i];
			j++;
		}
		i++;
	}
	substring[j] = '\0';
	return (substring);
}

int  ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*new;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(src);
	new = malloc(sizeof(*new) * (size + 1));
	if (new == 0) 
	{
		return (0);
	}
	while (src[i] != '\0')
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';


}

char	*ft_strjoin(char const *s1, const char *s2)
{
	char	*newstring;
	int	 i;
	int	 j;

	if (!s1 || !s2) 
		return (NULL);
	newstring = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) +1));
	if (!newstring)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		newstring[j++] = s1[i++];
		i = 0;
	while (s2[i])
		newstring[j++] = s2[i++];
	newstring[j] = '\0';
	return (newstring);
}

