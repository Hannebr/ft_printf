# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: hbrouwer <hbrouwer@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/19 16:08:13 by hbrouwer      #+#    #+#                  #
#    Updated: 2022/10/19 16:58:35 by hbrouwer      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

AR = ar

FLAGS = -Wall -Werror -Wextra

ARFLAGS = -crs

SRC = 

OBJ = $(SRC:.c=.o)

all:		$(NAME)

%.o:		%.c
			@$(CC) $(FLAGS) -c $< -o $@

$(NAME):	$(OBJ)
			@$(AR) $(ARFLAGS) $(NAME) $(OBJ)

clean:
			rm -f $(OBJ)
			
fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re