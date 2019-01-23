/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inventaire.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thormster <thormster.renard@outlook.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 20:15:10 by thormster         #+#    #+#             */
/*   Updated: 2018/12/12 20:15:10 by thormster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../headers/Inventaire.hpp"

// Fonctions privées
void        Inventaire::initialize(const unsigned from)
{
  std::size_t  i;

  i = from;
  while (i < this->capacite)
    {
      this->items[i] = nullptr;
      i += 1;
    }
}

void        Inventaire::expand()
{
  this->capacite *= 2;
  Item **temp = new Item*[this->capacite];
  std::size_t  i;

  i = 0;
  while (i < this->nbrItems)
    {
      temp[i] = this->items[i];
      i += 1;
    }
  delete[] this->items;
  this->items = temp;
  this->initialize(this->nbrItems);
}

// Constructeurs & Destructeurs
Inventaire::Inventaire(unsigned capacite)
{
  this->capacite = capacite;
  this->nbrItems = 0;
  this->items = new Item *[capacite];
  this->initialize(capacite);
}

Inventaire::Inventaire(const Inventaire &other)
{
  this->capacite = other.capacite;
  this->nbrItems = other.nbrItems;
  this->items = new Item *[this->capacite];
  std::size_t i = 0;
  while (i < this->nbrItems)
    {
      this->items[i] = other.items[i]->clone();
      i += 1;
    }
  this->initialize(capacite);
}

Inventaire::~Inventaire()
{
  std::size_t  i;

  i = 0;
  while (i < this->nbrItems)
    {
      delete this->items[i];
      i += 1;
    }
  delete[] this->items;
}

// Operateurs
void        Inventaire::operator=(const Inventaire &other)
{
  std::size_t i;

  i = 0;
  if (this != &other)
    {
      while (i < this->nbrItems)
        {
	  delete this->items[i];
	  i += 1;
        }
      delete[] this->items;
      this->capacite = other.capacite;
      this->nbrItems = other.nbrItems;
      this->items = new Item *[this->capacite];
      this->initialize(capacite);
      std::size_t i;

      i = 0;
      while (i < this->nbrItems)
        {
	  this->items[i] = other.items[i]->clone();
	  i += 1;
        }
    }
}

Item&   Inventaire::operator[](const unsigned index)
{
  if (index < 0 || index >= this->nbrItems)
    {
      throw("Vous n'avez plus assez de places dans votre inventaire.");
    }
  return (*this->items[index]);
}


// Accesseurs
const unsigned& Inventaire::size() const
{
  return (this->nbrItems);
}

const unsigned& Inventaire::capaciteTot() const
{
  return (this->capacite);
}

Item&       Inventaire::at(const unsigned index)
{
  return (*this->items[0]);
}

// Fonctions
void        Inventaire::add(const Item &item)
{
  if (this->nbrItems >= this->capacite)
    this->expand();
  this->items[this->nbrItems++] = item.clone();
}

void        Inventaire::del(const unsigned index)
{

}

Item*       Inventaire::replace(const unsigned index, Item* item)
{
  if (index < 0 || index >= this->nbrItems)
    throw("INVENTAIRE::OUT OF BOUNDS!");
  Item* temp = this->items[index]->clone();
  delete this->items[index];
  this->items[index] = item->clone();
  return (temp);
}

std::string Inventaire::toString() const
{
  std::stringstream ss;
  size_t  i;

  i = 0;
  ss << gui::msgMenuTitre("Menu de l'Inventaire");
  ss << gui::msgMenuDiviseur(40, '-');
  while (i < this->nbrItems)
  {
    ss << gui::msgMenuItem(1, i, this->items[i]->toString());
    i += 1;
  }
  return (ss.str());
}