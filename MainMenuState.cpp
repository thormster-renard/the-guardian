/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainMenuState.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thormster <thormster.renard@outlook.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:50:10 by thormster         #+#    #+#             */
/*   Updated: 2018/11/16 18:50:10 by thormster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "MainMenuState.hpp"

MainMenuState::MainMenuState(std::vector<Personnage*>*listePersonnage, unsigned& personnageActif, std::stack<Stats*>*etat) : Stats(), personnageActif(personnageActif) 
{
    this->listePersonnage = listePersonnage;
    this->etat = etat;
    //test
    //this->listePersonnage->push_back(new Personnage("TEST", "DEBUGGING"));
    //end test
}

MainMenuState::~MainMenuState()
{

}

void    MainMenuState::printMenu()
{
    system("CLS");
    std::cout << msgMenuTitre("Menu principal");
    if (!this->listePersonnage->empty())
        std::cout << this->listePersonnage->at(this->personnageActif)->getMenuBar() << std::endl;
    else
        std::cout << msgErreur("Pour debuter le jeu, creez un personnage");
    std::cout
    << msgMenuDiviseur(40, '-')
    << msgMenuItem(1, "Demarrer un nouveau jeu")
    << msgMenuItem(2, "Creer votre personnage")
    << msgMenuItem(3, "Choisir votre personnage")
    << msgMenuItem(4, "Quitter le jeu")
    << msgMenuDiviseur(40, '-');
}

void    MainMenuState::updateMenu()
{
    switch (this->getChoice() | system("CLS"))
    {
        case 1:
            if (!this->listePersonnage->empty())
                this->etat->push(new GameState(this->listePersonnage->at(this->personnageActif), this->etat));
            else
            {
                system("CLS");
                std::cout << "(!) [[ Pour jouer, vous devez d'abord creer, un nouveau personnage ]] "<< std::endl;
                system("PAUSE");
            }
            break;
        case 2:
            this->etat->push(new PersonnageCreatorState(this->listePersonnage, this->personnageActif, this->etat));
            break;
        case 3:
            this->etat->push(new PersonnageSelectorState(this->listePersonnage, this->personnageActif, this->etat));
            break;
        case 4:
            this->setQuit(true);
            break;
        default:
            system("CLS");
            std::cout << "(!) [[ Vous devez faire un choix qui.. et bien qui existe ! ]]" << std::endl;
            system("PAUSE");
            break;
    }
}

void        MainMenuState::update()
{
     this->printMenu();
     this->updateMenu();
}