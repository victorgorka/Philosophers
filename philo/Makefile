define HEADER
                              Proyect
                                by
                              vde-prad
  _____  _     _ _                       _                   
 |  __ \| |   (_) |                     | |                  
 | |__) | |__  _| | ___  ___  ___  _ __ | |__   ___ _ __ ___ 
 |  ___/| '_ \| | |/ _ \/ __|/ _ \| '_ \| '_ \ / _ \ '__/ __|
 | |    | | | | | | (_) \__ \ (_) | |_) | | | |  __/ |  \__ \\
 |_|    |_| |_|_|_|\___/|___/\___/| .__/|_| |_|\___|_|  |___/
                                  | |                        
                                  |_|                                                                                                                                                                                                  

endef
export HEADER

SRCS	= 	main.c \
			utils.c \
			init.c
OBJS	= ${SRCS:.c=.o}
NAME	= philo
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I -pthread -fsanitize=thread -g
RM		= rm -f
COLOR	= \033[1;36m
################# RULES #####################

all: $(NAME)


$(NAME): ${OBJS}
	@echo "\nCOMPILING PHILOSOPHERS"
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}
	@echo "$(COLOR)$$HEADER"

clean:
	@echo "CLEANED"
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re