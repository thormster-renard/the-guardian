/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainMenuState.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thormster <thormster.renard@outlook.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:50:10 by thormster         #+#    #+#             */
/*   Updated: 2018/11/16 18:50:10 by thormster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../headers/MainMenuState.hpp"

MainMenuState::MainMenuState(std::vector<Personnage*>*listePersonnage, unsigned& personnageActif, std::stack<Stats*>*etat) : Stats(), personnageActif(personnageActif)
{
  this->listePersonnage = listePersonnage;
  this->etat = etat;
}

MainMenuState::~MainMenuState() {}

void    MainMenuState::printMenu()
{
#ifdef _WIN32
  system("CLS");
#elif __linux__
  system("clear");
#endif
  std::cout << gui::msgMenuTitre("Menu principal");
  if (!this->listePersonnage->empty())
    std::cout << this->listePersonnage->at(this->personnageActif)->getMenuBar(false);
  else
    std::cout << gui::msgErreur("Pour debuter le jeu, creez un personnage");
  std::cout
    << gui::msgMenuDiviseur(40, '-')
    << gui::msgMenuItem(10, 1, "Demarrer un nouveau jeu")
    << gui::msgMenuItem(10, 2, "Creer votre personnage")
    << gui::msgMenuItem(10, 3, "Choisir votre personnage")
    << gui::msgMenuItem(10, 4, "Quitter le jeu")
    << gui::msgMenuDiviseur(40, '-');
}

void    MainMenuState::updateMenu()
{
  switch (this->getChoice())
    {
    case 1:
      if (!this->listePersonnage->empty())
	this->etat->push(new GameState(this->listePersonnage->at(this->personnageActif), this->etat));
      else
	{
#ifdef _WIN32
	  system("CLS");
#elif __linux__
	  system("clear");
#endif
	  std::cout << gui::msgErreur("Pour jouer, vous devez d'abord creer, un nouveau personnage.");
#ifdef _WIN32
	  system("PAUSE");
#elif __linux__
	  std::cin.get();
#endif
	}
      break;
    case 2:
      this->etat->push(new PersonnageCreatorState(this->listePersonnage, this->personnageActif, this->etat));
      break;
    case 3:
      this->etat->push(new PersonnageSelectorState(this->listePersonnage, this->personnageActif, this->etat));
      break;
    case 4:
      this->setQuit(true);
      break;
    default:
#ifdef _WIN32
      system("CLS");
#elif __linux__
      system("clear");
#endif
      std::cout << gui::msgErreur("Vous devez faire un choix qui.. et bien qui existe !");
#ifdef _WIN32
      system("PAUSE");
#elif __linux__
      std::cin.get();
#endif
      break;
    }
}

void        MainMenuState::update()
{
  this->printMenu();
  this->updateMenu();
}
