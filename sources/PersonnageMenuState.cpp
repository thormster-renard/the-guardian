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

PersonnageMenuState::~PersonnageMenuState()
{

}

void        PersonnageMenuState::update()
{
    this->printMenu();
    this->updateMenu();
}

void        PersonnageMenuState::printMenu()
{
    system("CLS");
    std::cout
        << gui::msgMenuTitre("Menu du personnage")
        << this->personnage->getMenuBar() << "\n" << "\n" 
        << gui::msgMenuDiviseur(40, '-')
        << gui::msgMenuItem(1, "Nom et Biographie")
        << gui::msgMenuItem(2, "Statistiques")
        << gui::msgMenuItem(3, "Assigner les points d'experience")
        << gui::msgMenuItem(4, "Inventaire")
        << gui::msgMenuItem(5, "Quitter le menu")
        << gui::msgMenuDiviseur(40, '-');
}



void        PersonnageMenuState::updateMenu()
{
    switch (this->getChoice())
        {
            case 1:
                system("CLS");
                std::cout << this->personnage->toStringNameBio() << std::endl;
                system("PAUSE");
                break;
            case 2:
                system("CLS");
                std::cout << this->personnage->toStringStats() << std::endl;
                system("PAUSE");
                break;
            case 3:
                system("CLS");

                system("PAUSE");
                break;
            case 4:
                system("CLS");
                std::cout << this->personnage->getInventaire().toString() << std::endl;
                system("PAUSE");
                break;
            case 5:
                this->setQuit(true);
                break;
            default:
                system("CLS");
                std::cout << gui::msgErreur("Vous devez faire un choix qui.. et bien qui existe !");
                system("PAUSE");
                break;
        }
}