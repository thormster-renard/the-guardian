/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TravelMenuState.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thormster <thormster.renard@outlook.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 18:22:45 by thormster         #+#    #+#             */
/*   Updated: 2018/11/30 18:22:45 by thormster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "TravelMenuState.hpp"

TravelMenuState::TravelMenuState(Personnage*& personnage, std::stack<Stats*>*etat) : personnage(personnage), Stats()
{
    this->etat = etat;
    this->locationString = "INCONNU";
    this->nbLieux = 6;
}

TravelMenuState::~TravelMenuState()
{}

void        TravelMenuState::update()
{
    this->updateEncounterMenu();
    this->updateMiniMap();
    this->printMenu();
    this->updateMenu();
}

void        TravelMenuState::printMenu()
{
    system("CLS");
    std::cout << "--- Menu de voyage ---" << "\n"
    << "\n"
    << this->personnage->getMenuBar() << "\n"
    << "\n"
    << "Lieu: " << this->locationString << "\n"
    << this->personnage->toStringPosition() << "\n"
    << "Mini carte:    #(vide) F(ferme) V(ville) M(magasin) E(ennemi) T(tresor) "<< "\n"
    << this->miniMapString << "\n"
    << " (1) HAUT" << "\n"
    << " (2) BAS" << "\n"
    << " (3) GAUCHE" << "\n"
    << " (4) DROITE" << "\n"
    << " (5) Quitter le menu" << "\n"
    << "\n";
}

void        TravelMenuState::updateMenu()
{
    switch (this->getChoice())
        {
            case 1:
                this->personnage->move(0, -1);
                break;
            case 2:
                this->personnage->move(0, 1);
                break;
            case 3:
                this->personnage->move(-1, 0);
                break;
            case 4:
                this->personnage->move(1, 0);
                break;
            case 5:
                this->setQuit(true);
                break;
            default:
                system("CLS");
                std::cout << "Cette direction est invalide" << std::endl;
                system("PAUSE");
                break;
        }
}

void        TravelMenuState::updateMiniMap()
{
    int startX = this->personnage->getX() - 2;
    if (startX < 0)
        startX = 0;
    int startY = this->personnage->getY() - 2;
    if (startY < 0)
        startY = 0;
    int endX = this->personnage->getX() + 2;
    int endY = this->personnage->getY() + 2;
    std::stringstream ss;

    for (size_t y = startY; y <= endY; y++)
    {
        for (size_t x = startX; x <= endX; x++)
        {
            srand(x + y);
            int location = rand() % this->nbLieux;
            if (x == this->personnage->getX() && y == this->personnage->getY())
                ss << "P ";
            else
            {
                switch (location)
                {
                    case EMPTY:
                        ss << "# ";
                        break;
                    case FARM:
                        ss << "F ";
                        break;
                    case CITY:
                        ss << "V ";
                        break;
                    case SHOP:
                        ss << "M ";
                        break;
                    case ENEMY:
                        ss << "E ";
                        break;
                    case CHEST:
                        ss << "T ";
                        break;
                }
            }
        }
        ss << "\n";
    }
    this->miniMapString = ss.str();
}

void        TravelMenuState::updateEncounterMenu()
{
    int     location;

    srand(this->personnage->getSeed());
    location = rand() % this->nbLieux;
    switch (location)
    {
        case EMPTY:
            this->locationString = "Il n'y a rien ici, continuons !";
            break;
        case FARM:
            this->locationString = "C'est une FERME, allons voir de plus pres";
            break;
        case CITY:
            this->locationString = "Bienvenue a CITY ! La plus grande ville de la region.";
            break;
        case SHOP:
            this->locationString = "Bienvenue au doux barbare ! Le meilleur MAGASIN de tout l'Entreterre !";
            break;
        case ENEMY:
            this->locationString = "Nous devrions etre prudents, il y a des ENNEMIS par ici.";
            break;
        case CHEST:
            this->locationString = "Je n'aime pas beaucoup les BANQUES, mais elles protegeront vos richesses. Votre coffre est par ici.";
            break;
        default:
            this->locationString = "Halte ! Ce sont des MARECAGES, nous risquerions de nous perdre ou pire encore.";
            break;
    }
}