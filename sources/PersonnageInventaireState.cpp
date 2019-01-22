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
        case 1:
#ifdef _WIN32
            system("CLS");
            //std::cout << this->personnage->toStringEquipe() << std::endl;
            std::cout << this->personnage->getInventaire().toString() << std::endl;
            system("PAUSE");
            break;
#elif __linux__
            system("clear");
            //std::cout << this->personnage->toStringEquipe() << std::endl;
            std::cout << this->personnage->getInventaire().toString() << std::endl;
            std::cin.get();
            break;
#endif
        case 2:
        {
#ifdef _WIN32
            system("CLS");
#elif __linux__
            system("clear");
#endif
            //std::cout << this->personnage->toStringEquipe() << std::endl;
            std::cout << this->personnage->getInventaire().toString() << std::endl;
            int choice = this->getChoice();
            if (choice < 0 || choice >= this->personnage->getInventaire().size( ))
                std::cout << gui::msgErreur("Aucun objet de ce genre dans l'item");
            else
            {
                Weapon *wep = dynamic_cast<Weapon*>(this->personnage->getInventaire().replace(choice, this->personnage->getWeapon()));
                if (wep)
                    this->personnage->setWeapon(wep);
            }
#ifdef _WIN32
            system("PAUSE");
#elif __linux__
            std::cin.get();
#endif

            break;
        }
        case 3:
            break;
        case 4:
            this->setQuit(true);
            break;
        default:
#ifdef _WIN32
            system("CLS");
            std::cout << gui::msgErreur("Vous devez faire un choix qui.. et bien qui existe !");
            system("PAUSE");
            break;
#elif __linux__
            system("clear");
            std::cout << gui::msgErreur("Vous devez faire un choix qui.. et bien qui existe !");
            std::cin.get();
            break;
#endif
    }
}

void        PersonnageInventaireState::update()
{
  this->PrintMenu();
  this->updateMenu();
}