/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:44:05 by abelov            #+#    #+#             */
/*   Updated: 2023/11/02 17:44:07 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

/* ---------- STRING -------------------- */
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_atoi(const char *nptr);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
/*
 * Copy src to dest, truncating or null-padding to always copy n bytes.
 * Return dest.
 * If there is no terminating null byte in the first n bytes of src, strncpy()
 * produces an unterminated string in dest.
 * `const char*` is a mutable pointer to an immutable character/string.
 * You cannot change the contents of the location(s) this pointer points to.
 */
char	*ft_strncpy(char *dest, char *src, unsigned int n);
size_t	ft_strlen(const char *s);
/**
 *  The ft_strlcat() function concatenates strings. It take the full size of
 *  the buffer (not just the length) and guarantees to NUL-terminate the result
 *  (as long as there is at least one byte free in dst).
 *  ft_strlcat() only operate on true “C” strings.  This means that both src
 *  and dst must be NUL-terminated.
 *
 *  Returns the total length of the string tried to create.
 *  That means the initial length of dst plus the length of src.
 */
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strstr_fixed(char *haystack, char *words[]);
char	*ft_strstr(char *str, char *to_find);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(char *src);
/**
 * Allocates char array and fills it with empty bytes.
 * Returns the new string or NULL if the allocation fails.
 */
char	*ft_empty_string(size_t length);

/**
 * Allocates (with malloc(3)) and returns a new string, which is the result
 * of the concatenation of 's1' and 's2'.
 * Parameters
 * 		s1: The prefix string.
 * 		s2: The suffix string.
 * Return value:
 * 		The new string or NULL if the allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * Allocates (with malloc(3)) and returns a copy of 's1' with the characters
 * specified in 'set' removed from the beginning and the end of the string.
 * Parameters
 * 		s1: The string to be trimmed.
 * 		set: The reference set of characters to trim.
 * Return value:
 * 		The new string or NULL if the allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set);

/**
 * Applies the function 'f' on each character of the string passed as argument,
 * passing its index as first argument.
 * Each character is passed by address to 'f' to be modified if necessary.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/**
 * Applies the function 'f' to each character of the string 's', and passing
 * its index as first argument to create a new string (with malloc(3)) resulting
 * from successive applications of 'f'.
 * Parameters
 * 		s: The string on which to iterate.
 * 		f: The function to apply to each character.
 * Return value:
 * 		The string created from the successive applications of 'f'.
 * 		Returns NULL if the allocation fails.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/**
 *
 * The  ft_strtok()  function  breaks a string into a sequence of zero or more
 * nonempty tokens.  On the first call to ft_strtok(), the string to be parsed
 * should be specified in str. In each subsequent call that  should  parse  the
 * same string, str must be NULL.
 *
 * The delim argument specifies a set of bytes that delimit the tokens in the
 * parsed string.  The caller may specify different strings in delim
 * in successive calls that parse the same string.
 *
 * Each call to ft_strtok() returns a pointer to a null-terminated string
 * containing the next token. This string does not include the delimiting byte.
 * If no more tokens are found, ft_strtok() returns NULL.
 */
char	*ft_strtok(char *str, const char *delim);
/**
 * The strtok_r() function is a reentrant version of strtok().
 * The saveptr argument is a pointer to a char * variable that is used
 * internally by ft_strtok_r() in order to maintain context between successive
 * calls that parse the same string.
 *
 * On the first call to ft_strtok_r(), str should point to the string to be
 * parsed, and the value of *saveptr is  ignored.
 * In subsequent calls, str should be NULL, and saveptr (and the buffer
 * that it points to) should be unchanged since the previous call.
 */
char	*ft_strtok_r(char *str, const char *delim, char **saveptr);
char	**ft_split(char const *s, char c);
/**
 * The ft_strspn() function calculates the length (in bytes) of the initial
 * segment of s which consists entirely of bytes in accept.
 */
size_t	ft_strspn(const char *s, const char *accept);
/**
 * The ft_strcspn() function calculates the length of the initial segment of s
 * which consists entirely of bytes not in reject.
 */
