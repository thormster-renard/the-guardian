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

#include    "PersonnageMenuState.hpp"

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
        << msgMenuTitre("Menu du personnage")
        << this->personnage->getMenuBar()
        << msgMenuItem(1, "Nom et Biographie")
        << msgMenuItem(2, "Statistiques")
        << msgMenuItem(3, "Assigner les points d'experience")
        << msgMenuItem(4, "Augmenter un niveau")
        << msgMenuItem(5, "Inventaire")
        << msgMenuItem(6, "Quitter le menu");
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
                if (this->personnage->canLevelUp())
                {
                    system("CLS");
                    std::cout << "Vous avez gagne un niveau !! Felicitation" << std::endl;
                    system("PAUSE");                    
                }
                else
                {   
                    system("CLS");
                    std::cout << "Faites-vous plus d'experience et revenez nous voir." << std::endl;
                    system("PAUSE");
                }
                system("PAUSE");
                break;
            case 5:
                system("CLS");
                std::cout << this->personnage->getInventaire().toString() << std::endl;
                system("PAUSE");
                break;
            case 6:
                this->setQuit(true);
                break;
            default:
                system("CLS");
                std::cout << "Vous devez faire un choix qui.. et bien qui existe !" << std::endl;
                system("PAUSE");
                break;
        }
}