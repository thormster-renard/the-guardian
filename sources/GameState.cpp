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

#include    "../headers/GameState.hpp"

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
        << gui::msgMenuTitre("Menu du jeu")
        << this->personnage->getMenuBar(false)
        << gui::msgMenuDiviseur(40, '-')
        << gui::msgMenuItem(10, 1, "Menu du personnage")
        << gui::msgMenuItem(10, 2, "Carte")
        << gui::msgMenuItem(10, 3, "Artisan")
        << gui::msgMenuItem(10, 4, "Se reposer")
        << gui::msgMenuItem(10, 5, "Retour au menu precedent")
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