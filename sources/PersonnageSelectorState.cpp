/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PersonnageSelectorState.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thormster <thormster.renard@outlook.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 21:50:12 by thormster         #+#    #+#             */
/*   Updated: 2018/11/29 21:50:12 by thormster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../headers/PersonnageSelectorState.hpp"

PersonnageSelectorState::PersonnageSelectorState(std::vector<Personnage*>*listePersonnage, unsigned& personnageActif, std::stack<Stats*>*etat) : Stats(), listePersonnage(listePersonnage), personnageActif(personnageActif), etat(etat)
{}

PersonnageSelectorState::~PersonnageSelectorState()
{}

void    PersonnageSelectorState::printMenu()
{
  int i;

  i = 0;
#ifdef _WIN32
  system("CLS");
#elif __linux__
  system("clear");
#endif
  std::cout
    << gui::msgMenuTitre("Selection du personnage")
    << gui::msgMenuDiviseur(40, '-')
    << gui::msgMenuItem(10, 1, "Menu precedent")
    << gui::msgMenuDiviseur(40, '-');
  if (!this->listePersonnage->empty())
    {
      while (i < this->listePersonnage->size())
        {
	  std::cout << " (" << i << ") " << this->listePersonnage->at(i)->getMenuBar(false) << std::endl;
	  i += 1;
        }
      std::cout << "\n";
    }
}

void    PersonnageSelectorState::updateMenu()
{
  int choice;

  if (!this->listePersonnage->empty())
    {
      choice = this->getChoice();
      if (choice < 0)
	this->setQuit(true);
      else if (choice >= 0 && choice < this->listePersonnage->size())
        {
	  this->personnageActif = choice;
	  this->setQuit(true);
	  std::cout << "Personnage " << choice << " selectionne." << std::endl;
#ifdef _WIN32
	  system("PAUSE");
#elif __linux__
	  std::cin.get();
#endif
        }
      else
        {
	  std::cout << gui::msgErreur("Hum, ce personnage n'existe pas.");
#ifdef _WIN32
	  system("PAUSE");
#elif __linux__
	  std::cin.get();
#endif
        }
    }
  else
    {
      this->setQuit(true);
      std::cout << "Aucun personnage n'a encore ete cree." << std::endl;
#ifdef _WIN32
      system("PAUSE");
#elif __linux__
      std::cin.get();
#endif
    }  
}

void        PersonnageSelectorState::update()
{
  this->printMenu();
  this->updateMenu();
}
