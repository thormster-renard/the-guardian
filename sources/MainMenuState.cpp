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

#include    "../headers/MainMenuState.hpp"

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
    std::cout << gui::msgMenuTitre("Menu principal");
    if (!this->listePersonnage->empty())
        std::cout << this->listePersonnage->at(this->personnageActif)->getMenuBar() << std::endl;
    else
        std::cout << gui::msgErreur("Pour debuter le jeu, creez un personnage");
    std::cout
    << gui::msgMenuDiviseur(40, '-')
    << gui::msgMenuItem(1, "Demarrer un nouveau jeu")
    << gui::msgMenuItem(2, "Creer votre personnage")
    << gui::msgMenuItem(3, "Choisir votre personnage")
    << gui::msgMenuItem(4, "Quitter le jeu")
    << gui::msgMenuDiviseur(40, '-');
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
                std::cout << gui::msgErreur("Pour jouer, vous devez d'abord creer, un nouveau personnage.");
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
            std::cout << gui::msgErreur("Vous devez faire un choix qui.. et bien qui existe !");
            system("PAUSE");
            break;
    }
}

void        MainMenuState::update()
{
     this->printMenu();
     this->updateMenu();
}