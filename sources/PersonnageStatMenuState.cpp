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
        << this->personnage->getMenuBar()
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
    switch (this->getChoice())
        {
            case 1:
                if (!this->personnage->addStatsPoints(FORCE))
                {
                    std::cout << gui::msgErreur("Vous avec deja assigner tout vos points de competences.");
                    system("PAUSE");
                }
                break;
            case 2:
                if (!this->personnage->addStatsPoints(VITALITE))
                {
                    std::cout << gui::msgErreur("Vous avec deja assigner tout vos points de competences.");
                    system("PAUSE");
                }
                break;
            case 3:
                if (!this->personnage->addStatsPoints(AGILITE))
                {
                    std::cout << gui::msgErreur("Vous avec deja assigner tout vos points de competences.");
                    system("PAUSE");
                }
                break;
            case 4:
                if (!this->personnage->addStatsPoints(DEXTERITE))
                {
                    std::cout << gui::msgErreur("Vous avec deja assigner tout vos points de competences.");
                    system("PAUSE");
                }
                break;
            case 5:
                if(!this->personnage->addStatsPoints(INTELLIGENCE))
                    std::cout << gui::msgErreur("Vous avec deja assigner tout vos points de competences.");
                break;
            case 6:
                this->setQuit(true);
                break;
            default:
                std::cout << gui::msgErreur("Ce choix n'est pas possible. Desole.");
                break;
        }
}

void        PersonnageStatMenuState::update()
{
    this->printMenu();
    this->updateMenu();
}