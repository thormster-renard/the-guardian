/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PersonnageCreatorState.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thormster <thormster.renard@outlook.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:30:50 by thormster         #+#    #+#             */
/*   Updated: 2018/11/17 18:30:50 by thormster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include        "../headers/PersonnageCreatorState.hpp"

PersonnageCreatorState::PersonnageCreatorState(std::vector<Personnage*>*listePersonnage, unsigned& personnageActif, std::stack<Stats*>*etat) : personnageActif(personnageActif), Stats(), maxPersonnages(5)
{
    this->listePersonnage = listePersonnage;
    this->etat = etat;
}

PersonnageCreatorState::~PersonnageCreatorState()
{

}

void            PersonnageCreatorState::update()
{
    this->printMenu();
    this->updateMenu();
}

void            PersonnageCreatorState::creerPersonnage()
{
    std::string nom;
    std::string bio;

    if (this->listePersonnage->size() < this->maxPersonnages)
    {
        nom = "";
        bio = "";
        std::cout << "Quel est le nom de votre personnage ?" << "\n" << "\n";
        getline(std::cin, nom);
        if (nom.empty())
        {
            std::cout << "Il me faut un nom, pour le registre. Je vais vous en donner un... Aller Billy ca sera tres bien" << "\n" << "\n" << "\n" << "\n";
            nom = "Billy";
        }
        std::cout << "\n" << "\n";
        std::cout << "Quel est le titre de votre personnage ?" << "\n" << "\n";
        std::cout << nom << " le lepreux, le benet ?" << "\n" << "\n";
        getline(std::cin, bio);
        this->listePersonnage->push_back(new Personnage(nom, bio));
        std::cout << "Bienvenue dans The Black Guardian !" << std::endl;
    }
    else
        std::cout << gui::msgErreur("Veuillez nous excuser, mais nous ne pouvons accueillir plus de 5 personnes.");
}

void            PersonnageCreatorState::printMenu()
{
    system("CLS");
    std::cout << gui::msgMenuTitre("Creation de votre nouveau personnage")
    << "      Personnages crees : " << std::to_string(this->listePersonnage->size()) << " / " << std::to_string(this->maxPersonnages)
    << "\n"
    << gui::msgMenuDiviseur(40, '-')
    << gui::msgMenuItem(1, "Creer votre personnage")
    << gui::msgMenuItem(2, "Retour au menu precedent")
    << gui::msgMenuDiviseur(40, '-');
}

void            PersonnageCreatorState::updateMenu()
{
    switch (this->getChoice() | system("CLS"))
        {
            case 1:
                system("CLS");
                this->creerPersonnage();
                system("PAUSE");
                break;
            case 2:
                this->setQuit(true);
                break;
            default:
                system("CLS");
                std::cout << gui::msgErreur("Excusez-moi, mais..vous devez faire un choix qui.. et bien qui existe !");
                system("PAUSE");
                break;
        }
}