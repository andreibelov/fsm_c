/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:37:43 by abelov            #+#    #+#             */
/*   Updated: 2023/11/02 17:37:47 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Copy src to dest, truncating or null-padding to always copy n bytes.
 * Return dest.
 * If there is no terminating null byte in the first n bytes of src, strncpy()
 * produces an unterminated string in dest.
 * `const char*` is a mutable pointer to an immutable character/string.
 * You cannot change the contents of the location(s) this pointer points to.
 */
char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	const char		*s = src;
	char *const		save_pointer = dest;
	unsigned int	i;

	i = 0;
	while (*s && (i++ < n))
		*dest++ = *s++;
	while (i++ < n)
		*dest++ = '\0';
	return (save_pointer);
}

/**
 * ft_strlen() - calculates the length of the string pointed to by s, excluding
 * the terminating null byte ('\0').
 * Returns the number of bytes in the string pointed to by s.
 */
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

/**
 * The ft_toupper() function converts lowercase letters to uppercase.
 * Returns its uppercase equivalent, if an uppercase representation exists
 * in the current locale.  Otherwise, it returns c.
 */
int	ft_toupper(int c)
{
	if (!((c >= 'a') && (c <= 'z')))
		return (c);
	return (c - 'a' + 'A');
}

/**
 * The ft_tolower() function converts uppercase letters to lowercase.
 * Returns its lowercase equivalent, if a lowercase representation exists
 * in the current locale.  Otherwise, returns c.
 */
int	ft_tolower(int c)
{
	if (!((c >= 'A') && (c <= 'Z')))
		return (c);
	return (c - 'A' + 'a');
}
