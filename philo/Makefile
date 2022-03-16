# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 09:52:26 by lleveque          #+#    #+#              #
#    Updated: 2022/03/16 14:50:10 by lleveque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ${SRCS_MAIN} ${SRCS_PHILO} ${SRCS_PARSING} ${SRCS_ERROR} ${SRCS_UTILS}

SRCS_MAIN = $(addprefix srcs/, main.c)

SRCS_PHILO = $(addprefix srcs/philo/, philo.c init.c threading.c routine.c)

SRCS_PARSING = $(addprefix srcs/parsing/, parse_args.c)

SRCS_ERROR = $(addprefix srcs/error/, check_args.c check_utils.c messages.c)

SRCS_UTILS = $(addprefix srcs/utils/, error_utils.c parse_utils.c philo_utils.c exit.c)

OBJS = ${SRCS:.c=.o}

NAME = philo

CC = clang

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -pthread

all:	${NAME}

BRED="\033[1;31m"
RED='\033[0;31m'
BGREEN='\033[1;32m'
BYELLOW='\033[1;33m'
YELLOW='\033[0;33m'
BLUE='\033[1;36m'
BROSE='\033[1;35m'
ROSE='\033[0;35m'

${NAME}:	${OBJS}
			@echo ${BYELLOW}"making" ${YELLOW}"${NAME}..."
			@${CC} ${OBJS} ${CFLAGS} -o ${NAME} ${LIBFT}
			@echo ${BGREEN}"${NAME} is ready !"${NONE}

.c.o:
	@echo ${BROSE}"compiling" ${BLUE}"[${CFLAGS}]"${ROSE}" ${<:.c=.c}..."
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
		@echo ${BRED}"removing" ${RED}"objects..."
		@${RM} ${OBJS}

fclean:		clean
			@echo ${BRED}"removing" ${RED}"executable..."
			@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
