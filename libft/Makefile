CC			:= gcc
TARGET		:= libft.a
OBJDIR		:= obj
SRCDIR		:= src
INCDIR		:= includes
OBJEXT		:= o
SRCEXT		:= c
CFLAGS		+= -Wall -Wextra -Werror
INC         := -I $(INCDIR)

CHR 		:= ft_putchar ft_putchar_fd
LST			:= ft_lstadd ft_lstdel ft_lstdelone ft_lstiter ft_lstmap ft_lstnew ft_lstappend ft_lstfree
NBR			:= ft_atoi ft_itoa ft_itoa_base ft_nbrlen ft_nbrlen_base ft_putnbr ft_putnbr_fd
MEM			:= ft_bzero ft_memalloc ft_memccpy ft_memchr ft_memcmp \
					ft_memcpy ft_memdel ft_memmove ft_memset ft_realloc
CTYPE		:= ft_abs ft_isalnum ft_isalpha ft_isascii ft_isblank ft_iscntrl \
					ft_isdigit ft_isgraph ft_islower ft_isprint ft_ispunct  \
					ft_isspace ft_isupper ft_isxdigit ft_tolower ft_toupper
STR			:=  ft_putendl ft_putendl_fd ft_putstr ft_putstr_fd ft_strcat ft_strchr \
					ft_strclr ft_strcmp ft_strcpy ft_strdel ft_strdup ft_strequ \
					ft_striter ft_striteri ft_strjoin ft_strlcat ft_strlen ft_strmap \
					ft_strmapi ft_strncat ft_strncmp ft_strncpy ft_strndup ft_strnequ \
					ft_strnew ft_strjoinf ft_strnlen ft_strnstr ft_strrchr ft_strsplit \
					ft_strstr ft_strsub ft_strtrim get_next_line ft_tbldel ft_wctomb \
					ft_countwords ft_log
PRINTF		:= ft_printf_1 ft_printf_2 ft_printf_dispatcher ft_printf_handle ft_printf_flags \
					ft_printf_array_1 ft_printf_array_2 ft_printf_c ft_printf_dp \
					ft_printf_nf ft_printf_s ft_printf_b ft_printf_uox
TREES		:= btree_add_node btree_apply_inorder btree_apply_postorder btree_apply_preorder \
					btree_create_node
ARR			:= ft_arr_create ft_arr_del ft_arr_get ft_arr_new ft_arr_pop ft_arr_push \
					ft_arr_remove ft_arr_resize ft_arr_set

FILES		:= $(addprefix chr/, $(CHR)) \
				$(addprefix ctype/, $(CTYPE)) \
				$(addprefix lst/, $(LST)) \
				$(addprefix mem/, $(MEM)) \
				$(addprefix nbr/, $(NBR)) \
				$(addprefix str/, $(STR)) \
				$(addprefix printf/, $(PRINTF)) \
				$(addprefix trees/, $(TREES)) \
				$(addprefix arr/, $(ARR)) \

.PHONY = all clean fclean

SRC			:= $(addprefix $(SRCDIR)/, $(addsuffix .$(SRCEXT), $(FILES)))
OBJ			:= $(patsubst $(SRCDIR)/%, $(OBJDIR)/%, $(SRC:.$(SRCEXT)=.$(OBJEXT)))

MAX			:=	$(words $(OBJ))
n			:=	x
increment	=	$1 x
COUNTER		=	$(words $n)$(eval n := $(call increment,$n))


all: obj $(TARGET)

obj:
	@mkdir -p $(OBJDIR)

$(TARGET): $(OBJ)
	@printf "\r\e[32mCompiling...(%d/%d)[DONE]\n\e[0m" $(MAX) $(MAX)
	@printf "\e[32mLinking and indexing... \e[0m"
	@ar rcs $(TARGET) $(OBJ)
	@printf "\e[32m[DONE]\e[0m\n"
	@echo	"\033[32mCreated LIBFT\033[0m"

$(OBJDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
	@printf "\r\e[32mCompiling...(%d/%d)\e[0m" $(COUNTER) $(MAX)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(TARGET)
	@echo "\033[32mRemoved LIBFT\033[0m"
	
re: fclean all
