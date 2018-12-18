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
    system("PAUSE");
    system("CLS");
    std::cout << std::setw(8) << "--- MENU PRINCIPAL ---" << std::endl;
    if (!this->listePersonnage->empty())
        std::cout << this->listePersonnage->at(this->personnageActif)->getMenuBar() << std::endl;
    else
        std::cout << "Veuillez choisir un personnage." << std::endl;
    std::cout << " (1) Demarrer un nouveau jeu" << std::endl;
    std::cout << " (2) Creer votre personnage" << std::endl;
    std::cout << " (3) Choisir votre personnage" << std::endl;
    std::cout << " (4) Quitter le jeu" << std::endl;
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
                std::cout << "Pour jouer, vous devez d'abord creer, un nouveau personnage."<< std::endl;
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
            std::cout << "Vous devez faire un choix qui.. et bien qui existe !" << std::endl;
            system("PAUSE");
            break;
    }
}

void        MainMenuState::update()
{
     this->printMenu();
     this->updateMenu();
}