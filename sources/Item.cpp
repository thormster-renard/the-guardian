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


//Accesseurs

const std::string Item::getTypeAsString() const
{
  std::string type = "Aucun";

  switch (this->type)
  {
    case WEAPON:
      type = "Arme";
      break;
    case ARMOR:
      type = "Armure";
      break;
    default:
      type = "Erreur";
      break;
  }
  return (type);
}

const std::string  Item::getRareteAsString() const
{
  std::string rarete = "Aucun";

  switch (this->type)
  {
    case COMMON:
      rarete = "commun";
      break;
    case UNCOMMON:
      rarete = "non-commun";
      break;
    case RARE:
      rarete = "rare";
      break;
    case EPIC:
      rarete = "epique";
      break;
    case LEGENDARY:
      rarete = "legendaire";
      break;
    case MYTHIC:
      rarete = "mythique";
      break;
    default:
      rarete = "Erreur";
      break;
  }
  return (rarete);
}

const std::string& Item::getNom() const
{
  return (this->nom);
}

const unsigned& Item::getType() const
{
  return (this->type);
}

const unsigned& Item::getRarete() const
{
  return (this->rarete);
}

const unsigned& Item::getValeur() const
{
  return (this->valeur);
}