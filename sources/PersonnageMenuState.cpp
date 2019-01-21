/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PersonnageMenuState.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thormster <thormster.renard@outlook.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:01:50 by thormster         #+#    #+#             */
/*   Updated: 2018/11/23 19:01:50 by thormster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../headers/PersonnageMenuState.hpp"

PersonnageMenuState::PersonnageMenuState(Personnage*& personnage, std::stack<Stats*>*etat) : personnage(personnage), Stats()
{
  this->etat = etat;
}

PersonnageMenuState::~PersonnageMenuState() {}

void        PersonnageMenuState::update()
{
  this->printMenu();
  this->updateMenu();
}

void        PersonnageMenuState::printMenu()
{
#ifdef _WIN32
  system("CLS");
#elif __linux__
  system("clear");
#endif
  std::cout
    << gui::msgMenuTitre("Menu du personnage")
    << this->personnage->getMenuBar(false)
    << gui::msgMenuDiviseur(40, '-')
    << gui::msgMenuItem(10, 1, "Nom et Biographie")
    << gui::msgMenuItem(10, 2, "Statistiques")
    << gui::msgMenuItem(10, 3, "Assigner les points de competences")
    << gui::msgMenuItem(10, 4, "Inventaire")
    << gui::msgMenuItem(10, 5, "Quitter le menu")
    << gui::msgMenuDiviseur(40, '-');
}

void        PersonnageMenuState::updateMenu()
{
  switch (this->getChoice())
    {
    case 1:
#ifdef _WIN32
      system("CLS");
      std::cout << this->personnage->toStringNameBio() << std::endl;
      system("PAUSE");
      break;
#elif __linux__
      system("clear");
      std::cout << this->personnage->toStringNameBio() << std::endl;
      std::cin.get();
      break;
#endif
    case 2:
#ifdef _WIN32
      system("CLS");
      std::cout << this->personnage->toStringStats() << std::endl;
      system("PAUSE");
      break;
#elif __linux__
      system("clear");
      std::cout << this->personnage->toStringStats() << std::endl;
      std::cin.get();
      break;
#endif
    case 3:
      this->etat->push(new PersonnageStatMenuState(this->personnage, this->etat));
      break;
    case 4:
      this->etat->push(new PersonnageInventaireState(this->personnage, this->etat));
      break;
    case 5:
      this->setQuit(true);
      break;
    default:
#ifdef _WIN32
      system("CLS");
      std::cout << gui::msgErreur("Vous devez faire un choix qui.. et bien qui existe !");
      system("PAUSE");
#elif __linux__
      system("clear");
      std::cout << gui::msgErreur("Vous devez faire un choix qui.. et bien qui existe !");
      std::cin.get();
#endif
      break;
    }
}
