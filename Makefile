# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thormster <thormster@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/28 22:58:01 by thormster         #+#    #+#              #
#    Updated: 2018/09/28 22:58:01 by thormster        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	the_last_guardian

SRC		=	$(wildcard *.cpp)

OBJ		=	$(SRC:.cpp=.o)

all:		$(OBJ)
			g++ -o $(NAME) $(OBJ)

clean:		rm -rf $(OBJ)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all