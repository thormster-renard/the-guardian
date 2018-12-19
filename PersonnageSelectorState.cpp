/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PersonnageSelectorState.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thormster <thormster.renard@outlook.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 21:50:12 by thormster         #+#    #+#             */
/*   Updated: 2018/11/29 21:50:12 by thormster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "PersonnageSelectorState.hpp"

PersonnageSelectorState::PersonnageSelectorState(std::vector<Personnage*>*listePersonnage, unsigned& personnageActif, std::stack<Stats*>*etat) : Stats(), listePersonnage(listePersonnage), personnageActif(personnageActif), etat(etat)
{}

PersonnageSelectorState::~PersonnageSelectorState()
{}

void    PersonnageSelectorState::printMenu()
{
    int i;

    i = 1;
    system("CLS");
    std::cout
        << msgMenuTitre("Selection du personnage")
        << msgMenuItem(1, "Menu precedent");
    if (!this->listePersonnage->empty())
    {
        while (i < this->listePersonnage->size())
        {
            std::cout << " (" << i << ") " << this->listePersonnage->at(i)->getMenuBar() << std::endl;
            i += 1;
        }
        std::cout << "\n";
    } 
}

void    PersonnageSelectorState::updateMenu()
{
    int choice;

    if (!this->listePersonnage->empty())
    {
        choice = this->getChoice();
        if (choice < 0)
        {
            this->setQuit(true);
        }
        else if (choice >= 0 && choice < this->listePersonnage->size())
        {
            this->personnageActif = choice;
            this->setQuit(true);
            std::cout << "Personnage " << choice << " selectionne." << std::endl;
            system("PAUSE");
        }
        else
        {
            std::cout << "Hum, ce personnage n'existe pas." << std::endl;
            system("PAUSE");
        }
    }
    else
    {
        this->setQuit(true);
        std::cout << "Aucun personnage n'a encore ete cree." << std::endl;
        system("PAUSE");
    }  
}

void        PersonnageSelectorState::update()
{
     this->printMenu();
     this->updateMenu();
}