size_t	ft_strcspn(const char *s, const char *reject);
/**
 * The ft_strchr() function returns a pointer to the first occurrence of the
 * character c in the string s.
 * It returns a pointer to the matched character or NULL if the character
 * isn't found. The terminating null byte is considered part of the string,
 * so that if c is specified as '\0', the function returns a pointer to the NULL
 * terminator.
 */
char	*ft_strchr(const char *s, int chr);

/**
 * The ft_strrchr() function returns a pointer to the last occurrence
 * of the character c in the string s.
 */
char	*ft_strrchr(const char *s, int chr);

/**
 * The ft_strncmp() returns an integer indicating the result of the comparison
 * of the first (at most) n bytes of s1 and s2 as follows:
 *     • 0, if the s1 and s2 are equal;
 *     • a negative value if s1 is less than s2;
 *     • a positive value if s1 is greater than s2.
 * The return value is the arithmetic result of subtracting the last compared
 * byte in s2 from the last compared byte in s1. (If the two characters are
 * equal, this difference is 0.).
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * The ft_strnstr() function locates the first occurrence of the null-terminated
 * string little in the string big, where not more than len characters are
 * searched. Characters that appear after a '\0' character are not searched.
 * If little is an empty string, big is returned; if little occurs nowhere in
 * big, NULL is returned; otherwise a pointer to the first character of
 * the first occurrence of little is returned.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len);

/**
 * Description:
 * 		Allocates (with malloc(3)) and returns a substring from the string 's'.
 * Parameters:
 * 		s: The string from which to create the substring.
 * 		start: The start index of the substring in the string `s`.
 * 		len: The maximum length of the substring.
 * Return value:
 * 		The substring.
 * 		NULL if the allocation fails.
 * The substring begins at index 'start' and is of maximum size 'len'.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);
/* ---------- IO -------------------- */
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/* ---------- STD -------------------- */
void	*ft_calloc(size_t nmemb, size_t size);

/* ---------- LIST -------------------- */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;
typedef struct s_dnode {
	int				value;
	struct s_dnode	*next;
	struct s_dnode	*prev;
}					t_dnode;

typedef struct s_dlist_info
{
	int		size;
	t_dnode	*head;
	t_dnode	*tail;
}					t_dlist_info;
typedef void	(*t_func)(void *data, void *user_data);
t_dlist_info	*ft_dlst_new(void);
t_dnode	*ft_dnode_new(int value);
void	ft_dlist_foreach(t_dlist_info *list, t_func func, void *user_data);
void	ft_dlist_free(t_dlist_info *list);
void	ft_dlist_free_full(t_dlist_info **list);
t_dnode	*ft_dlist_pop(t_dlist_info *list);
t_dnode	*ft_dlist_pop_back(t_dlist_info *list);
t_dlist_info	*ft_dlist_append(t_dlist_info *list, int value);
t_dlist_info	*ft_dlist_prepend(t_dlist_info *list, int value);
t_dlist_info	*ft_dlist_push(t_dlist_info *list, t_dnode *dnode);
t_dlist_info	*ft_dlist_push_back(t_dlist_info *list, t_dnode *dnode);
t_dlist_info	*ft_dlist_rotate(t_dlist_info *list);
t_dlist_info	*ft_dlist_rev_rotate(t_dlist_info *list);
t_list	*ft_lstnew(void *content);

int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* ---------- PRINTF -------------------- */
int		ft_printf(const char *format, ...);

typedef size_t	(*t_ft_print_dispatch_f)(va_list *ap);

size_t	ft_print_p(va_list *argp);
size_t	ft_print_d(va_list *argp);
size_t	ft_print_s(va_list *argp);
size_t	ft_print_x(va_list *argp);
size_t	ft_print_upperx(va_list *argp);
size_t	ft_print_u(va_list *argp);
size_t	ft_print_c(va_list *argp);
size_t	ft_print_percent(va_list *argp);

char	*ft_itoa(int nb);
char	*ft_itoa_buf(int nb, char *buf, size_t length);
char	*ft_uitoa_buf(unsigned int abs, char *buf, size_t length);
char	*ft_uitoa(unsigned int nb);
char	*ft_uitoa_base(unsigned int nb, const char *base);
char	*ft_ultoa_buf_base(unsigned long abs,
			char *buf, size_t length, const char *base);
char	*ft_print_pointer(unsigned long long nb);

#endif //LIBFT_H
