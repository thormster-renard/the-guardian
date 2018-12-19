/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Personnage.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thormster <thormster.renard@outlook.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:54:45 by thormster         #+#    #+#             */
/*   Updated: 2018/11/13 14:54:45 by thormster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "Personnage.hpp"

Personnage::Personnage(std::string nom, std::string bio)
{
    //Initialisation des attributs && core
    this->nom = nom;
    this->bio = bio;
    this->premierLache = true;
    this->niveau = 1;
    this->experience = 99;
    this->experience_suivante = 100;
    this->gold = 20;
    this->statpoints = 0;

    this->force = 1;
    this->vitalite = 1;
    this->agilite = 1;
    this->dexterite = 1;
    this->intelligence = 1;
    this->x = 0;
    this->y = 0;
    this->updateStats();
    //TEST AJOUT OBJET INVENTAIRE
    this->inventaire.add(Item("Test", 0, 1, 200));
    // fin test
}

Personnage::~Personnage()
{

}

void        Personnage::updateStats()
{
    this->pvMax = this->vitalite * 10 + this->vitalite;
    this->pv = this->pvMax;
    this->staminaMax = this->vitalite * 2;
    this->stamina = this->staminaMax;
    this->manaMax = this->vitalite * 10 + this->vitalite;
    this->mana = this->manaMax;
    this->degatsMin = this->force * 2;
    this->degatsMax = this->force + this->force * 2;
    this->defense = this->agilite * 2;
    this->chance_toucher = this->dexterite * 2 + this->dexterite;
    this->chance_critique = static_cast<float>(this->dexterite / 60);
    this->trouvailles_magiques = static_cast<float>(this->intelligence / 70);
}

const std::string Personnage::toString()
{
    std::stringstream sg;

    sg  << " Nom : " << this->nom << "\n" << "\n"
        << " Bio : " << this->bio << "\n" << "\n"
        << " Argent : " << this->gold << "\n"
        << " Niveau : " << this->niveau << "\n"
        << " Experience : " << this->experience << " / " << this->experience_suivante << "\n"
        << "\n"
        << " Points de vie : " << this->pv << " / " << this->pvMax << "\n"
        << " Stamina : " << this->stamina << " / " << this->staminaMax << "\n"
        << " Mana : " << this->mana << " / " << this->manaMax << "\n"
        << "\n"
        << " Force :" << this->force << "\n"
        << " Vitalite :" << this->vitalite << "\n"
        << " Agilite :" << this->agilite << "\n"
        << " Dexterite :" << this->dexterite << "\n"
        << " Intelligence :" << this->intelligence << "\n"
        << "\n"
        << " Degats infliges : " << this->degatsMin << " - " << this->degatsMax << " (Min-Max)" << "\n"
        << " Defense : " << this->defense << "\n"
        << " Attaque : " << this->chance_toucher << "\n"
        << " Critique : " << this->chance_critique << "\n"
        << " Chance de trouver des Objets Magiques : " << this->trouvailles_magiques << "\n"
        << "\n";
    return (sg.str());
}

std::string       Personnage::getNom()
{
    return (this->nom);
}

const std::string Personnage::getMenuBar()
{
    std::stringstream ss;
    int expFait;
    int expRest;//Experience a acquerir pour +1 niveau

    expFait = 10 * (static_cast<float>(this->experience) / this->experience_suivante);
    expRest = 10 - expFait;
    ss << " Nom: " << this->nom << " | "
        << " Niveau: " << this->niveau << " "
        << "[" << std::string(expFait, '=') << std::string(expRest, '-') << "]" << " | "
        << " Points de vie: " << this->pv << " / " << this->pvMax << " | "
        << " Stamina : " << this->stamina << " / " << this->staminaMax << "\n"
        << " Points SPECIAL disponible: " << this->statpoints;
    return (ss.str());
}

const std::string Personnage::toStringNameBio()
{
    std::stringstream ss;

    ss  << " Nom : " << this->nom << "\n"
        << " Bio : " << this->bio << "\n" << "\n"
        << " Niveau : " << this->niveau << "\n"
        << " Argent : " << this->gold << "\n";
    return (ss.str());
}

const std::string Personnage::toStringStats()
{
    std::stringstream ss;

    ss  << " Niveau : " << this->niveau << "\n"
        << " Experience : " << this->experience << " / " << this->experience_suivante << "\n"
        << " Points de vie : " << this->pv << " / " << this->pvMax << "\n"
        << " Argent : " << this->gold << "\n"
        << " Stamina : " << this->stamina << " / " << this->staminaMax << "\n"
        << " Mana : " << this->mana << " / " << this->manaMax << "\n"
        << "\n"
        << " Force : " << this->force << "\n"
        << " Vitalite : " << this->vitalite << "\n"
        << " Agilite : " << this->agilite << "\n"
        << " Dexterite : " << this->dexterite << "\n"
        << " Intelligence : " << this->intelligence << "\n"
        << "\n"
        << " Degats infliges : " << this->degatsMin << " - " << this->degatsMax << " (Min-Max)" << "\n"
        << " Defense : " << this->defense << "\n"
        << " Attaque : " << this->chance_toucher << "\n"
        << " Critique : " << this->chance_critique << "\n"
        << " Chance de trouver des Objets Magiques : " << this->trouvailles_magiques << "\n";
    return (ss.str());
}

const std::string Personnage::toStringPosition()
{
    std::stringstream ss;

    ss << "X(" << this->x << ") | Y(" << this->y << ")" << std::endl;
    return (ss.str());
}

bool        Personnage::canLevelUp()
{
   if (this->experience >= this->experience_suivante)
   {
        this->niveau += 1;
        this->experience -= this->experience_suivante;
        this->experience_suivante = (50 / 3) * (pow(this->niveau, 3)) - 6 * pow(this->niveau, 2) + (this->niveau * 17) - 12;
        this->statpoints += 1;
        this->pvMax += 1;
        return (true);
   }
   return (false);
}

void        Personnage::addExp(const unsigned experience)
{
    this->experience += experience;
}

const std::string         Personnage::runAway()
{
    std::stringstream ss;
    int     lostGold;
    int     lostXP;

    if (this->premierLache)
    {
        std::cout << "Comme c'est la premiere fois que vous fuiez un combat "
        << "nous n'avons rien perdu, mais rappelez vous que la prochaine fois "
        << "vous y laisserez de l'or et de l'experience." << std::endl;
        system("PAUSE");
    }
    else
    {
        this->premierLache = false;
        std::cout << "Vous fuiez le combat." << std::endl;
        lostXP = rand() % (this->niveau * 5) + 1;
        lostGold = rand() % (this->niveau * 5) + 1;;
        ss << "Vous avez perdu " << lostXP << " et " << lostGold;
        this->experience -= lostXP;
        if (this->experience < 0)
            this->experience = 0;
        this->gold -= lostGold;
        if (this->gold < 0)
            this->gold = 0;
    }
    return (ss.str());
}

void        Personnage::reset()
{
    this->pv = this->pvMax;
    this->stamina = this->staminaMax;
    this->mana = this->manaMax;
}

void        Personnage::takeDegats(const int degats)
{
    this->pv -= degats;
    if (this->pv <= 0)
        this->setDead();
}

void        Personnage::setDead()
{
    this->pv = 0;

    this->experience -= rand() % (this->niveau * 10) + 1;
    if (this->experience < 0)
        this->experience = 0;

    this->gold -= rand() % (this->niveau * 10) + 1;
    if (this->gold < 0)
        this->gold = 0;
}

void        Personnage::setPosition(const unsigned x, const unsigned y)
{
    this->x = x;
    this->y = y;
}

void        Personnage::move(const int x, const int y)
{
    if (static_cast<int>(this->x)+ x < 0)
        this->x = 0;
    else
        this->x += x;

    if (static_cast<int>(this->y)+ y < 0)
        this->y = 0;
    else
        this->y += y;
}
