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

#include    "../headers/Personnage.hpp"

Personnage::Personnage(std::string nom, std::string bio)
{
  //Initialisation des attributs && core
  this->nom = nom;
  this->bio = bio;
  this->premierLache = true;
  this->niveau = 1;
  this->experience = 0;
  this->experience_suivante = 46;
  this->gold = 100;
  this->statpoints = 5;
  this->location = -1;

  this->force = 1;
  this->vitalite = 1;
  this->agilite = 1;
  this->dexterite = 1;
  this->intelligence = 1;
  this->x = 0;
  this->y = 0;

  this->weapon = new Weapon(2, 4, "Epee", 0, 1, 200);

  this->updateStats();
  this->resetPV();

  //TEST AJOUT OBJET INVENTAIRE
  this->inventaire.add(Weapon(5, 10, "Test", WEAPON, COMMON, 200));
  // fin test
}

Personnage::~Personnage()
{
  delete this->weapon;
}

const int   Personnage::getDegatsMin() const
{
  if (this->weapon)
    return (this->degatsMin + this->weapon->getDegatsMin());
  return (this->degatsMin);
}

const int   Personnage::getDegatsMax() const
{
  if (this->weapon)
    return (this->degatsMax + this->weapon->getDegatsMax());
  return (this->degatsMax);
}

const int   Personnage::getAttribut(const unsigned attribut)
{
  switch (attribut)
    {
    case FORCE:
      return (this->force);
      break;
    case VITALITE:
      return (this->vitalite);
      break;
    case AGILITE:
      return (this->agilite);
      break;
    case DEXTERITE:
      return (this->dexterite);
      break;
    case INTELLIGENCE:
      return (this->intelligence);
      break;
    default:
      return (-1);
      break;
    }
  return (0);
}

const int Personnage::getDegatsTotal() const
{
  if (this->weapon)
    return (rand() % ((this->degatsMax + this->weapon->getDegatsMax()) - (this->degatsMin + this->weapon->getDegatsMin())) + (this->degatsMin + this->weapon->getDegatsMin()));
  return (rand() % (this->degatsMax - this->degatsMin) + this->degatsMin);
}

void        Personnage::updateStats()
{
  this->pvMax = this->vitalite * 10 + this->vitalite;
  //this->pv = this->pvMax;
  this->staminaMax = this->vitalite * 2;
  this->stamina = this->staminaMax;
  this->manaMax = this->vitalite * 10 + this->vitalite;
  this->mana = this->manaMax;
  this->degatsMin = this->force * 2;
  this->degatsMax = this->force + this->force * 2;
  if (this->weapon)
    {
      this->degatsMin += this->weapon->getDegatsMin();
      this->degatsMax += this->weapon->getDegatsMax();
    }
  this->defense = this->agilite * 2;
  this->chance_toucher = this->dexterite * 2 + this->dexterite;
  this->chance_critique = static_cast<float>(this->dexterite / 60);
  this->trouvailles_magiques = static_cast<float>(this->intelligence / 70);
}


