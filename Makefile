NAME = built

CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes

MAIN_SRCS =	srcs/echo.c \
	   		srcs/pwd.c \
	   		srcs/env.c \
			srcs/unset.c \
			srcs/exit.c \
			srcs/export.c \
			srcs/export_utils.c \
			srcs/cd.c \
	   		srcs/main.c \

UTIL_SRCS =	utils/ft_atol.c \
			utils/ft_export_strjoin.c \
			utils/check.c \
			utils/error.c \
			utils/free_all.c

SRCS = $(MAIN_SRCS) $(UTIL_SRCS)

$(NAME)	: 
	$(CC) $(CFLAGS) $(SRCS) -o $@

fclean :
	rm -f $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) $(NAME)
