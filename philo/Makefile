SRCS	= main.c
OBJS	= ${SRCS:.c=.o}
NAME	= philo
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -pthread
RM		= rm -f
################# RULES #####################

all: $(NAME)


$(NAME): ${OBJS}
	@echo "\nCOMPILING PHILOSOPHERS"
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}
	@echo "\nFINISHED"

clean:
	@echo "CLEANED"
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re