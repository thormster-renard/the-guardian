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
                this->etat->push(new PersonnageStatMenuState(this->personnage, this->etat));
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