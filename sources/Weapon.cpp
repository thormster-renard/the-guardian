/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thormster <thormster.renard@outlook.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 22:17:49 by thormster         #+#    #+#             */
/*   Updated: 2018/12/20 22:17:49 by thormster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../headers/Weapon.hpp"

// Constructeur et Destructeur

Weapon::Weapon(int degatsMin, int degatsMax, std::string nom, unsigned type, unsigned rarete, unsigned valeur) : Item(nom, type, rarete, valeur)
{
  this->degatsMin = degatsMin;
  this->degatsMax = degatsMax;
}

Weapon::~Weapon() {}


// Fonctions

Weapon* Weapon::clone() const
{
  return (new Weapon(*this));
}

const std::string Weapon::toString() const
{
  std::stringstream ss;

  ss << "| Nom: " << this->getNom()
    << " | Type: " << this->getTypeAsString()
    << " | Degats: " << this->degatsMin << " - " << this->degatsMax
    << " | Rarete: " << this->getRareteAsString()
    << " | Valeur: " << this->getValeur();
  return (ss.str());
}