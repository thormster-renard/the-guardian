/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Item.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thormster <thormster.renard@outlook.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 20:10:49 by thormster         #+#    #+#             */
/*   Updated: 2018/12/12 20:10:49 by thormster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../headers/Item.hpp"

Item::Item(std::string nom,
	   unsigned type,
	   unsigned rarete,
	   unsigned valeur)
{
  this->nom = nom;
  this->type = type;
  this->rarete = rarete;
  this->valeur = valeur;
}

Item::~Item() {}

void        Item::generate() {}

// Accesseurs
const std::string& Item::getNom()
{
  return (this->nom);
}

const unsigned& Item::getType()
{
  return (this->type);
}

const unsigned& Item::getRarete()
{
  return (this->rarete);
}

const unsigned& Item::getValeur()
{
  return (this->valeur);
}

// Fonctions
const std::string Item::toString() const
{
  std::stringstream ss;

  ss << " Nom: " << this->nom
     << " | Type: " << this->type
     << " | Rarete: " << this->rarete
     << " | Valeur: " << this->valeur
     << "\n";
  return (ss.str());
}
