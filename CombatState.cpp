/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CombatState.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thormster <thormster.renard@outlook.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 12:46:15 by thormster         #+#    #+#             */
/*   Updated: 2018/12/08 12:46:15 by thormster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "CombatState.hpp"

CombatState::CombatState(Personnage*& personnage, std::stack<Stats*>*etat) : personnage(personnage), Stats()
{
    this->etat = etat;
}

CombatState::~CombatState()
{}

void        CombatState::debutCombat()
{
    Ennemi ennemi(this->personnage->getLevel());
    bool endCombat;
    int tour;
    int round;

    endCombat = false;
    tour = rand() % 2;
    round = 0;
    srand(time(NULL));
    while (!endCombat)
    {
        std::string attStr = this->personnage->getNom();
        std::string defStr = "Ennemi";
        float chanceToucher = static_cast<float>(this->personnage->getChanceToucher());
        float defense = static_cast<float>(ennemi.getDefense());
        
        if (!tour)
        {
            attStr = "Ennemi";
            defStr = this->personnage->getNom();
            chanceToucher = static_cast<float>(ennemi.getChanceToucher());
            defense = static_cast<float>(this->personnage->getDefense());
        }

        float totalHitDef = chanceToucher + defense;
        float HitPercent = 100.f * (chanceToucher / totalHitDef);
        float defPercent = 100.f * (defense / totalHitDef);

        int random = rand() % 100 + 1;

        system("CLS");
        std::cout << "--------------------------------------------------------------------" << std::endl;
        std::cout << "  Attaquant : " << attStr << "    Points de vie : " << this->personnage->getPV() << " / " << this->personnage->getPVMax() << "." << std::endl;
        std::cout << "  Defenseur : " << defStr << "    Points de vie : " << ennemi.getPV() << " / " << ennemi.getPVMax() << "." << std::endl;
        std::cout << "       Tour : " << ++round << std::endl;
        std::cout << "--------------------------------------------------------------------" << std::endl;

        if (random > 0 && random <= HitPercent)
        {
            int degats;
            
            degats = 0;
            if (tour)
            {
                degats = rand() % (this->personnage->getDegatsMax() + this->personnage->getDegatsMin());
                ennemi.takeDegats(degats);
            }
            else
            {
                degats = rand() % (ennemi.getDegatsMax() + ennemi.getDegatsMin());
                this->personnage->takeDegats(degats);
            }
            std::cout << attStr << " a inflige "
            << degats << " a " << defStr << std::endl;
        }
        else
        {
            std::cout << "Vous avez manque votre coups !" << std::endl;
        }

        std::cout << "--------------------------------------------------------------------" << std::endl;
        std::cout << "  Chance de victoire : " << totalHitDef << std::endl;
        std::cout << "  Chance de toucher l'ennemi : " << chanceToucher << "   Pourcentage d'attaque  : " << HitPercent << std::endl;
        std::cout << "  Chance de  parer  l'ennemi : " << defense << "   Pourcentage de defense : " << defPercent << std::endl;
        std::cout << "  Potentiel de degats sur " << attStr << " : " << this->personnage->getDegatsMin() << " - " << this->personnage->getDegatsMax() << std::endl;
        std::cout << "  Potentiel de degats sur " << defStr << " : " << ennemi.getDegatsMin() << " - " << ennemi.getDegatsMax() << std::endl;
        std::cout << "--------------------------------------------------------------------" << std::endl;


        if (this->personnage->isDead())
        {
            endCombat = true;
            std::cout << "YOU DIED ! .... Hum pardon .... vous etes mort en faite. Voila... Desole." << std::endl;
            std::cout << "Ah et.. comment dire.. vous avez perdu de l'experience et de l'argent." << std::endl;
            std::cout << "Vous vous demandez peut-etre pourquoi, non ?" << std::endl;
            std::cout << "Et bien dites vous qu'un enterrement, ca n'est pas gratuit !" << std::endl;
        }
        else if (ennemi.isDead())
        {
            endCombat = true;
            int expGagne = rand() % (ennemi.getLevel() * 10) + 1;
            this->personnage->addExp(expGagne);
            std::cout << "Vous avez battu " << defStr << " !" << std::endl;
            std::cout << "Et vous avez gagne " << expGagne << " points d'experience." << std::endl;
        }

        tour = tour ? false : true;

        system("PAUSE");
    }
}

void        CombatState::runAway()
{

}

void        CombatState::printMenu()
{
    system("CLS");
    std::cout << "--- Menu de Combat ---" << std::endl;
    std::cout << this->personnage->getMenuBar() << "\n" << "\n";
    std::cout << " (1) Engager le combat" << std::endl;
    std::cout << " (2) Fuir le combat" << std::endl;
    std::cout << " (3) Se soigner" << std::endl;
    std::cout << " (4) Retour au menu precedent" << std::endl;
}

void        CombatState::update()
{
    this->printMenu();
    this->updateMenu();
}

void        CombatState::updateMenu()
{
    switch (this->getChoice())
        {
            case 1:
                this->debutCombat();
                std::cout << "Fin du combat" << std::endl;
                system("PAUSE");
                break;
            case 2:
                this->runAway();
                break;
            case 3:
                system("CLS");
                this->personnage->reset();
                std::cout << "Vous avez ete soigne, vous avez recupere toute votre sante." << std::endl;
                system("PAUSE");
                break;
            case 4:
                this->setQuit(true);
                break;
            default:
                system("CLS");
                system("PAUSE");
                break;
        }
}