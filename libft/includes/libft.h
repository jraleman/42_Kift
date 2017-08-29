/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 16:58:42 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/25 23:00:10 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdint.h>
# include <wchar.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>

# define CHK(a, b) if(1){if(a){return(b);}}
# define CHK1(a, b, c) if(1){if(a){b; return(c);}}
# define CHK2(a, b, c, d) if(1){if(a){b; c; return(d);}}
# define CHK3(a, b, c, d, e) if(1){if(a){b; c; d; return(e);}}
# define CHK4(a, b, c, d, e, f) if(1){if(a){b; c; d; e; return(f);}}

# define LOG(M,...) ft_log_err(__FILE__, __LINE__, M, ##__VA_ARGS__)
# define CHECK(a,b,M,...) if(1){if(a){(LOG(M, ##__VA_ARGS__));b;}}
# define CHECK1(a,b,c,M,...) if(1){if(a){LOG(M, ##__VA_ARGS__);b;c;}}
# define CHECK2(a,b,c,d,M,...) if(1){if(a){LOG(M, ##__VA_ARGS__);b;c;d;}}
# define CHECK3(a,b,c,d,e,M,...) if(1){if(a){LOG(M, ##__VA_ARGS__);b;c;d;e;}}

# define MEMCHECK(a) CHECK((!a), RETURN(-1), "Out of Memory");
# define MEMCHECK1(a, b) CHECK1((!a), b, RETURN(-1), "Out of Memory");
# define MEMCHECK2(a, b, c) CHECK2((!a), b, c, RETURN(-1), "Out of Memory");

# define CHECK_MEM(a, b) CHECK((!a), b, "Out of Memory")
# define CHECK_MEM1(a, b, c) CHECK1((!a), b, c, "Out of Memory")
# define CHECK_MEM2(a, b, c, d) CHECK2((!a), b, c, d, "Out of Memory")
# define RETURN(a) return(a)

# define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
# define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
# define ISDIGIT(a) (a >= 48 && a <= 57)
# define ISUPPER(a) (a >= 'A' && a <= 'Z')
# define ISLOWER(a) (a >= 'a' && a <= 'z')
# define ISALPHA(a) (ISUPPER(a) || ISLOWER(a))
# define ISALNUM(a) (ISALPHA(a) || ISDIGIT(a))
# define ISASCII(a) (a >= 0 && a <= 127)
# define ISBLANK(a) (a == ' ' || a == '\t')
# define ISCNTRL(a) ((a >= 0 && a <= 37) || (a == 127))
# define ISGRAPH(a) (a >= 33 && a <= 126)
# define ISPRINT(a) (a >= 32 && a <= 126)
# define ISSPACE(a) ((a >= 9 && a <= 13) || (a == 32))
# define ISXDIGIT(a) (ISDIGIT(a)|| (a >= 65 && a <= 70) || (a >= 97 && a <= 102)
# define TOLOWER(a) (a >= 'A' && a <= 'Z' ? a + 32 : a)
# define TOUPPER(a) (a >= 'a' && a <= 'z' ? a - 32 : a)
# define STRJOIN_FREE_SRC1 1
# define STRJOIN_FREE_SRC2 2
# define STRJOIN_FREE_BOTH 3

# define CLEAR "\033[0m"
# define YELLOW "\033[33m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
# define BLUE "\033[34m"

# ifdef NDEBUG
#  define DEBUG(M, ...)
# else
#  define DEBUG(M, ...) ft_log_debug(__FILE__, __LINE__, M, ##__VA_ARGS__)
# endif

/*
** Ctype
*/

int					ft_isalnum(int c);
int					ft_isalpha(int	c);
int					ft_isascii(int c);
int					ft_isblank(int c);
int					ft_iscntrl(int c);
int					ft_isdigit(int c);
int					ft_isgraph(int c);
int					ft_islower(int c);
int					ft_isprint(int c);
int					ft_ispunct(int c);
int					ft_isspace(int c);
int					ft_isupper(int c);
int					ft_isxdigit(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);

/*
** Wide Character
*/

int					ft_wctomb(char *tmp, wchar_t org);

