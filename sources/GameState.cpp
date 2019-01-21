/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameState.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thormster <thormster.renard@outlook.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:04:28 by thormster         #+#    #+#             */
/*   Updated: 2018/11/13 19:04:28 by thormster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../headers/GameState.hpp"

GameState::GameState(Personnage*& personnage, std::stack<Stats*>*etat) : personnage(personnage), Stats()
{
  this->etat = etat;
}

GameState::~GameState() {}

void        GameState::update()
{
  this->PrintMenu();
  this->updateMenu();
}

void         GameState::PrintMenu() const
{
#ifdef _WIN32
  system("CLS");
#elif __linux__
  system("clear");
#endif
  std::cout
    << gui::msgMenuTitre("Menu du jeu")
    << this->personnage->getMenuBar(false)
    << gui::msgMenuDiviseur(40, '-')
    << gui::msgMenuItem(10, 1, "Menu du personnage")
    << gui::msgMenuItem(10, 2, "Carte")
    << gui::msgMenuItem(10, 3, "Artisan")
    << gui::msgMenuItem(10, 4, "Se reposer")
    << gui::msgMenuItem(10, 5, "Retour au menu precedent")
    << gui::msgMenuDiviseur(40, '-');
}

void        GameState::updateMenu()
{
  switch (this->getChoice())
    {
    case 1:
      this->etat->push(new PersonnageMenuState(this->personnage, this->etat));
      break;
    case 2:
      this->etat->push(new TravelMenuState(this->personnage, this->etat));
      break;
    case 3:
      break;
    case 4:
#ifdef _WIN32
      system("CLS");
#elif __linux__
      system("clear");
#endif
      if (this->personnage->getLocation() == BOURG)
      {
        this->personnage->reset();
        std::cout << "Vous vous reposez..." << std::endl;
      }
      else
        std::cout << "Vous ne pouvez pas vous reposer ici !\n" << std::endl;
#ifdef _WIN32
      system("PAUSE");
#elif __linux__
      std::cin.get();
#endif
      break;
    case 5:
      this->setQuit(true);
      break;
    default:
#ifdef _WIN32
      system("CLS");
      system("PAUSE");
#elif __linux__
      system("clear");
      std::cin.get();
#endif
      std::cout << "Vous devez faire un choix qui.. et bien qui existe !" << std::endl;
      break;
    }
}
