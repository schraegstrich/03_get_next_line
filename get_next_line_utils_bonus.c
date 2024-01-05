/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkirillo <lkirillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:20:30 by lkirillo          #+#    #+#             */
/*   Updated: 2024/01/05 18:52:29 by lkirillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *str1)
{
	int		len;
	char	*str2;

	len = ft_strlen((char *)str1);
	str2 = malloc ((len + 1) * sizeof(char));
	if (!str2)
		return (0);
	ft_memcpy(str2, str1, len + 1);
	return (str2);
}

void	*ft_memcpy(void *dst, const void *src, int n)
{
	int					i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (n > 0)
	{
		((unsigned char *)dst)[i] = ((unsigned const char *)src)[i];
		i++;
		n--;
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	int		j;
	char	*newstr;

	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	newstr = malloc((len + 1) * sizeof(char));
	i = 0;
	j = 0;
	if (!newstr)
		return (0);
	while (i < len && s1[i] != '\0')
	{
		newstr[i] = s1[i];
		i++;
	}
	while (i < len && s2[j] != '\0')
	{
		newstr[i] = s2[j];
		i++;
		j++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*substr;
	unsigned int		i;
	unsigned int		s_len;

	i = 0;
	if (!s)
		return (0);
	s_len = ft_strlen((char *)s);
	if (len == 0 || start >= s_len)
		substr = malloc (1 * sizeof(char));
	else if (len > s_len - start)
		substr = malloc((s_len - start + 1) * sizeof(char));
	else
		substr = malloc ((len + 1) * sizeof(char));
	if (!substr)
		return (0);
	while (i < len && start < s_len)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
