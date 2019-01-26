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
  this->armorType = armorType;
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
        case ARMOR_HEAD:
            type = "HEAUME";
            break;
        case ARMOR_CHEST:
            type = "PLASTRON";
            break;
        case ARMOR_SHOULDERS:
            type = "SPALIERE";
            break;
        case ARMOR_ARMS:
            type = "CANON DE BRAS";
            break;
        case ARMOR_HAND:
            type = "GANTELET";
            break;
        case ARMOR_LEGS:
            type = "JAMBIERE";
            break;
        case ARMOR_FEET:
            type = "SOLERET";
            break;
        default:
            type = "Erreur";
            break;
  }
  return (type);
}
