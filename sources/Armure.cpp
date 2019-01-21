/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Armure.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thormster <thormster.renard@outlook.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 21:41:02 by thormster         #+#    #+#             */
/*   Updated: 2019/01/21 21:41:02 by thormster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../headers/Armure.hpp"

// Constructeur et Destructeur

Armure::Armure(int defense, unsigned armorType, std::string nom, unsigned type, unsigned rarete, unsigned valeur) : Item(nom, type, rarete, valeur)
{
  this->defense = defense;
}

Armure::~Armure() {}


// Fonctions

Armure* Armure::clone() const
{
  return (new Armure(*this));
}

const std::string Armure::toString() const
{
  std::stringstream ss;

  ss << "| Nom: " << this->getNom()
    << " | Defense : " << this->getDefense()
    << " | Type: " << this->getTypeAsString()
    << " | Rarete: " << this->getRareteAsString()
    << " | Valeur: " << this->getValeur();
  return (ss.str());
}

const std::string Armure::getArmorTypeAsString() const
{
    std::string type = "Aucun";

    switch (this->armorType)
    {
        case HEAD:
            type = "HEAUME";
            break;
        case CHEST:
            type = "PLASTRON";
            break;
        case SHOULDERS:
            type = "SPALIERE";
            break;
        case ARMS:
            type = "CANON DE BRAS";
            break;
        case HAND:
            type = "GANTELET";
            break;
        case LEGS:
            type = "JAMBIERE";
            break;
        case FEET:
            type = "SOLERET";
            break;

        default:
            type = "Erreur";
            break;
  }
  return (type);
}