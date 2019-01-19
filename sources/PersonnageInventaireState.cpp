/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PersonnageInventaireState.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thormster <thormster.renard@outlook.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 18:52:17 by thormster         #+#    #+#             */
/*   Updated: 2019/01/18 18:52:17 by thormster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../headers/PersonnageInventaireState.hpp"

PersonnageInventaireState::PersonnageInventaireState(Personnage*& personnage, std::stack<Stats*>*etat) : personnage(personnage), Stats()
{
    this->etat = etat;
}

PersonnageInventaireState::~PersonnageInventaireState()
{}

void         PersonnageInventaireState::PrintMenu() const
{
#ifdef _WIN32
  system("CLS");
#elif __linux__
  system("clear");
#endif
  std::cout
    << gui::msgMenuTitre("Menu de l'inventaire")
    << this->personnage->getMenuBar(false)
    << gui::msgMenuDiviseur(40, '-')
    << gui::msgMenuItem(10, 1, "Voir l'inventaire")
    << gui::msgMenuItem(10, 2, "Equiper un objet")
    << gui::msgMenuItem(10, 3, "Jeter un objet")
    << gui::msgMenuItem(10, 4, "Retour au menu precedent")
    << gui::msgMenuDiviseur(40, '-');
}

void        PersonnageInventaireState::updateMenu()
{
  switch (this->getChoice())
    {
        case 0:
            std::cout << this->personnage->getInventaire().toString() << std::endl;
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
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

void        PersonnageInventaireState::update()
{
  this->PrintMenu();
  this->updateMenu();
}