// Modifieurs
const std::string         Personnage::runAway()
{
  std::stringstream ss;
  int     lostGold;
  int     lostXP;

  if (this->premierLache)
    {
      std::cout
        << "Comme c'est la premiere fois que vous fuiez un combat "
        << "nous n'avons rien perdu, mais rappelez vous que la prochaine fois "
        << "vous y laisserez de l'or et de l'experience."
        << std::endl;
#ifdef _WIN32
      system("PAUSE");
#elif __linux__
      std::cin.get();
#endif
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

void        Personnage::resetPV()
{
  this->pv = this->pvMax;
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

void        Personnage::setLocation(const int location)
{
  this->location = location;
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


// Fonctions
std::string       Personnage::getNom()
{
  return (this->nom);
}

bool        Personnage::addStatsPoints(const unsigned stat)
{
  if (this->statpoints > 0)
    {
      this->statpoints -= 1;
      switch (stat)
        {
	case FORCE:
	  this->force += 1;
	  break;
	case VITALITE:
	  this->vitalite += 1;
	  break;
	case AGILITE:
	  this->agilite += 1;
	  break;
	case DEXTERITE:
	  this->dexterite += 1;
	  break;
	case INTELLIGENCE:
	  this->intelligence += 1;
	  break;
	default:
	  this->statpoints++;
	  return (false);
	  break;
        }
      this->updateStats();
      this->resetPV();
      return (true);
    }
  return (false);
}

bool        Personnage::addExp(const unsigned experience)
{
  bool    niveauSup;

  niveauSup = false;
  this->experience += experience;
  while (this->experience >= this->experience_suivante)
    {
      this->niveau += 1;
      this->experience -= this->experience_suivante;
      this->experience_suivante = (50 / 3) * (pow(this->niveau, 3)) - 6 * pow(this->niveau, 2) + (this->niveau * 17) - 12;
      this->statpoints += 1;
      this->force += this->niveau % 2;
      this->vitalite += this->niveau % 2;
      this->agilite += this->niveau % 2;
      this->dexterite += this->niveau % 2;
      this->intelligence += this->niveau % 2;
      this->pvMax += 1;
      niveauSup = true;
      this->updateStats();
      this->resetPV();
    }
  return (niveauSup);
}

const std::string Personnage::getMenuBar(const bool voirAttributs)
{
  std::stringstream ss;
  int expFait;
  int expRest;//Experience a acquerir pour +1 niveau

  expFait = 10 * (static_cast<float>(this->experience) / this->experience_suivante);
  expRest = 10 - expFait;
  ss
    << std::string(4, ' ') << " | Nom: " << this->nom << "\n"
    << std::string(4, ' ') << " | Niveau: " << this->niveau << " [" << std::string(expFait, '=') << std::string(expRest, '-') << "]" << "\n"
    << std::string(4, ' ') << " | Points de vie: " << this->pv << " / " << this->pvMax << "\n"
    << std::string(4, ' ') << " | Stamina : " << this->stamina << " / " << this->staminaMax << "\n"
    << std::string(4, ' ') << " | Points de competence disponibles: " << this->statpoints;
  if (voirAttributs)
    {
      ss  << "\n"
	  << std::string(4, ' ') << " | Force:        " << this->force << "\n"
	  << std::string(4, ' ') << " | Vitalite:     " << this->vitalite << "\n"
	  << std::string(4, ' ') << " | Agilite:      " << this->agilite << "\n"
	  << std::string(4, ' ') << " | Dexterite:    " << this->dexterite << "\n"
	  << std::string(4, ' ') << " | Intelligence: " << this->intelligence << "\n";
    }
  ss
    << "\n" << "\n";
  return (ss.str());
}

const std::string Personnage::toString()
{
  std::stringstream ss;

  ss  << " Nom : " << this->nom << "\n" << "\n"
      << " Bio : " << this->bio << "\n" << "\n"
      << " Argent : " << this->gold << "\n"
      << " Niveau : " << this->niveau << "\n"
      << " Experience : " << this->experience << " / " << this->experience_suivante << "\n";
  if (this->weapon)
    {
      ss << " Arme  " << this->weapon->toString() << "\n"
	    << "\n"
      << " Degats infliges : " << this->degatsMin + this->weapon->getDegatsMin() 
      << " - " << this->degatsMax + this->weapon->getDegatsMax()
      << "\n";
    }
  else
    {
      ss << " Arme  " << "aucune arme equipee" << "\n"
	 << "\n"
	 << " Degats infliges : " << this->degatsMin << " - " << this->degatsMax << " (Min-Max)" << "\n";
    }
  ss << " Points de vie : " << this->pv << " / " << this->pvMax << "\n"
     << " Stamina : " << this->stamina << " / " << this->staminaMax << "\n"
     << " Mana : " << this->mana << " / " << this->manaMax << "\n"
     << "\n"
     << " Force :" << this->force << "\n"
     << " Vitalite :" << this->vitalite << "\n"
     << " Agilite :" << this->agilite << "\n"
     << " Dexterite :" << this->dexterite << "\n"
     << " Intelligence :" << this->intelligence << "\n"
     << "\n"
     << " Defense : " << this->defense << "\n"
     << " Attaque : " << this->chance_toucher << "\n"
     << " Critique : " << this->chance_critique << "\n"
     << " Chance de trouver des Objets Magiques : " << this->trouvailles_magiques << "\n"
     << "\n";
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
      << "\n";
  if (this->weapon)
    {
      ss << " Arme  " << this->weapon->toString() << "\n"
	    << "\n"
      << " Degats infliges : " << this->degatsMin + this->weapon->getDegatsMin()
      << " - " << this->degatsMax + this->weapon->getDegatsMax()
      << "\n";
    }
  else
    {
  ss << " Arme  " << "aucune arme equipee" << "\n"
	   << "\n"
     << " Degats infliges : " << this->degatsMin << " - " << this->degatsMax << " (Min-Max)" << "\n";
    }
  ss << " Defense : " << this->defense << "\n"
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
