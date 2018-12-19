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

#include    "GameState.hpp"

GameState::GameState(Personnage*& personnage, std::stack<Stats*>*etat) : personnage(personnage), Stats()
{
    this->etat = etat;
}

GameState::~GameState()
{}

void        GameState::update()
{
    this->PrintMenu();
    this->updateMenu();
}

void         GameState::PrintMenu() const
{
    system("CLS");
    std::cout
        << msgMenuTitre("Menu principal")
        << this->personnage->getMenuBar() << "\n" << "\n"
        << msgMenuItem(1, "Menu du personnage")
        << msgMenuItem(2, "Carte")
        << msgMenuItem(3, "Artisan")
        << msgMenuItem(4, "Se reposer")
        << msgMenuItem(5, "Retour au menu precedent");
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
            system("CLS");
            this->personnage->reset();
            std::cout << "Vous vous reposez..." << std::endl;
            system("PAUSE");
            break;
        case 5:
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