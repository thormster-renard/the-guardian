/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PersonnageStatMenuState.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thormster <thormster.renard@outlook.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 21:58:32 by thormster         #+#    #+#             */
/*   Updated: 2018/12/19 21:58:32 by thormster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include        "../headers/PersonnageStatMenuState.hpp"

PersonnageStatMenuState::PersonnageStatMenuState(Personnage*& personnage, std::stack<Stats*>*etat) : personnage(personnage), Stats()
{
    this->etat = etat;
}

PersonnageStatMenuState::~PersonnageStatMenuState()
{
}

void        PersonnageStatMenuState::printMenu()
{
    system("CLS");
    std::cout
        << gui::msgMenuTitre("Assigner vos points de competences")
        << this->personnage->getMenuBar(true)
        << gui::msgMenuDiviseur(40, '-')
        << " (" << this->personnage->getAttribut(FORCE) << ") " << gui::msgMenuItem(10, 1, "Force")
        << " (" << this->personnage->getAttribut(VITALITE) << ") " << gui::msgMenuItem(10, 2, "Vitalite")
        << " (" << this->personnage->getAttribut(AGILITE) << ") " << gui::msgMenuItem(10, 3, "Agilite")
        << " (" << this->personnage->getAttribut(DEXTERITE) << ") " << gui::msgMenuItem(10, 4, "Dexterite")
        << " (" << this->personnage->getAttribut(INTELLIGENCE) << ") " << gui::msgMenuItem(10, 5, "Intelligence")
        << gui::msgMenuItem(15, 6, "Retour au menu precedent")
        << gui::msgMenuDiviseur(40, '-');
}

void        PersonnageStatMenuState::updateMenu()
{
    int     choice;

    choice = this->getChoice();
    if (choice == 6)
    {
        this->setQuit(true);
    }
    else if (choice > 0 && choice < 6)
    {
        if (!this->personnage->addStatsPoints(choice - 1))
            std::cout << gui::msgErreur("Vous avec deja assigner tout vos points de competences.");
    }
    else
    {
        system("PAUSE");
        std::cout << gui::msgErreur("Vous avec deja assigner tout vos points de competences.");
        system("PAUSE");
    }
}

void        PersonnageStatMenuState::update()
{
    this->printMenu();
    this->updateMenu();
}