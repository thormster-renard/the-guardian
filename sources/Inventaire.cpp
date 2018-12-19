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
    this->initialize(capacite);
    std::size_t i;

    i = 0;
    while (i < this->nbrItems)
    {
        this->items[i] = new Item(*other.items[i]);
        i += 1;
    }
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
            this->items[i] = new Item(*other.items[i]);
            i += 1;
        }
    }
}

Item&   Inventaire::operator[](const unsigned index)
{
    if (index < 0 || index >= this->nbrItems)
    {
        throw("HORS LIMITE");
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
    this->items[this->nbrItems++] = new Item(item);
}

void        Inventaire::del(const unsigned index)
{
    
}

std::string Inventaire::toString() const
{
    std::stringstream ss;
    size_t  i;

    i = 0;
    while (i < this->nbrItems)
    {
        ss << "[" << i << "]" << this->items[i]->toString() << "\n";
        i += 1;
    }
    return (ss.str());
}