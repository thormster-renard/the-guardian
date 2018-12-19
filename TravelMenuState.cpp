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
    this->nbLieux = 5;
    this->updateEncounterMenu();
}

TravelMenuState::~TravelMenuState()
{}

void        TravelMenuState::update()
{
    
    this->updateMiniMap();
    this->printMenu();
    this->updateMenu();
    this->updateEncounterMenu();
}

void        TravelMenuState::printMenu()
{
    system("CLS");
    std::cout
        << gui::msgMenuTitre("Menu de voyage")
        << this->personnage->getMenuBar() << "\n" << "\n"
        << std::string(4, ' ') << "Lieu: " << this->locationString << "\n"
        << std::string(4, ' ') << this->personnage->toStringPosition() << "\n"
        << std::string(35, ' ') << "Mini carte:"<< "\n"
        << std::string(30, ' ') << this->miniMapString << "\n"
        << gui::msgMenuDiviseur(40, '-')
        << gui::msgMenuItem(8, "HAUT")
        << gui::msgMenuItem(2, "BAS")
        << gui::msgMenuItem(4, "GAUCHE")
        << gui::msgMenuItem(6, "DROITE")
        << gui::msgMenuItem(5, "Quitter le menu")
        << gui::msgMenuDiviseur(40, '-');
}

void        TravelMenuState::updateMenu()
{
    switch (this->getChoice())
        {
            case 8:
                this->personnage->move(0, -1);
                break;
            case 2:
                this->personnage->move(0, 1);
                break;
            case 4:
                this->personnage->move(-1, 0);
                break;
            case 6:
                this->personnage->move(1, 0);
                break;
            case 5:
                this->setQuit(true);
                break;
            default:
                system("CLS");
                std::cout << gui::msgErreur("Cette direction est invalide.");
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
                ss << "Joueur  ";
            else
            {
                switch (location)
                {
                    case FORET:
                        ss << "Foret  ";
                        break;
                    case FERME:
                        ss << "Ferme  ";
                        break;
                    case BOURG:
                        ss << "Bourg  ";
                        break;
                    case SHOP:
                        ss << "Shops  ";
                        break;
                    case BANKS:
                        ss << "Banks  ";
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
    int     random;

    if (!this->getQuit())
    {
        srand(this->personnage->getSeed());
        location = rand() % this->nbLieux;
        switch (location)
        {
            case EMPTY:
                this->locationString = "Il n'y a rien ici, continuons !";
                random = rand() % 2;
                if (random)
                {
                    system("CLS");
                    std::cout << "Ennemi en vue ! A l'attaque !!" << "\n" << "\n";
                    system("PAUSE");
                    this->etat->push(new CombatState(this->personnage, this->etat));
                }
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
            case CHEST:
                this->locationString = "Je n'aime pas beaucoup les BANQUES, mais elles protegeront vos richesses. Votre coffre est par ici.";
                break;
            default:
                this->locationString = "Halte ! Ce sont des MARECAGES, nous risquerions de nous perdre ou pire encore.";
                break;
        }
    }
}