/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 10:13:50 by rmount            #+#    #+#             */
/*   Updated: 2022/08/24 21:28:17 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *str)
{
    size_t  i;

    i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);

}

char    *ft_strjoin(char const *s1, const char *s2)
{
    char    *newstring;
    int     i;
    int     j;

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

