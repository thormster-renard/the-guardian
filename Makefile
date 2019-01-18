# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thormster <thormster.renard@outlook.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/28 22:58:01 by thormster         #+#    #+#              #
#    Updated: 2018/09/28 22:58:01 by thormster        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	the_last_guardian

ifeq ($(OS), Windows_NT)
SRC		=	sources\main.cpp			\
			sources\CombatState.cpp			\
			sources\Ennemi.cpp			\
			sources\Game.cpp			\
			sources\GameState.cpp			\
			sources\Inventaire.cpp			\
			sources\Item.cpp			\
			sources\MainMenuState.cpp		\
			sources\msgfonctions.cpp		\
			sources\Personnage.cpp			\
			sources\PersonnageCreatorState.cpp	\
			sources\PersonnageMenuState.cpp		\
			sources\PersonnageSelectorState.cpp	\
			sources\PersonnageStatMenuState.cpp	\
			sources\Stats.cpp			\
			sources\TravelMenuState.cpp		\
			sources\Weapon.cpp
else
SRC		=	sources/main.cpp			\
			sources/CombatState.cpp			\
			sources/Ennemi.cpp			\
			sources/Game.cpp			\
			sources/GameState.cpp			\
			sources/Inventaire.cpp			\
			sources/Item.cpp			\
			sources/MainMenuState.cpp		\
			sources/msgfonctions.cpp		\
			sources/Personnage.cpp			\
			sources/PersonnageCreatorState.cpp	\
			sources/PersonnageMenuState.cpp		\
			sources/PersonnageSelectorState.cpp	\
			sources/PersonnageStatMenuState.cpp	\
			sources/Stats.cpp			\
			sources/TravelMenuState.cpp		\
			sources/Weapon.cpp
endif

else
SRC		=	sources/main.cpp			\
			sources/CombatState.cpp			\
			sources/Ennemi.cpp			\
			sources/Game.cpp			\
			sources/GameState.cpp			\
			sources/Inventaire.cpp			\
			sources/Item.cpp			\
			sources/MainMenuState.cpp		\
			sources/msgfonctions.cpp		\
			sources/Personnage.cpp			\
			sources/PersonnageCreatorState.cpp	\
			sources/PersonnageMenuState.cpp		\
			sources/PersonnageSelectorState.cpp	\
			sources/PersonnageStatMenuState.cpp	\
			sources/Stats.cpp			\
			sources/TravelMenuState.cpp		\
			sources/Weapon.cpp
endif

OBJ		=	$(SRC:.cpp=.o)

all		:	$(OBJ)
			g++ -o $(NAME) $(OBJ)

ifeq ($(OS), Windows_NT)
clean	:
			del $(OBJ)
else
clean	:
			rm -rf $(OBJ)
endif

ifeq ($(OS), Windows_NT)
fclean	:	clean
			del $(NAME).exe
else
fclean	:	clean
			rm -rf $(NAME)
endif

re		:	fclean all