/*
** Putin
*/

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr(int n);
void				ft_putstr(char const *src);
void				ft_putstr_fd(char const *src, int fd);
void				ft_putendl(char const *src);
void				ft_putendl_fd(char const *src, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
** Str
*/

size_t				ft_strlcat(char *src1, const char *src2, size_t size);
size_t				ft_strlen(const char *src);
size_t				ft_strnlen(const char *src, size_t maxlen);
int					ft_strcmp(const char *src1, const char *src2);
int					ft_strncmp(const char *src1, const char *src2, size_t len);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t len);
void				ft_strdel(char **as);
void				ft_strclr(char *src);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_tbldel(char **tbl);
char				*ft_strchr(const char *src, int c);
char				*ft_strrchr(const char *src, int c);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strdup(const char *src);
char				*ft_strndup(const char *src, size_t len);
char				*ft_strstr(const char *src, const char *to_find);
char				*ft_strnstr(const char *src, const char *to_find, size_t n);
char				*ft_strcat(char *dst, const char *src);
char				*ft_strncat(char *src1, const char *src2, size_t len);
char				*ft_strnew(size_t size);
char				*ft_strmap(char const *src, char (*f)(char));
char				*ft_strmapi(char const *src, char (*f)(unsigned int, char));
char				*ft_strsub(char const *src, unsigned int start, size_t len);
char				*ft_strjoin(char const *src1, char const *src2);
char				*ft_strjoinf(char *s1, char *s2, size_t d);
char				*ft_strtrim(char const *src);
char				**ft_strsplit(const char *src, char c);
int					ft_countwords(char const *src, char c);

/*
** Mem
*/

int					ft_memcmp(const void *src1, const void *src2, size_t len);
void				ft_memdel(void **ap);
void				ft_bzero(void *src, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *s, int s_c, size_t len);
void				*ft_memchr(const void *src, int src_c, size_t len);
void				*ft_memset(void *src, int c, size_t len);
void				*ft_memalloc(size_t size);
void				*ft_realloc(void *src, size_t srcsize, size_t newsize);

/*
** Conversion
*/

int					ft_abs(int i);
int					ft_atoi(const char *str);
char				*ft_itoa(intmax_t nb);
char				*ft_itoa_base(uintmax_t n, int8_t base, const char *spec);
int8_t				ft_nbrlen(intmax_t src);
int8_t				ft_nbrlen_base(uintmax_t src, int8_t base);

/*
** List
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *src, size_t sze);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdelone(t_list **alst, void(*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void(*f)(t_list *cnt));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *cnt));
void				ft_lstdel(t_list**alst, void(*del)(void*, size_t));
void				ft_lstappend(t_list **alst, t_list *new);
void				ft_lstfree(t_list **alst);

/*
** GETNEXTLINE
*/

# define GNL_BUFF_SIZE 1000
# define GNL_MAX_FD 3

int					get_next_line(const int fd, char **line);

/*
** PRINTF
*/

int					ft_printf(const char *in, ...);
int					ft_dprintf(int fd, const char *in, ...);
int					ft_sprintf(char *ret, const char *fmt, ...);
int					ft_snprintf(char *ret, size_t size, const char *fmt, ...);
int					ft_asprintf(char **ret, const char *fmt, ...);
int					ft_vprintf(const char *fmt, va_list ap);
int					ft_vsprintf(char *ret, const char *fmt, va_list ap);
int					ft_vdprintf(int fd, const char *fmt, va_list ap);
int					ft_vasprintf(char **ret, const char *fmt, va_list ap);

/*
** Binary Search Trees
*/

typedef struct		s_btree
{
	int				item;
	struct s_btree	*left;
	struct s_btree	*right;
}					t_btree;
t_btree				*btree_create_node(int item);
void				btree_add_node(t_btree **root, t_btree *node);
void				btree_apply_inorder(t_btree *root, void (*applyf)(int));
void				btree_apply_postorder(t_btree *root, void (*applyf)(int));
void				btree_apply_preorder(t_btree *root, void (*applyf)(int));

/*
** LOG
*/

int					ft_log_err(char *file, int line, char *message, ...);
int					ft_log_debug(char *file, int line, char *message, ...);

/*
** ARR
*/

# define ARR_LAST(A) ((A)->contents[(A)->end - 1])
# define ARR_FIRST(A) ((A)->contents[0])
# define ARR_END(A) ((A)->end)
# define ARR_COUNT(A) ARR_END(A)
# define ARR_MAX(A) ((A)->max)
# define ARR_FREE(E) free((E))
# define DEFAULT_EXPAND_RATE 300

typedef struct		s_arr
{
	int				end;
	int				max;
	size_t			element_size;
	size_t			expand_rate;
	void			**contents;
	void			(*del)(void *elm);
}					t_arr;

int					arr_set(t_arr *array, int i, void *el);
void				*arr_get(t_arr *array, int i);
void				*arr_remove(t_arr *array, int i);
void				*arr_new(t_arr *array);
t_arr				*arr_create(size_t element_size, size_t initial_max);
void				arr_destroy(t_arr *array);
void				arr_clear(t_arr *array);
int					arr_expand(t_arr *array);
int					arr_contract(t_arr *array);
int					arr_push(t_arr *array, void *el);
void				*arr_pop(t_arr *array);
void				arr_del(t_arr *array);
#endif
