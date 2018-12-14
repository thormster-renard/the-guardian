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

#include    "Inventaire.hpp"

Inventaire::Inventaire(unsigned capacity)
{
    this->capacity = capacity;
    this->nbrItems = 0;
    this->items = new Item *[capacity];
    this->initialize(capacity);
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
    delete [] this->items;
}

void        Inventaire::initialize(const unsigned from)
{
    std::size_t  i;

    i = from;
    while (i < this->capacity)
    {
        this->items[i] = nullptr;
        i += 1;
    }
}

void        Inventaire::expand()
{
    
}