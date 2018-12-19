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
        << gui::msgMenuTitre("Menu principal")
        << this->personnage->getMenuBar() << "\n" << "\n"
        << gui::msgMenuDiviseur(40, '-')
        << gui::msgMenuItem(1, "Menu du personnage")
        << gui::msgMenuItem(2, "Carte")
        << gui::msgMenuItem(3, "Artisan")
        << gui::msgMenuItem(4, "Se reposer")
        << gui::msgMenuItem(5, "Retour au menu precedent")
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
            system("CLS");
            this->personnage->reset();
            std::cout << "Vous vous reposez..." << std::endl;
            system("PAUSE");
            break;
        case 5:
            this->setQuit(true);
            break;
        default:
            system("CLS");
            std::cout << "Vous devez faire un choix qui.. et bien qui existe !" << std::endl;
            system("PAUSE");
            break;
    }
}