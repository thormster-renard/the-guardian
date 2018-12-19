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

SRC		=	sources/main.cpp					\
			sources/CombatState.cpp				\
			sources/Ennemi.cpp					\
			sources/Game.cpp					\
			sources/GameState.cpp				\
			sources/Inventaire.cpp				\
			sources/Item.cpp					\
			sources/MainMenuState.cpp			\
			sources/msgfonctions.cpp			\
			sources/Personnage.cpp				\
			sources/PersonnageCreatorState.cpp	\
			sources/PersonnageMenuState.cpp		\
			sources/PersonnageSelectorState.cpp	\
			sources/Stats.cpp					\
			sources/TravelMenuState.cpp

OBJ		=	$(SRC:.cpp=.o)

all:		$(OBJ)
			g++ -o $(NAME) $(OBJ)

clean:		rm -rf $(OBJ)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all