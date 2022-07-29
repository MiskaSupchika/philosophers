NAME		=	philo

SRCS		=	philo/main.c philo/utils.c \
				philo/food_sleep_and_think.c 

SRCS_BONUS	=	philo_bonus/main.c philo_bonus/utils.c \
				philo_bonus/food_sleep_and_think.c

BONUS_OBJS	=	$(SRCS_BONUS:.c=.o)

OBJS		=	$(SRCS:.c=.o)

HEADER		=	philo.h

CFLAGS		=	#-Werror -Wall -Wextra

CC			=	gcc

LIBFT		=	./libft/libft.a

NONE='\033[0m'
GREEN='\033[32m'

.c :.o	${HEADER}
	${CC} ${CFLAGS} -c $< -o $@

all: $(NAME)


$(NAME): $(OBJS) $(MLX) $(LIBFT)
		$(CC) -g $(OBJS) ${LIBFT} -pthread -o  $(NAME)

$(LIBFT):
	make -C ./libft

clean:
	rm -rf $(OBJS) 

fclean: clean
	rm -rf $(NAME)

re: clean all 

bonus:  $(BONUS_OBJS) $(LIBFT)
		ar rc $(NAME) $(BONUS_OBJS)

.PHONY: all, clean, fclean, re

norm:
		@norminette ${SRCS} ${SRCS_BONUS} ${HEADER}
		@printf ${GREEN}${CURSIVE}"Norm ok\n"${NONE}