/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ennemi.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thormster <thormster.renard@outlook.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:03:41 by thormster         #+#    #+#             */
/*   Updated: 2018/12/06 12:03:41 by thormster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "Ennemi.hpp"

Ennemi::Ennemi(int niveau)
{
    this->niveau = niveau;
    this->pvMax = niveau * 10 + this->niveau;
    this->pv = this->pvMax;

    this->degatsMin = this->niveau * 2;
    this->degatsMax = this->niveau + this->niveau * 2;
    this->defense = this->niveau * 2;
    this->chance_toucher = this->niveau * 2 + this->niveau;
    this->chance_critique = static_cast<float>(this->niveau / 60);
}

Ennemi::~Ennemi()
{}

void    Ennemi::takeDegats(const int degats)
{
    this->pv -= degats;
    if (this->pv <= 0)
        this->setDead();
}

void    Ennemi::setDead()
{
    this->pv = 0;   
}

const std::string Ennemi::toStringStats()
{
    std::stringstream ss;

    ss  << " Niveau : " << this->niveau << "\n"
        << " Points de vie : " << this->pv << " / " << this->pvMax << "\n"
        << "\n"
        << " Degats infliges : " << this->degatsMin << " - " << this->degatsMax << " (Min-Max)" << "\n"
        << " Defense : " << this->defense << "\n"
        << " Attaque : " << this->chance_toucher << "\n"
        << " Critique : " << this->chance_critique << "\n"
        << "\n";
    return (ss.str());
}